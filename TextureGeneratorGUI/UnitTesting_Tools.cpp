//
// Author: Pierre COURTEILLE
//

//----------------------------------------//
// include STL
//----------------------------------------//
#include <iostream> // pour std::cout et std::endl
#include <sstream> // pour stringstream
#include <chrono> // pour system_clock
#include <string>
#include <ctime> // pour localTime
#include <iomanip> // put_time

//----------------------------------------//
// include OS
//----------------------------------------//
#include "Windows.h" // TODO PCO dépendance Windows.h pour la fonction "GetCurrentDirectory"

//----------------------------------------//
// include SFML
//----------------------------------------//
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

//----------------------------------------//
// include Tricible
//----------------------------------------//
#include "./UnitTesting_Tools.hpp"

//----------------------------------------//
// code
//----------------------------------------//
namespace UnitTesting
{
	namespace Tools // TODO, une fois dans VS 2017 avec le support de C++ 17, alors imbriquer les namespaces
	{
		// taille de la fenêtre SFML pour afficher une image
		#define		SIZE_WINDOW_WIDTH	800
		#define		SIZE_WINDOW_HEIGHT	500

		// obtenir la date courante dans un format affichable et lisible (string) = YYYY-MM-DD HHMM
		std::string GetCurrentDateTimeToString()
		{
			auto dateTimeNow = std::chrono::system_clock::now();
			auto castTo_time_t = std::chrono::system_clock::to_time_t(dateTimeNow);
			std::stringstream bufferStream;

			bufferStream << std::put_time(std::localtime(&castTo_time_t), "%Y-%m-%d %X"); // 2018-12-31 1654

			return bufferStream.str(); // passage par copie
		}

		// obtenir le chemin du dossier courant où s'exécute actuellement le processus en cours
		std::string GetCurrentDirectoryOfProcess()
		{
			char pathCurrentDirectory[MAX_PATH + 1]; // MAX_PATH viens de "minwindef.h", il vaut 260 en principe

			GetCurrentDirectory(MAX_PATH, pathCurrentDirectory); // renvoyer le dossier courant

			return std::string(pathCurrentDirectory); // passsage par copie
		}

		// lancer un test avec une fonction en paramètre de type "void (*ptrFunction)(void)"
		// gère le texte et la mise en page de la console
		void RunTest_NoParameters(const std::string & TestTitle, void (*ptrFunction)(void))
		{
			std::cout << " Try [" << TestTitle << "]";
			std::cout << " --> START = [" << GetCurrentDateTimeToString() << "]";
			try
			{
				ptrFunction();
			}
			catch (std::exception exp)
			{
				std::cout << " --> ERROR = [" << GetCurrentDateTimeToString() << "] | msg = "  << exp.what() << std::endl;
			}
			std::cout << " --> END !" << std::endl;
		}

		// afficher une image à partir d'un fichier dans une fenêtre SFML
		void DrawInSfmlWindowFromPictureFile(const std::string & pathPicture)
		{
			sf::RenderWindow window(sf::VideoMode(SIZE_WINDOW_WIDTH, SIZE_WINDOW_HEIGHT), "Unit Testing - courte_p (waiting activated in console)");
			sf::Texture	texture;
			sf::Sprite sprite;

			texture.loadFromFile(pathPicture);
			sprite.setTexture(texture);
			window.draw(sprite);
			window.display();

			std::cout << "----------------------------------------" << std::endl;
			std::cout << "SFML STOPPED -> Press key to continue" << std::endl;
			getchar();
		}
	}
}

