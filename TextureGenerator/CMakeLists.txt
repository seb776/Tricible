##
## Author: Pierre Courteille
## Contribs: Sebastien Maire
##

## version minium du cmake
cmake_minimum_required(VERSION 2.8)

## Nom du projet (sera affiché dans l'IDE tel quel)
project(TricibleTextureGenerator)


## SOURCE_CODE_INJECTION_START ## DO NOT REMOVE THIS LINE, IT'S USED BY A PYTHON SCRIPT TO INJECT SOURCE FILES THE WAY WE WANT
#### Procedural1D ####
##########

set(FOLDER_GROUP Procedural1D)
set(
	"${CMAKE_PROJECT_NAME}${FOLDER_GROUP}Sources"
	".//Procedural1D/Curve.cpp"
	".//Procedural1D/OverlappedCurve.cpp"
)
set(
	"${CMAKE_PROJECT_NAME}${FOLDER_GROUP}Includes"
	".//Procedural1D/Curve.hpp"
	".//Procedural1D/OverlappedCurve.hpp"
	".//Procedural1D/Procedural1D.hpp"
)
source_group(
	"${FOLDER_GROUP}\\"
	FILES
	${${CMAKE_PROJECT_NAME}${FOLDER_GROUP}Sources}
)
source_group(
	"${FOLDER_GROUP}\\"
	FILES
	${${CMAKE_PROJECT_NAME}${FOLDER_GROUP}Includes}
)

#### Procedural2D ####
##########

set(FOLDER_GROUP Procedural2D)
set(
	"${CMAKE_PROJECT_NAME}${FOLDER_GROUP}Sources"
	".//Procedural2D/OverlappedPerlinNoise.cpp"
	".//Procedural2D/PerlinNoise.cpp"
)
set(
	"${CMAKE_PROJECT_NAME}${FOLDER_GROUP}Includes"
	".//Procedural2D/OverlappedPerlinNoise.hpp"
	".//Procedural2D/PerlinNoise.hpp"
	".//Procedural2D/Procedural2D.hpp"
)
source_group(
	"${FOLDER_GROUP}\\"
	FILES
	${${CMAKE_PROJECT_NAME}${FOLDER_GROUP}Sources}
)
source_group(
	"${FOLDER_GROUP}\\"
	FILES
	${${CMAKE_PROJECT_NAME}${FOLDER_GROUP}Includes}
)

#### Gradient ####
##########

set(FOLDER_GROUP Gradient)
set(
	"${CMAKE_PROJECT_NAME}${FOLDER_GROUP}Sources"
)
set(
	"${CMAKE_PROJECT_NAME}${FOLDER_GROUP}Includes"
	".//Utility/Gradient/LinearGradient.hpp"
	".//Utility/Gradient/PointGradient.hpp"
)
source_group(
	"${FOLDER_GROUP}\\"
	FILES
	${${CMAKE_PROJECT_NAME}${FOLDER_GROUP}Sources}
)
source_group(
	"${FOLDER_GROUP}\\"
	FILES
	${${CMAKE_PROJECT_NAME}${FOLDER_GROUP}Includes}
)

set(
	"SourceFiles"
	${${CMAKE_PROJECT_NAME}Procedural1DSources}
	${${CMAKE_PROJECT_NAME}Procedural1DIncludes}
	${${CMAKE_PROJECT_NAME}Procedural2DSources}
	${${CMAKE_PROJECT_NAME}Procedural2DIncludes}
	${${CMAKE_PROJECT_NAME}GradientSources}
	${${CMAKE_PROJECT_NAME}GradientIncludes}
)
## SOURCE_CODE_INJECTION_END ## DO NOT REMOVE THIS LINE, IT'S USED BY A PYTHON SCRIPT TO INJECT SOURCE FILES THE WAY WE WANT


##
## définition bibliothèque 
##
add_library(
    TricibleTextureGenerator
    STATIC
    ${SourceFiles}
)

## This command triggers the sources list update, it generates ${SourceFiles} and filters
add_custom_command(TARGET  ${PROJECT_NAME}
					PRE_BUILD
					COMMAND 
				    ${DIR_TOOLS}/CMakeScript.py ${CMAKE_PROJECT_NAME} ${PROJECT_SOURCE_DIR} ${PROJECT_NAME}
					DEPENDS ${DIR_TOOLS}/CMakeScript.py
)

target_link_libraries(
    TricibleTextureGenerator
    TricibleEngine
)
