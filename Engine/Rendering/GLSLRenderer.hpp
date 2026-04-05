#pragma once

#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include "Renderer.hpp"

namespace Tricible
{
	class GLSLRenderer : public Renderer
	{
	private:
		GLFWwindow* _window;
		GLuint _objectsSSBO;
		GLuint _trianglesSSBO;
		GLuint _vao;

		struct GLSLRenderTarget
		{
			GLuint fbo;
			GLuint texture;
			int width;
			int height;
		};

		const std::string FULLSCREEN_VERTEX_SHADER = R"(#version 430 core
        const vec2 verts[3] = vec2[](
            vec2(-1,-1),
            vec2( 3,-1),
            vec2(-1, 3)
        );
        void main() { gl_Position = vec4(verts[gl_VertexID], 0.0, 1.0); }
    )";
		const std::string FRAGMENT_HEADER = R"(#version 430 core
#define OPENGL_SHADER_CODE
			)";

		GLuint _shaderProgram;
		GLSLRenderTarget _renderTarget;

		GLFWwindow* _initGL();
		GLuint _compileShader(const std::string& source, GLenum type);
		GLuint _createShaderProgram(const std::string& vertexSrc, const std::string& fragmentSrc);
		GLSLRenderTarget _createRenderTarget(int width, int height);
		void _copyFrameBufferToCPUArray();

	public:
		GLSLRenderer(int resX, int resY);


		void SetUniformFloat(std::string uniformName, float value) override;
		void SetUniformVector(std::string uniformName, const vec2& value) override;
		void SetUniformVector(std::string uniformName, const vec3& value) override;
		void SetUniformVector(std::string uniformName, const vec4& value) override;

		void UpdateInternalScene() override;
		void Resize(int resX, int resY) override;
		void Render() override;
		~GLSLRenderer();
	};
}