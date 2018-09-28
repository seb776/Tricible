##
## Author: Pierre CourteilleSebastien
## Contribs:
##

## version minium du cmake
cmake_minimum_required(VERSION 2.8)

## Nom du projet (sera affiché dans l'IDE tel quel)
project(TricibleTextureGenerator)

##
## Définition dossier et contenu : Procedural1D
##

## Nom du dossier
set(FOLDER_GROUP Procedural1D)

## Contenu du dossier
set(
    "${CMAKE_PROJECT_NAME}${FOLDER_GROUP}Sources"
		"./Procedural1D/Curve.cpp"
		"./Procedural1D/OverlappedCurve.cpp"
)
set(
    "${CMAKE_PROJECT_NAME}${FOLDER_GROUP}Includes"
		"./Procedural1D/Procedural1D.hpp"
		"./Procedural1D/Curve.hpp"
		"./Procedural1D/OverlappedCurve.hpp"
)

## Regroupement de fichiers (sera affiché dans l'IDE pour organiser le code source)
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

##
## Définition dossier et contenu : Procedural2D
##

## Nom du dossier
set(FOLDER_GROUP Procedural2D)

## Contenu du dossier
set(
    "${CMAKE_PROJECT_NAME}${FOLDER_GROUP}Sources"
		"./Procedural2D/PerlinNoise.cpp"
		"./Procedural2D/OverlappedPerlinNoise.cpp"
)
set(
    "${CMAKE_PROJECT_NAME}${FOLDER_GROUP}Includes"
		"./Procedural2D/Procedural2D.hpp"
		"./Procedural2D/PerlinNoise.hpp"
		"./Procedural2D/OverlappedPerlinNoise.hpp"
)

## Regroupement de fichiers (sera affiché dans l'IDE pour organiser le code source)
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

##
## Définition dossier et contenu : Utility/Gradient
##

## Nom du dossier
set(FOLDER_GROUP Gradient)

## Contenu du dossier
set(
    "${CMAKE_PROJECT_NAME}${FOLDER_GROUP}Includes"
		"./Utility/Gradient/PointGradient.hpp"
		"./Utility/Gradient/LinearGradient.hpp"
)

## Regroupement de fichiers (sera affiché dans l'IDE pour organiser le code source)
source_group(
    "Utility\\${FOLDER_GROUP}\\"
    FILES
    ${${CMAKE_PROJECT_NAME}${FOLDER_GROUP}Includes}
)


##
## HUB des fichiers
##

set(
    "TextureGeneratorFiles"

	${${CMAKE_PROJECT_NAME}Procedural1DSources}
    ${${CMAKE_PROJECT_NAME}Procedural1DIncludes}

	${${CMAKE_PROJECT_NAME}Procedural2DSources}
    ${${CMAKE_PROJECT_NAME}Procedural2DIncludes}

    ${${CMAKE_PROJECT_NAME}GradientIncludes}
)

##
## définition bibliothèque 
##
add_library(
    TricibleTextureGenerator
    STATIC
    ${TextureGeneratorFiles}
)

target_link_libraries(
    TricibleTextureGenerator
    TricibleEngine
)
