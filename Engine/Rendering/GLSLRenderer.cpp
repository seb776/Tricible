#include <iostream>
#include <fstream>
#include "GLSLRenderer.hpp"
#include "../GLSLRendererCPP/Swizzle.glsl.hpp"
#include "../GLSLRendererCPP/vec4.hpp"

using namespace Tricible;

GLSLRenderer::GLSLRenderer(int resX, int resY) :
	Renderer(resX, resY)
{
	this->_window = this->_initGL();
	const auto& exePath = GetCurrentExecutableDirectory();
	const auto& kernalFilePath = PathCombine(exePath, "./Rendering/TestRender.glsl.cpp");
	const auto& kernelSource = ReadFile(kernalFilePath);
	const std::string fragmentProgram = kernelSource;
	_shaderProgram = _createShaderProgram(FULLSCREEN_VERTEX_SHADER, fragmentProgram);
	_renderTarget = _createRenderTarget(resX, resY);


}

void GLSLRenderer::Resize(int resX, int resY)
{
	Renderer::Resize(resX, resY); // Handle CPU buffer
	// TODO
}

void GLSLRenderer::Render()
{
	glfwMakeContextCurrent(_window);

	this->SetUniformVector("resolution", vec2(this->_resX, this->_resY));

	glBindFramebuffer(GL_FRAMEBUFFER, _renderTarget.fbo);
	glViewport(0, 0, this->_resX, this->_resY);
	glClearColor(0.f, 0.f, 0.f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT);

	glBindVertexArray(_vao);
	glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, _objectsSSBO);
	glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 1, _trianglesSSBO);
	glUseProgram(_shaderProgram);

	
	glDrawArrays(GL_TRIANGLES, 0, 3);

	auto err = glGetError();
	if (err != GL_NO_ERROR)
		printf("GL error after draw: %d\n", err);
	_copyFrameBufferToCPUArray();
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

GLSLRenderer::~GLSLRenderer()
{
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glDeleteProgram(_shaderProgram);
	glDeleteFramebuffers(1, &_renderTarget.fbo);
	glDeleteTextures(1, &_renderTarget.texture);
}

GLFWwindow* GLSLRenderer::_initGL()
{
	if (!glfwInit())
		return nullptr;

	glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE); // hidden window
	GLFWwindow* window = glfwCreateWindow(1, 1, "", nullptr, nullptr);
	glfwMakeContextCurrent(window);

	if (!gladLoadGL(glfwGetProcAddress))
	{
		std::cerr << "Failed to initialize GLAD\n";
		return nullptr;
	}

	glGenVertexArrays(1, &this->_vao);
	glBindVertexArray(_vao);

	return window;
}

GLuint GLSLRenderer::_compileShader(const std::string& source, GLenum type)
{
	GLuint shader = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(shader, 1, &src, nullptr);
	glCompileShader(shader);

	GLint success;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		char infoLog[512];
		glGetShaderInfoLog(shader, 512, nullptr, infoLog);
		std::cerr << "ERROR: Shader compilation failed\n" << infoLog << std::endl;
		return 0;
	}
	return shader;
}

GLuint GLSLRenderer::_createShaderProgram(const std::string& vertexSrc, const std::string& fragmentSrc)
{
	GLuint vertexShader = _compileShader(vertexSrc, GL_VERTEX_SHADER);

	auto fragmentFixes = FRAGMENT_HEADER + fragmentSrc;
	const auto& currentExePath = GetCurrentExecutableDirectory();
	std::ofstream myfile;
	std::string fragmentFileName = "./Rendering/fragment.includes.glsl";
	std::string fragmentFilePath = PathCombine(currentExePath,  fragmentFileName);
	myfile.open(fragmentFilePath, std::ios::out | std::ios::trunc);
	myfile << fragmentFixes;
	myfile.close();
	// Write to file
	// TODO check if fails
	std::cout << "Running GLSL Includes: " << fragmentFileName << std::endl;

	system((std::string("cd " + currentExePath + " & cd GLSLIncludes_V1.1 & cd & GLSLIncludes.exe ") + PathCombine("../", fragmentFileName)).c_str());
	std::ifstream fragmentWithIncludesFlat(currentExePath + "./Rendering/fragment.includes.glsl.generated");
	std::stringstream strStream;
	strStream << fragmentWithIncludesFlat.rdbuf();
	GLuint fragmentShader = _compileShader(strStream.str(), GL_FRAGMENT_SHADER);

	GLuint program = glCreateProgram();
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);
	glLinkProgram(program);

	GLint success;
	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success)
	{
		char infoLog[512];
		glGetProgramInfoLog(program, 512, nullptr, infoLog);
		std::cerr << "ERROR: Shader linking failed\n" << infoLog << std::endl;
		return 0;
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	return program;
}



