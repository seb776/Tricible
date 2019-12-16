##
## Author: Sebastien Maire
## Contribs:
##

cmake_minimum_required(VERSION 2.8)
project(TricibleEngine)

execute_process(COMMAND ${PROJECT_SOURCE_DIR}/CMakeScript.py -s ${CMAKE_PROJECT_NAME} -d ${PROJECT_SOURCE_DIR} -p ${PROJECT_NAME})

include_directories(${DIR_LIB_EXT}/FreeImage/${DIR_ARCH}/)

## SOURCE_CODE_INJECTION_START ## DO NOT REMOVE THIS LINE, IT'S USED BY A PYTHON SCRIPT TO INJECT SOURCE FILES THE WAY WE WANT
#### Color ####
##########

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

#### Material ####
##########

set(FOLDER_GROUP Material)
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

#### Rendering ####
##########

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

#### Scene ####
##########

set(FOLDER_GROUP Scene)
set(
	"${CMAKE_PROJECT_NAME}${FOLDER_GROUP}Sources"
	"./Scene/AIntersectable.cpp"
	"./Scene/Mesh.cpp"
	"./Scene/Plane.cpp"
	"./Scene/Scene.cpp"
	"./Scene/Sphere.cpp"
	"./Scene/Triangle.cpp"
)
set(
	"${CMAKE_PROJECT_NAME}${FOLDER_GROUP}Includes"
	"./Scene/AIntersectable.hpp"
	"./Scene/ALight.hpp"
	"./Scene/AObject.hpp"
	"./Scene/Camera.hpp"
	"./Scene/IntersectionInfo.hpp"
	"./Scene/Mesh.hpp"
	"./Scene/Plane.hpp"
	"./Scene/Scene.hpp"
	"./Scene/Source.hpp"
	"./Scene/Sphere.hpp"
	"./Scene/Triangle.hpp"
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

#### Texture ####
##########

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

#### Tools ####
##########

set(FOLDER_GROUP Tools)
set(
	"${CMAKE_PROJECT_NAME}${FOLDER_GROUP}Sources"
	"./Tools/Interpolation.cpp"
	"./Tools/Point3.cpp"
	"./Tools/RNG.cpp"
)
set(
	"${CMAKE_PROJECT_NAME}${FOLDER_GROUP}Includes"
	"./Tools/3x3Matrix.hpp"
	"./Tools/Interpolation.hpp"
	"./Tools/Interpolation.tpp"
	"./Tools/Macros.hpp"
	"./Tools/Point3.hpp"
	"./Tools/RNG.hpp"
	"./Tools/RNG.tpp"
	"./Tools/Tools.hpp"
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
	${${CMAKE_PROJECT_NAME}ColorSources}
	${${CMAKE_PROJECT_NAME}ColorIncludes}
	${${CMAKE_PROJECT_NAME}MaterialSources}
	${${CMAKE_PROJECT_NAME}MaterialIncludes}
	${${CMAKE_PROJECT_NAME}RenderingSources}
	${${CMAKE_PROJECT_NAME}RenderingIncludes}
	${${CMAKE_PROJECT_NAME}SceneSources}
	${${CMAKE_PROJECT_NAME}SceneIncludes}
	${${CMAKE_PROJECT_NAME}TextureSources}
	${${CMAKE_PROJECT_NAME}TextureIncludes}
	${${CMAKE_PROJECT_NAME}ToolsSources}
	${${CMAKE_PROJECT_NAME}ToolsIncludes}
)
## SOURCE_CODE_INJECTION_END ## DO NOT REMOVE THIS LINE, IT'S USED BY A PYTHON SCRIPT TO INJECT SOURCE FILES THE WAY WE WANT

add_library(
    TricibleEngine
    STATIC
    ${SourceFiles}
)

target_link_libraries(
	TricibleEngine
	optimized
	${DIR_LIB_EXT}/FreeImage/${DIR_ARCH}/FreeImage.lib
	debug
	${DIR_LIB_EXT}/FreeImage/${DIR_ARCH}/FreeImage.lib
)

## This command triggers the sources list update, it generates ${SourceFiles} and filters
add_custom_command(TARGET  ${PROJECT_NAME}
					PRE_BUILD
					COMMAND 
				    ${DIR_TOOLS}/CMakeScript.py -s ${CMAKE_PROJECT_NAME} -d ${PROJECT_SOURCE_DIR} -p ${PROJECT_NAME}
					DEPENDS ${DIR_TOOLS}/CMakeScript.py
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory "${PROJECT_SOURCE_DIR}/Resources/" $<TARGET_FILE_DIR:${PROJECT_NAME}>/Resources/
)
