##
## Author: Sebastien Maire
## Contribs:
##

cmake_minimum_required(VERSION 2.8)
project(TricibleTextureGenerator)

set(
    "${CMAKE_PROJECT_NAME}RootSources"
	"./PerlinNoise.hpp"
	"./ColorRGBA.hpp"
	"./GradientPoint.hpp"
	"./GradientCollection.hpp"
    "./Generator.cpp"
)

source_group(
    "\\"
    FILES
    ${${CMAKE_PROJECT_NAME}RootSources}
)

source_group(
    "\\"
    FILES
    ${${CMAKE_PROJECT_NAME}RootIncludes}
)

set(
    "TextureGeneratorFiles"
    ${${CMAKE_PROJECT_NAME}RootSources}
    ${${CMAKE_PROJECT_NAME}RootIncludes}
)

add_library(
    TricibleTextureGenerator
    SHARED
    ${TextureGeneratorFiles}
)
