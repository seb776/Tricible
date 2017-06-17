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
	sf::Sprite 		sprite;
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

	char *image = nullptr;
	texture.update((sf::Uint8 *)image);
	sprite.setTexture(texture);
	window.draw(sprite);
	window.display();
	return 0;
}


