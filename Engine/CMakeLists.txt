##
## Author: Sebastien Maire
## Contribs:
##

cmake_minimum_required(VERSION 2.8)
project(TricibleEngine)


## Material #########################################################
#################################################################
set(FOLDER_GROUP  Material)
set(
    "${CMAKE_PROJECT_NAME}${FOLDER_GROUP}Sources"
)
set(
    "${CMAKE_PROJECT_NAME}${FOLDER_GROUP}Includes"
		"./Material/Material.hpp"
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

## Texture #########################################################
#################################################################
set(FOLDER_GROUP Texture)
set(
    "${CMAKE_PROJECT_NAME}${FOLDER_GROUP}Sources"
)
set(
    "${CMAKE_PROJECT_NAME}${FOLDER_GROUP}Includes"
	"./Texture/Texture.hpp"
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

## Rendering ########################################################
#################################################################
set(FOLDER_GROUP Rendering)
set(
    "${CMAKE_PROJECT_NAME}${FOLDER_GROUP}Sources"
)
set(
    "${CMAKE_PROJECT_NAME}${FOLDER_GROUP}Includes"
	"./Rendering/Renderer.hpp"
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

## Tools ###########################################################
#################################################################
set(FOLDER_GROUP  Tools)
set(
    "${CMAKE_PROJECT_NAME}${FOLDER_GROUP}Sources"
		"./Tools/Point3.cpp"
)
set(
    "${CMAKE_PROJECT_NAME}${FOLDER_GROUP}Includes"
	"./Tools/Point3.hpp"
    "./Tools/3x3Matrix.hpp"
	"./Tools/Interpolation.hpp"
    "./Tools/Tools.hpp"
    "./Tools/Macros.hpp"
	"./Tools/RNG.hpp"
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


## Color ###########################################################
#################################################################
set(FOLDER_GROUP Color)
set(
    "${CMAKE_PROJECT_NAME}${FOLDER_GROUP}Sources"
)
set(
    "${CMAKE_PROJECT_NAME}${FOLDER_GROUP}Includes"
	"./Color/RGB.hpp"
    "./Color/RGBA.hpp"
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
	
## Scene ###########################################################
#################################################################
set(
    "${CMAKE_PROJECT_NAME}SceneSources"
    "./Scene/Sphere.cpp"
    "./Scene/Scene.cpp"
    "./Scene/Triangle.cpp"
    "./Scene/Plane.cpp"
	"./Scene/Scene.cpp"
	"./Scene/AIntersectable.cpp"
	"./Scene/Mesh.cpp"
)

set(
    "${CMAKE_PROJECT_NAME}SceneIncludes"
    "./Scene/Sphere.hpp"
    "./Scene/ALight.hpp"
    "./Scene/AObject.hpp"
    "./Scene/Plane.hpp"
    "./Scene/Triangle.hpp"
    "./Scene/Scene.hpp"
	"./Scene/Camera.hpp"
	"./Scene/Mesh.hpp"
	"./Scene/AIntersectable.hpp"
)

source_group(
    "Scene\\"
    FILES
    ${${CMAKE_PROJECT_NAME}SceneSources}
)
source_group(
    "Scene\\"
    FILES
    ${${CMAKE_PROJECT_NAME}SceneIncludes}
)


## Root ###############################
set(
    "${CMAKE_PROJECT_NAME}RootSources"
)

set(
    "${CMAKE_PROJECT_NAME}RootIncludes"
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

## Binary ###############################
set(
    "EngineFiles"
	${${CMAKE_PROJECT_NAME}ToolsSources}
    ${${CMAKE_PROJECT_NAME}ToolsIncludes}
	
	${${CMAKE_PROJECT_NAME}MaterialSources}
    ${${CMAKE_PROJECT_NAME}MaterialIncludes}
	
	${${CMAKE_PROJECT_NAME}TextureSources}
    ${${CMAKE_PROJECT_NAME}TextureIncludes}
	
	${${CMAKE_PROJECT_NAME}ColorSources}
    ${${CMAKE_PROJECT_NAME}ColorIncludes}
	
	${${CMAKE_PROJECT_NAME}RenderingSources}
    ${${CMAKE_PROJECT_NAME}RenderingIncludes}
	
    ${${CMAKE_PROJECT_NAME}SceneSources}
    ${${CMAKE_PROJECT_NAME}SceneIncludes}
	
    ${${CMAKE_PROJECT_NAME}RootSources}
    ${${CMAKE_PROJECT_NAME}RootIncludes}
)

include_directories(${DIR_LIB_EXT}/FreeImage/${DIR_ARCH}/)

add_library(
    TricibleEngine
    STATIC
    ${EngineFiles}
)

target_link_libraries(
	TricibleEngine
	optimized
	${DIR_LIB_EXT}/FreeImage/${DIR_ARCH}/FreeImage.lib
	debug
	${DIR_LIB_EXT}/FreeImage/${DIR_ARCH}/FreeImage.lib
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory "${PROJECT_SOURCE_DIR}/Resources/" $<TARGET_FILE_DIR:${PROJECT_NAME}>/Resources/)

##add_custom_command(TARGET TricibleEngine PRE_BUILD
##                   COMMAND ${CMAKE_COMMAND} -E copy_directory
##                       ./Resources/ $<TARGET_FILE_DIR:TricibleEngine>)
##configure_file(./Resources/ ${CMAKE_CURRENT_BINARY_DIR}/Resources/ COPYONLY)