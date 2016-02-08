//
// Author: Sebastien Maire
// Contribs:
//

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "../Engine/Renderer.hpp"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <ctime>
#include <string>

// courte_p : J'ai découpé la partie du "main" qui s'occupe de gérer la translation de la caméra via les événements de la SFML
void translateCamera(Tricible::Renderer *renderer, const Tricible::Point3 & vecOrigin, const sf::Keyboard::Key key)
{
	if (key == sf::Keyboard::Up)
	{
		renderer->_camera.MoveForward();
		// TODO courte : anciennement code ->
		// renderer->_camera.position += (renderer->_camera.yawMat * (renderer->_camera.pitchMat * vecOrigin)) * 1.f;
	}
	if (key == sf::Keyboard::Down)
	{
		renderer->_camera.MoveBackward();
		// TODO courte : anciennement code ->
		// renderer->_camera.position -= (renderer->_camera.yawMat * (renderer->_camera.pitchMat * vecOrigin)) * 1.f;
	}
	if (key == sf::Keyboard::Left)
	{
		renderer->_camera.SetYaw(renderer->_camera.yaw - 0.01f);
	}
	if (key == sf::Keyboard::Right)
	{
		renderer->_camera.SetYaw(renderer->_camera.yaw + 0.01f);
	}
	if (key == sf::Keyboard::Add)
	{
		renderer->_camera.SetPitch(renderer->_camera.pitch - 0.01f);
	}
	if (key == sf::Keyboard::Subtract)
	{
		renderer->_camera.SetPitch(renderer->_camera.pitch + 0.01f);
	}
	if (key == sf::Keyboard::Space)
	{
		renderer->_camera.position._z += 1.f;
	}
	if (key == sf::Keyboard::LControl)
	{
		renderer->_camera.position._z -= 1.f;
	}
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
	sf::Texture	texture;
	sf::Sprite sprite;
	Tricible::Renderer renderer(800, 600, 0);
	sf::String fpsCount;

	std::clock_t start;
	std::clock_t end;
	double duration = 0.0;


	/* Your algorithm here */

	if (!texture.create(800, 600))
	{
		std::cerr << "fail creating the texture" << std::endl;
		return 1;
	}
	window.setKeyRepeatEnabled(true);

	Tricible::Point3 vecOrigin(1.f, 0.f, .0f);
	Tricible::Point3 curDir;
	int iFrameCount = 0;
	while (window.isOpen())
	{
		start = std::clock();
		sf::Event event;
		if (window.pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::KeyPressed:
				{
					std::cout << renderer._camera.position._x << "/" << renderer._camera.position._y << "/" << renderer._camera.position._z << std::endl;
					// TODO courte_p : question sur le ligne de code curDir... 
					// c'est l'équivalent de vec3 forwardVector = lookAtPosition - cameraPosition ???
					// curDir = (renderer._camera.yawMat * (renderer._camera.pitchMat * vecOrigin)) * 1.f;
					// NOTE : curDir a été bougée dans la fonction "void translateCamera(...)" -> fichier main.cpp
					translateCamera(&renderer, vecOrigin, event.key.code);
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


