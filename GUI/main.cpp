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
				curDir = (renderer._camera.yawMat * (renderer._camera.pitchMat * vecOrigin)) * 1.f;
				std::cout << renderer._camera.position._x << "/" << renderer._camera.position._y << "/" << renderer._camera.position._z << std::endl;
				if (event.key.code == sf::Keyboard::Up)
				{
					renderer._camera.position += curDir;
				}
				if (event.key.code == sf::Keyboard::Down)
				{
					renderer._camera.position = renderer._camera.position - curDir;
				}
				if (event.key.code == sf::Keyboard::Left)
				{
					renderer._camera.SetYaw(renderer._camera.yaw - 0.01f);
				}
				if (event.key.code == sf::Keyboard::Right)
				{
					renderer._camera.SetYaw(renderer._camera.yaw + 0.01f);
				}
				if (event.key.code == sf::Keyboard::Add)
				{
					renderer._camera.SetPitch(renderer._camera.pitch - 0.01f);
				}
				if (event.key.code == sf::Keyboard::Subtract)
				{
					renderer._camera.SetPitch(renderer._camera.pitch + 0.01f);
				}
				if (event.key.code == sf::Keyboard::Space)
				{
					renderer._camera.position._z += 1.f;
				}
				if (event.key.code == sf::Keyboard::LControl)
				{
					renderer._camera.position._z -= 1.f;
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