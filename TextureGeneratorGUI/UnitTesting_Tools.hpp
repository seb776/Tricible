//
// Author: Pierre COURTEILLE
//

//----------------------------------------//
// Protection double inclusion
//----------------------------------------//
#pragma once

//----------------------------------------//
// include STL
//----------------------------------------//
#include "string"

//----------------------------------------//
// code
//----------------------------------------//
namespace UnitTesting
{
	namespace Tools // TODO, une fois dans VS 2017 avec le support de C++ 17, alors imbriquer les namespaces
	{
		std::string GetCurrentDateTimeToString();
		std::string GetCurrentDirectoryOfProcess();
		void RunTest_NoParameters(const std::string & TestTitle, void (*ptrFunction)(void));
		void DrawInSfmlWindowFromPictureFile(const std::string & pathPicture);
	}
}

