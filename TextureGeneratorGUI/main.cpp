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
#include <string>

#define		SIZE_WIDTH	900
#define		SIZE_HEIGHT	600

void Trace_1D()
{
	sf::Color pixel = sf::Color(0, 0, 0);
	sf::Image image;
	int y_coord;
	float result[SIZE_WIDTH];
	
	image.create(SIZE_WIDTH, SIZE_HEIGHT, sf::Color::White);
//	PerlinNoise2D::PerlinNoise1D(result, SIZE_WIDTH, 6);
	PerlinNoise2D::PerlinNoise1DStacked(result, SIZE_WIDTH, 16, 4, 0.3f, 2.0f);
	for (int x = 0; x < SIZE_WIDTH; x++)
	{
		y_coord = result[x] * SIZE_HEIGHT;
		image.setPixel(x, result[x] * SIZE_HEIGHT, pixel);
 	}
	image.saveToFile("resultPCO.png");
}

void Trace_2D()
{
	sf::Color pixel;
	sf::Image image;
	int result_color;
	float * result = (float *) std::malloc(SIZE_HEIGHT * SIZE_WIDTH * sizeof(float));

	image.create(SIZE_WIDTH, SIZE_HEIGHT, sf::Color::White);
	PerlinNoise2D::PerlinNoise2D(result, SIZE_WIDTH, SIZE_HEIGHT, 20);
	for (int y = 0; y < SIZE_HEIGHT; ++y)
	{
		for (int x = 0; x < SIZE_WIDTH; x++)
		{
			result_color = result[y * SIZE_WIDTH + x] * 256;
			pixel = sf::Color(result_color, result_color, result_color);
			image.setPixel(x, y, pixel);
		}
	}
	image.saveToFile("resultPCO.png");
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(SIZE_WIDTH, SIZE_HEIGHT), "My window");

//	Trace_1D();
	Trace_2D();

	sf::Texture	texture;
	texture.loadFromFile("resultPCO.png");
	sf::Sprite sprite;
	sprite.setTexture(texture);
	window.draw(sprite);
	window.display();

	std::cout << "Press any key to exit..." << std::endl;
	getchar();
	return 0;
}


