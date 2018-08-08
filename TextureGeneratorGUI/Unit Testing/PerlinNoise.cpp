//
// Author: Pierre COURTEILLE
//

//----------------------------------------//
// include SFML
//----------------------------------------//
#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Sprite.hpp>

//----------------------------------------//
// include STL
//----------------------------------------//
#include <iostream>
#include <string>

#include "../../Engine/Rendering/Renderer.hpp"

//----------------------------------------//
// include Tricible
//----------------------------------------//
#include "../../TextureGenerator/PerlinNoise.hpp"
#include "../../TextureGenerator/GradientsLinear.hpp"

namespace UnitTesting
{
	#define		SIZE_IMG_WIDTH	800		// taille de l'image PNG
	#define		SIZE_IMG_HEIGHT	500		// taille de l'image PNG

	// Va g�n�rer une image PNG dans le dossier courant
	// Courbe � une dimension - de gauche � droite
	// L'axe X est constant (horizontal)
	// L'axe Y varie (vertical)
	void PerlinNoise_1D()
	{
		float * result = new float[SIZE_IMG_WIDTH];		// buffer de l'image
		sf::Image image;								// SFML pour enregistrer le fichier PNG
		int temp_y_coord;								// pour stocker la valeur Y de la courbe

		// compute perlin noise
		Tricible::PerlinNoise::PerlinNoise1D(6, SIZE_IMG_WIDTH, &result);

		// mise en place d'un fond blanc
		image.create(SIZE_IMG_WIDTH, SIZE_IMG_HEIGHT, sf::Color::White);

		// affichage de la courbe
		for (int x = 0; x < SIZE_IMG_WIDTH; x++)
		{
			temp_y_coord = result[x] * SIZE_IMG_HEIGHT;
			image.setPixel(x, result[x] * SIZE_IMG_HEIGHT, sf::Color(0, 0, 0)); // courbe noir
		}
		image.saveToFile("Example_PerlinNoise_1D.png");

		// nettoyage
		delete[] result;
	}

	// Va g�n�rer une image PNG dans le dossier courant
	// Courbe � une dimension - de gauche � droite
	// L'axe X est constant (horizontal)
	// L'axe Y varie (vertical)
	void PerlinNoise_1D_Stacked()
	{
		float * result = new float[SIZE_IMG_WIDTH];		// buffer de l'image
		sf::Image image;                                // SFML pour enregistrer le fichier PNG
		int temp_y_coord;								// pour stocker la valeur Y de la courbe

		// compute perlin noise
		Tricible::PerlinNoise::PerlinNoise1DStacked(16, 4, 0.3f, SIZE_IMG_WIDTH, &result);

		// mise en place d'un fond blanc
		image.create(SIZE_IMG_WIDTH, SIZE_IMG_HEIGHT, sf::Color::White);

		// affichage de la courbe
		for (int x = 0; x < SIZE_IMG_WIDTH; x++)
		{
			temp_y_coord = result[x] * SIZE_IMG_HEIGHT;
			image.setPixel(x, result[x] * SIZE_IMG_HEIGHT, sf::Color(0, 0, 0)); // courbe noir
		}
		image.saveToFile("Example_PerlinNoise_1D_Stacked.png");

		// nettoyage
		delete[] result;
	}

	// Va g�n�rer une image PNG dans le dossier courant
	// Nuage de gris
	void PerlinNoise_2D()
	{
		float * result = new float[SIZE_IMG_HEIGHT * SIZE_IMG_WIDTH]; // buffer de l'image
		sf::Color pixel;
		sf::Image image;
		int result_color;

		// compute perlin noise
		Tricible::PerlinNoise::PerlinNoise2D(20, 12, SIZE_IMG_WIDTH, SIZE_IMG_HEIGHT, &result);

		// mise en place d'un fond blanc
		image.create(SIZE_IMG_WIDTH, SIZE_IMG_HEIGHT, sf::Color::White);

		// render perlin noise
		for (int y = 0; y < SIZE_IMG_HEIGHT; ++y)
		{
			for (int x = 0; x < SIZE_IMG_WIDTH; x++)
			{
				result_color = result[y * SIZE_IMG_WIDTH + x] * 255.0f; // 255 = blanc
				pixel = sf::Color(result_color, result_color, result_color);
				image.setPixel(x, y, pixel);
			}
		}
		image.saveToFile("Example_PerlinNoise_2D.png");

		// nettoyage
		delete[] result;
	}

