//
// Author: Pierre COURTEILLE
//

//----------------------------------------//
// include STL
//----------------------------------------//
#include <iostream> // pour std::cout et std::endl
#include <string>

//----------------------------------------//
// include Tricible
//----------------------------------------//
#include "./UnitTesting_Tools.hpp"
#include "./Unit_Testing/PerlinNoise.hpp"

	//----------------------------------------//
	// code
	//----------------------------------------//
int RunBlock_AllPerlinNoise()
{
	std::string pathDir = UnitTesting::Tools::GetCurrentDirectoryOfProcess();

	// en-tête
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "By courte_p : Unit Testing / Perlin Noise" << std::endl;
	std::cout << "Current Directories : " << std::endl << pathDir << std::endl;
	std::cout << "----------------------------------------" << std::endl;

	// bloc de tests
	std::cout << "BLOCK : PerlinNoise" << std::endl;
	UnitTesting::Tools::RunTest_NoParameters("1D", &UnitTesting::PerlinNoise_1D);
	UnitTesting::Tools::RunTest_NoParameters("1D_Stacked", &UnitTesting::PerlinNoise_1D_Overlapped);
	UnitTesting::Tools::RunTest_NoParameters("2D", &UnitTesting::PerlinNoise_2D);
	UnitTesting::Tools::RunTest_NoParameters("2D_Stacked", &UnitTesting::PerlinNoise_2D_Overlapped);
	UnitTesting::Tools::RunTest_NoParameters("2D_Stacked_With_Color", &UnitTesting::PerlinNoise_2D_Overlapped_With_Color);

	// spéciale : afficher une image dans une fenêtre SFML
	UnitTesting::Tools::DrawInSfmlWindowFromPictureFile("Example_PerlinNoise_2D_Stacked_With_Color.png");

	// pied de page
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Press any key to exit... (STOPPED)" << std::endl;
	getchar(); // attendre entrée touche clavier

	// fin
	return 0;
}

int main()
{
	int result = 0;

	result += RunBlock_AllPerlinNoise();

	return (result);
}

