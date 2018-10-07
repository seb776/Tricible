##
## Author: Sebastien Maire
## Contribs:
##

cmake_minimum_required(VERSION 2.8)
project(TricibleEngine)

execute_process(COMMAND ${PROJECT_SOURCE_DIR}/CMakeScript.py ${CMAKE_PROJECT_NAME} ${PROJECT_SOURCE_DIR})

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
	"E:/z0rg/Projects/Tricible/Engine/Color/RGB.hpp"
	"E:/z0rg/Projects/Tricible/Engine/Color/RGBA.hpp"
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
	"E:/z0rg/Projects/Tricible/Engine/Material/Material.hpp"
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
	"E:/z0rg/Projects/Tricible/Engine/Rendering/Renderer.hpp"
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
	"E:/z0rg/Projects/Tricible/Engine/Scene/AIntersectable.cpp"
	"E:/z0rg/Projects/Tricible/Engine/Scene/Mesh.cpp"
	"E:/z0rg/Projects/Tricible/Engine/Scene/Plane.cpp"
	"E:/z0rg/Projects/Tricible/Engine/Scene/Scene.cpp"
	"E:/z0rg/Projects/Tricible/Engine/Scene/Sphere.cpp"
	"E:/z0rg/Projects/Tricible/Engine/Scene/Triangle.cpp"
)
set(
	"${CMAKE_PROJECT_NAME}${FOLDER_GROUP}Includes"
	"E:/z0rg/Projects/Tricible/Engine/Scene/AIntersectable.hpp"
	"E:/z0rg/Projects/Tricible/Engine/Scene/ALight.hpp"
	"E:/z0rg/Projects/Tricible/Engine/Scene/AObject.hpp"
	"E:/z0rg/Projects/Tricible/Engine/Scene/Camera.hpp"
	"E:/z0rg/Projects/Tricible/Engine/Scene/IntersectionInfo.hpp"
	"E:/z0rg/Projects/Tricible/Engine/Scene/Mesh.hpp"
	"E:/z0rg/Projects/Tricible/Engine/Scene/Plane.hpp"
	"E:/z0rg/Projects/Tricible/Engine/Scene/Scene.hpp"
	"E:/z0rg/Projects/Tricible/Engine/Scene/Source.hpp"
	"E:/z0rg/Projects/Tricible/Engine/Scene/Sphere.hpp"
	"E:/z0rg/Projects/Tricible/Engine/Scene/Triangle.hpp"
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
	"E:/z0rg/Projects/Tricible/Engine/Texture/Texture.hpp"
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
	"E:/z0rg/Projects/Tricible/Engine/Tools/Interpolation.cpp"
	"E:/z0rg/Projects/Tricible/Engine/Tools/Point3.cpp"
	"E:/z0rg/Projects/Tricible/Engine/Tools/RNG.cpp"
)
set(
	"${CMAKE_PROJECT_NAME}${FOLDER_GROUP}Includes"
	"E:/z0rg/Projects/Tricible/Engine/Tools/3x3Matrix.hpp"
	"E:/z0rg/Projects/Tricible/Engine/Tools/Interpolation.hpp"
	"E:/z0rg/Projects/Tricible/Engine/Tools/Interpolation.tpp"
	"E:/z0rg/Projects/Tricible/Engine/Tools/Macros.hpp"
	"E:/z0rg/Projects/Tricible/Engine/Tools/Point3.hpp"
	"E:/z0rg/Projects/Tricible/Engine/Tools/RNG.hpp"
	"E:/z0rg/Projects/Tricible/Engine/Tools/RNG.tpp"
	"E:/z0rg/Projects/Tricible/Engine/Tools/Tools.hpp"
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
				    ${DIR_TOOLS}/CMakeScript.py ${CMAKE_PROJECT_NAME} ${PROJECT_SOURCE_DIR} ${PROJECT_NAME}
					DEPENDS ${DIR_TOOLS}/CMakeScript.py
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory "${PROJECT_SOURCE_DIR}/Resources/" $<TARGET_FILE_DIR:${PROJECT_NAME}>/Resources/
)




