//
// Author: Sebastien Maire
// Contribs:
//

#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <iostream>
#include <string>

#include "../Engine/Renderer.hpp"
#include "../TextureGenerator/PerlinNoise.hpp"
#include "../TextureGenerator/GradientCollection.hpp"

#define		SIZE_WIDTH	1280
#define		SIZE_HEIGHT	768

void Example_PerlinNoise_1D()
{
	// compute perlin noise
	float * result = new float[SIZE_WIDTH];

	PerlinNoise::PerlinNoise1D(result, SIZE_WIDTH, 6);

	// render perlin noise
	sf::Color pixel = sf::Color(0, 0, 0);
	sf::Image image;
	int y_coord;

	image.create(SIZE_WIDTH, SIZE_HEIGHT, sf::Color::White);
	for (int x = 0; x < SIZE_WIDTH; x++)
	{
		y_coord = result[x] * SIZE_HEIGHT;
		image.setPixel(x, result[x] * SIZE_HEIGHT, pixel);
	}
	delete[] result;

	image.saveToFile("Example_PerlinNoise_1D.png");
}

void Example_PerlinNoise_1D_Stacked()
{
	// compute perlin noise
	float * result = new float[SIZE_WIDTH];

	PerlinNoise::PerlinNoise1DStacked(result, SIZE_WIDTH, 16, 4, 0.3f);

	// render perlin noise
	sf::Color pixel = sf::Color(0, 0, 0);
	sf::Image image;
	int y_coord;
	
	image.create(SIZE_WIDTH, SIZE_HEIGHT, sf::Color::White);
	for (int x = 0; x < SIZE_WIDTH; x++)
	{
		y_coord = result[x] * SIZE_HEIGHT;
		image.setPixel(x, result[x] * SIZE_HEIGHT, pixel);
 	}
	delete[] result;

	image.saveToFile("Example_PerlinNoise_1D_Stacked.png");
}

void Example_PerlinNoise_2D()
{
	// compute perlin noise
	float * result = new float[SIZE_HEIGHT * SIZE_WIDTH];
	PerlinNoise::PerlinNoise2D(result, SIZE_WIDTH, SIZE_HEIGHT, 20, 12);

	// render perlin noise
	sf::Color pixel;
	sf::Image image;
	int result_color;

	image.create(SIZE_WIDTH, SIZE_HEIGHT, sf::Color::White);
	for (int y = 0; y < SIZE_HEIGHT; ++y)
	{
		for (int x = 0; x < SIZE_WIDTH; x++)
		{
			result_color = result[y * SIZE_WIDTH + x] * 255.0f;
			pixel = sf::Color(result_color, result_color, result_color);
			image.setPixel(x, y, pixel);
		}
	}
	delete[] result;

	image.saveToFile("Example_PerlinNoise_2D.png");
}

void Example_PerlinNoise_2D_Stacked()
{
	// compute perlin noise
	float * result = new float[SIZE_HEIGHT * SIZE_WIDTH];
	PerlinNoise::PerlinNoise2DStacked(result, SIZE_WIDTH, SIZE_HEIGHT, 16, 9, 5, 0.25f);

	// render perlin noise
	sf::Color pixel;
	sf::Image image;
	int result_color;

	image.create(SIZE_WIDTH, SIZE_HEIGHT, sf::Color::White);
	for (int y = 0; y < SIZE_HEIGHT; ++y)
	{
		for (int x = 0; x < SIZE_WIDTH; x++)
		{
			result_color = result[y * SIZE_WIDTH + x] * 255.0f;
			pixel = sf::Color(result_color, result_color, result_color);
			image.setPixel(x, y, pixel);
		}
	}
	delete[] result;

	image.saveToFile("Example_PerlinNoise_2D_Stacked.png");
}

void Example_PerlinNoise_2D_Stacked_WithGradient()
{
	// compute perlin noise
	float * result = new float[SIZE_HEIGHT * SIZE_WIDTH];
	PerlinNoise::PerlinNoise2DStacked(result, SIZE_WIDTH, SIZE_HEIGHT, 30, 15, 8, 0.30f);

	// gradient mapping
	GradientCollection grad;

	grad.AddGradientPoint(GradientPoint(0.10f, ColorRGBA(0, 0, 255)));
	grad.AddGradientPoint(GradientPoint(0.33f, ColorRGBA(0, 255, 0)));
	grad.AddGradientPoint(GradientPoint(0.66f, ColorRGBA(255, 0, 0)));
	grad.AddGradientPoint(GradientPoint(0.90f, ColorRGBA(255, 255, 255)));

	// render perlin noise
	sf::Color pixel;
	sf::Image image;
	ColorRGBA resultGrad;
	uint8_t r;
	uint8_t g;
	uint8_t b;

	image.create(SIZE_WIDTH, SIZE_HEIGHT, sf::Color::White);
	for (int y = 0; y < SIZE_HEIGHT; ++y)
	{
		for (int x = 0; x < SIZE_WIDTH; x++)
		{
			grad.GetColorRGBA(result[y * SIZE_WIDTH + x], &resultGrad);
			pixel = sf::Color(resultGrad.GetRed(), resultGrad.GetGreen(), resultGrad.GetBlue());
			image.setPixel(x, y, pixel);
		}
	}
	delete[] result;

	image.saveToFile("Example_PerlinNoise_2D_Stacked_WithGradient.png");
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(SIZE_WIDTH, SIZE_HEIGHT), "My window");

//	Example_PerlinNoise_1D();
//	Example_PerlinNoise_1D_Stacked();
//	Example_PerlinNoise_2D();
	Example_PerlinNoise_2D_Stacked();
	Example_PerlinNoise_2D_Stacked_WithGradient();

	sf::Texture	texture;
	// "Example_PerlinNoise_1D"
	// "Example_PerlinNoise_1D_Stacked"
	// "Example_PerlinNoise_2D"
	texture.loadFromFile("Example_PerlinNoise_2D_Stacked_WithGradient.png");
	sf::Sprite sprite;
	sprite.setTexture(texture);
	window.draw(sprite);
	window.display();

	std::cout << "Press any key to exit..." << std::endl;
	getchar();
	return 0;
}


