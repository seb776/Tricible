//
// Author: Sebastien Maire
// Contribs:
//

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "../Engine/Renderer.hpp"
#include "../TextureGenerator/PerlinNoise2D.hpp"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <ctime>
#include <string>
#include <iomanip>

#define		SIZE_WIDTH	800
#define		SIZE_HEIGHT	600

int main()
{
	sf::RenderWindow window(sf::VideoMode(SIZE_WIDTH, SIZE_HEIGHT), "My window");
	sf::Texture	texture;
	sf::Sprite sprite;
	char imageRGBA [SIZE_WIDTH * SIZE_HEIGHT * 4]; // must be an unsigned integer 8 bit

	if (!texture.create(SIZE_WIDTH, SIZE_HEIGHT))
	{
		std::cerr << "fail creating the texture" << std::endl;
		return 1;
	}

	std::cout.precision(3);
	for (int i = 0; i < 15; i++)
	{
		std::cout << "[  " << std::setw(5) << PerlinNoise2D::smooth_noise_1D_with_linear(i * 100);
		std::cout << "  ;  ";
		std::cout << std::setw(5) << PerlinNoise2D::smooth_noise_1D_with_linear(-i * 100);
		std::cout << "  ]" << std::endl;
	}


	//texture.update((sf::Uint8 *)image);
	//sprite.setTexture(texture);
	//window.draw(sprite);
	//window.display();

	std::cout << "Press any key to exit..." << std::endl;
	getchar();
	return 0;
}


