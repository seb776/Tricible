//
// Author: Sebastien Maire
// Contribs:
//

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#define IN_EXE
#include "../Engine/Rendering/Renderer.hpp"
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

void SetupScene(Tricible::Renderer *renderer)
{
	//renderer->Scene->Objects.push_back(new Scene::Sphere());
	//renderer->Scene->Objects.push_back(new Plane());
	renderer->Scene->Objects.push_back(new Triangle(Point3(25.f, 0.f, 0.f), Point3(25.f, 0.f, 5.f), Point3(25.f, 2.5f, 2.5f)));
	renderer->Scene->Lights.push_back(new ALight(0xFF424242, Point3(20.f, 20.f, 20.f), 1.f));
	//renderer->Scene->Lights.push_back(new ALight(0xFFFF00FF, Point3(50.f, -10.f, 75.f), 1.f));
	renderer->Scene->Skymap = new Texture("Resources/Image.jpg");
	//renderer->Scene->LoadFromObj("Resources/test.obj");
}

// courte_p : J'ai découpé la partie du "main" qui s'occupe de gérer la translation de la caméra via les événements de la SFML
void translateCamera(Tricible::Renderer *renderer, const Tricible::Point3 & vecOrigin)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		renderer->Scene->CurrentCamera->MoveForward();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		renderer->Scene->CurrentCamera->MoveBackward();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{

		renderer->Scene->CurrentCamera->MoveLeft();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		renderer->Scene->CurrentCamera->MoveRight();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add))
	{
		renderer->Scene->CurrentCamera->SetYaw(renderer->Scene->CurrentCamera->yaw + 0.01f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract))
	{
		renderer->Scene->CurrentCamera->SetYaw(renderer->Scene->CurrentCamera->yaw - 0.01f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		renderer->Scene->CurrentCamera->AddPosition(Tricible::Point3::up);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
	{
		renderer->Scene->CurrentCamera->AddPosition(Tricible::Point3::down);
	}
}

int main()
{
	int width = 480;
	int height = 360;
	sf::RenderWindow window(sf::VideoMode(width, height), "My window");
	sf::Texture	texture;
	sf::Sprite sprite;
	auto scene = Scene::Scene::LoadFromObj("Resources/test.obj");
	Tricible::Renderer renderer(width, height, 0, scene);
	sf::String fpsCount;
	SetupScene(&renderer);
	std::clock_t start;
	std::clock_t end;
	double duration = 0.0;


	if (!texture.create(width, height))
	{
		std::cerr << "fail creating the texture" << std::endl;
		return 1;
	}
	window.setKeyRepeatEnabled(true);

	Tricible::Point3 vecOrigin(1.f, 0.f, .0f);
	Tricible::Point3 curDir;
	int iFrameCount = 0;
	bool isMouseLocked = false;
	sf::Vector2i lastMousePos = sf::Vector2i(0, 0);
	while (window.isOpen())
	{
		start = std::clock();
		sf::Event event;
		translateCamera(&renderer, vecOrigin);
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

				const float mouseSensitivity = -0.0005f;
				mouseDelta *= mouseSensitivity;
				renderer.Scene->CurrentCamera->SetPitch(renderer.Scene->CurrentCamera->pitch - (mouseDelta.x));
				renderer.Scene->CurrentCamera->SetYaw(renderer.Scene->CurrentCamera->yaw - (mouseDelta.y));

				uint32_t maxMousePosRadius = min(window.getSize().x, window.getSize().y) / 3;
				sf::Vector2f windowCenter = (sf::Vector2f)window.getSize() / 2.0f;
				Point3 curMousePos = Point3(currentMousePos.x, currentMousePos.y, 0.0f);
				Point3 winCenter = Point3(windowCenter.x, windowCenter.y, 0.0f);
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
		++iFrameCount;
		renderer.Render();
		texture.update((sf::Uint8 *)renderer.image);
		sprite.setTexture(texture);
		window.draw(sprite);
		window.display();
		end = std::clock();
		duration += (end - start) / (double)CLOCKS_PER_SEC;
		if (duration > 0.5)
		{
			window.setTitle(std::to_string(((double)iFrameCount / duration)));
			iFrameCount = 0;
			duration = 0.0;
		}
	}
	return 0;
}