	// Va g�n�rer une image PNG dans le dossier courant
	// Nuage de gris
	void PerlinNoise_2D_Stacked()
	{
		float * result = new float[SIZE_IMG_HEIGHT * SIZE_IMG_WIDTH]; // buffer de l'image
		sf::Color pixel;
		sf::Image image;
		int result_color;

		// compute perlin noise
		Tricible::PerlinNoise::PerlinNoise2DStacked(16, 9, 5, 0.25f, SIZE_IMG_WIDTH, SIZE_IMG_HEIGHT, &result);

		// mise en place d'un fond blanc
		image.create(SIZE_IMG_WIDTH, SIZE_IMG_HEIGHT, sf::Color::White);

		// render perlin noise
		for (int y = 0; y < SIZE_IMG_HEIGHT; ++y)
		{
			for (int x = 0; x < SIZE_IMG_WIDTH; x++)
			{
				result_color = result[y * SIZE_IMG_WIDTH + x] * 255.0f; // 255 = blanc
				pixel = sf::Color(result_color, result_color, result_color);
				image.setPixel(x, y, pixel);
			}
		}
		image.saveToFile("Example_PerlinNoise_2D_Stacked.png");

		// nettoyage
		delete[] result;
	}

	// Va g�n�rer une image PNG dans le dossier courant
	// Nuage de gris qui est ensuite coloris� avec une liste de gradientColor
	void PerlinNoise_2D_Stacked_With_Color()
	{
		// compute perlin noise
		float * result = new float[SIZE_IMG_HEIGHT * SIZE_IMG_WIDTH];
		Tricible::PerlinNoise::PerlinNoise2DStacked(30, 15, 8, 0.30f, SIZE_IMG_WIDTH, SIZE_IMG_HEIGHT, &result);

		// gradient mapping
		Tricible::GradientsLinear grad;

		grad.AddGradientPoint(Tricible::GradientPoint(0.00f, Tricible::Color::RGBA(0, 50, 200)));
		grad.AddGradientPoint(Tricible::GradientPoint(0.30f, Tricible::Color::RGBA(0, 200, 0)));
		grad.AddGradientPoint(Tricible::GradientPoint(0.45f, Tricible::Color::RGBA(200, 50, 0)));
		grad.AddGradientPoint(Tricible::GradientPoint(0.55f, Tricible::Color::RGBA(200, 255, 0)));
		grad.AddGradientPoint(Tricible::GradientPoint(0.70f, Tricible::Color::RGBA(200, 50, 200)));
		grad.AddGradientPoint(Tricible::GradientPoint(1.00f, Tricible::Color::RGBA(0, 200, 200)));

		// render perlin noise
		sf::Color pixel;
		sf::Image image;
		Tricible::Color::RGBA resultGrad;

		image.create(SIZE_IMG_WIDTH, SIZE_IMG_HEIGHT, sf::Color::White);
		for (int y = 0; y < SIZE_IMG_HEIGHT; ++y)
		{
			for (int x = 0; x < SIZE_IMG_WIDTH; x++)
			{
				grad.GetColor(result[y * SIZE_IMG_WIDTH + x], &resultGrad);
				pixel = sf::Color(resultGrad.Red(), resultGrad.Green(), resultGrad.Blue());
				image.setPixel(x, y, pixel);
			}
		}
		image.saveToFile("Example_PerlinNoise_2D_Stacked_With_Color.png");

		// nettoyage
		delete[] result;
	}
}

