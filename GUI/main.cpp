//
// Author: Sebastien Maire
// Contribs:
//

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#define IN_EXE
#include "../Engine/Rendering/GLSLRenderer.hpp"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <ctime>
#include <string>

#include "../Engine/Scene/Scene.hpp"
#include "../Engine/Scene/Plane.hpp"
#include "../Engine/Scene/Sphere.hpp"
#include "../Engine/Scene/Triangle.hpp"
#include "../Engine/Scene/Camera.hpp"


using namespace Tricible;

// TODO Move this
void SetupScene(Tricible::Renderer* renderer)
{
	auto& curDir = GetCurrentExecutableDirectory();

	renderer->Scene = Scene::Scene::LoadFromObj(PathCombine(curDir, "./Resources/test.obj"));
	//renderer->Scene->Objects.push_back(new Scene::Sphere());
	//renderer->Scene->Objects.push_back(new Plane());
	//renderer->Scene->Objects.push_back(new Triangle(Point3(25.f, 0.f, 0.f), Point3(25.f, 0.f, 5.f), Point3(25.f, 2.5f, 2.5f)));
	renderer->Scene->Lights.push_back(new ALight((vec3(0x42, 0x42, 0x42)/255.0f)*2.0f, vec3(20.f, 20.f, 20.f), 1.f));
	//renderer->Scene->Lights.push_back(new ALight(0xFFFF00FF, Point3(50.f, -10.f, 75.f), 1.f));
	renderer->Scene->Skymap = new Texture("Resources/Outside.jpg");
	renderer->UpdateInternalScene();
}

// TODO move this
void translateCamera(Camera& camera)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		camera.MoveForward();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		camera.MoveBackward();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		camera.MoveLeft();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		camera.MoveRight();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add))
	{
		camera.SetYaw(camera.yaw + 0.01f);  // TODO Make constant
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract))
	{
		camera.SetYaw(camera.yaw - 0.01f);  // TODO Make constant
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		camera.AddPosition(vec3(0.,1.,0.) * 0.01f); // TODO Speed as constant too
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
	{
		camera.AddPosition(vec3(0., -1., 0.) * 0.01f); // TODO Speed as constant too
	}
}
struct EngineConfig
{
	float MouseSensitivity;
};
EngineConfig Config;
void loadConfig()
{
	Config.MouseSensitivity = -0.0005f;
}
int main()
{
	loadConfig();
	int width = 1280;
	int height = 720;
	sf::RenderWindow window(sf::VideoMode(width, height), "Tricible");
	sf::Texture	texture;
	sf::Sprite sprite;
	Tricible::Renderer *renderer = new Tricible::GLSLRenderer(width, height);
	glEnable(GL_TEXTURE_2D);

	SetupScene(renderer);

	sf::String fpsCount;
	std::clock_t start;
	std::clock_t end;
	double duration = 0.0;
	double totalDuration = 0.0;

	if (!texture.create(width, height))
	{
		std::cerr << "fail creating the texture" << std::endl;
		return 1;
	}
	window.setKeyRepeatEnabled(true);

	int iFrameCount = 0;
	bool isMouseLocked = false;
	sf::Vector2i lastMousePos = sf::Vector2i(0, 0);
	Camera camera = Camera();
	
	while (window.isOpen())
	{
		sf::Event event;
		start = std::clock();
		translateCamera(camera);
		if (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyPressed:
			{
				break;
			}
			case sf::Event::KeyReleased:
			{
				if (event.key.code == sf::Keyboard::L)
				{
					isMouseLocked = !isMouseLocked;
				}
				break;
			}
			case sf::Event::MouseMoved:
			{
				if (isMouseLocked)
				{
					sf::Vector2i currentMousePos = sf::Vector2i(event.mouseMove.x, event.mouseMove.y);
					sf::Vector2f mouseDelta = (sf::Vector2f)lastMousePos - (sf::Vector2f)currentMousePos;

					mouseDelta *= Config.MouseSensitivity;
					camera.SetPitch(camera.pitch + mouseDelta.y);
					camera.SetYaw(camera.yaw + mouseDelta.x);

					uint32_t maxMousePosRadius = min(window.getSize().x, window.getSize().y) / 3;
					sf::Vector2f windowCenter = (sf::Vector2f)window.getSize() / 2.0f;
					Vector3 curMousePos = Vector3(currentMousePos.x, currentMousePos.y, 0.0f);
					Vector3 winCenter = Vector3(windowCenter.x, windowCenter.y, 0.0f);
					if ((curMousePos - winCenter).Length() > maxMousePosRadius) {
						sf::Mouse::setPosition(sf::Vector2i((int)windowCenter.x, (int)windowCenter.y), window);
						lastMousePos = (sf::Vector2i)windowCenter;
					}
					else {
						lastMousePos = currentMousePos;
					}
				}
				break;
			}
			}
			if (event.type == sf::Event::Closed)
				window.close();
		}
		renderer->SetUniformFloat("cameraPitch", camera.pitch);
		renderer->SetUniformFloat("cameraYaw", camera.yaw);
		renderer->SetUniformFloat("time", totalDuration);
		renderer->SetUniformVector("cameraPosition", camera.getPosition());
		++iFrameCount;
		window.setActive(false);
		renderer->Render();
		window.setActive(true);
		texture.update((sf::Uint8*)renderer->image);
		sprite.setTexture(texture);
		window.draw(sprite);
		window.display();
		end = std::clock();
		duration += (end - start) / (double)CLOCKS_PER_SEC;
		totalDuration += (end - start) / (double)CLOCKS_PER_SEC;
		//std::cout << camera.getPosition().ToString() << std::endl;
		if (duration > 0.5)
		{
			window.setTitle(std::to_string(((double)iFrameCount / duration)));
			iFrameCount = 0;
			duration = 0.0;
		}
	}
	return 0;
}