GLSLRenderer::GLSLRenderTarget GLSLRenderer::_createRenderTarget(int width, int height)
{
	GLSLRenderTarget rt;
	rt.width = width;
	rt.height = height;

	glGenFramebuffers(1, &rt.fbo);
	glBindFramebuffer(GL_FRAMEBUFFER, rt.fbo);

	glGenTextures(1, &rt.texture);
	glBindTexture(GL_TEXTURE_2D, rt.texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, rt.texture, 0);

	GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
	if (status != GL_FRAMEBUFFER_COMPLETE)
		std::cerr << "ERROR: Framebuffer not complete!" << std::endl;

	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	return rt;
}

void GLSLRenderer::UpdateInternalScene()
{
	Renderer::UpdateInternalScene();
	glfwMakeContextCurrent(_window);
	glGenBuffers(1, &_objectsSSBO);
	glBindBuffer(GL_SHADER_STORAGE_BUFFER, _objectsSSBO);
	glBufferData(GL_SHADER_STORAGE_BUFFER, _objectsCount * sizeof(ObjectData), _objects, GL_DYNAMIC_DRAW);
	glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, _objectsSSBO);  // binding = 0

	glGenBuffers(1, &_trianglesSSBO);
	glBindBuffer(GL_SHADER_STORAGE_BUFFER, _trianglesSSBO);
	glBufferData(GL_SHADER_STORAGE_BUFFER, _trianglesCount * sizeof(TriangleData), _triangles, GL_DYNAMIC_DRAW);
	glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 1, _trianglesSSBO);  // binding = 1


	GLint size = 0;
	glBindBuffer(GL_SHADER_STORAGE_BUFFER, _trianglesSSBO);
	glGetBufferParameteriv(GL_SHADER_STORAGE_BUFFER, GL_BUFFER_SIZE, &size);
	printf("triangles buffer size: %d\n", size);
}


void GLSLRenderer::_copyFrameBufferToCPUArray()
{
	glfwMakeContextCurrent(_window);
	glBindFramebuffer(GL_FRAMEBUFFER, _renderTarget.fbo);
	glReadBuffer(GL_COLOR_ATTACHMENT0);
	glReadPixels(0, 0, this->_resX, this->_resY, GL_RGBA, GL_UNSIGNED_BYTE, this->image);
}

void GLSLRenderer::SetUniformFloat(std::string uniformName, float value)
{
	glfwMakeContextCurrent(_window);
	auto uniformLocation = glGetUniformLocation(_shaderProgram, uniformName.c_str());
	glProgramUniform1f(_shaderProgram, uniformLocation, value);
}
void GLSLRenderer::SetUniformVector(std::string uniformName, const vec2& value)
{
	glfwMakeContextCurrent(_window);
	auto uniformLocation = glGetUniformLocation(_shaderProgram, uniformName.c_str());
	glProgramUniform2f(_shaderProgram, uniformLocation, value.X_, value.Y_);
}
void GLSLRenderer::SetUniformVector(std::string uniformName, const vec3& value)
{
	glfwMakeContextCurrent(_window);
	auto uniformLocation = glGetUniformLocation(_shaderProgram, uniformName.c_str());
	glProgramUniform3f(_shaderProgram, uniformLocation, value.X_, value.Y_, value.Z_);
}
void GLSLRenderer::SetUniformVector(std::string uniformName, const vec4& value)
{
	glfwMakeContextCurrent(_window);
	auto uniformLocation = glGetUniformLocation(_shaderProgram, uniformName.c_str());
	glProgramUniform4f(_shaderProgram, uniformLocation, value.X_, value.Y_, value.Z_, value.W_);
}