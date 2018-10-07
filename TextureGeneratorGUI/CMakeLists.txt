##
## Author: Sebastien Maire
## Contribs:
##

cmake_minimum_required(VERSION 2.8)
project(TricibleTextureGeneratorGUI)

## SOURCE_CODE_INJECTION_START ## DO NOT REMOVE THIS LINE, IT'S USED BY A PYTHON SCRIPT TO INJECT SOURCE FILES THE WAY WE WANT
#### Root ####
##########

set(FOLDER_GROUP Root)
set(
	"${CMAKE_PROJECT_NAME}${FOLDER_GROUP}Sources"
	"E:/z0rg/Projects/Tricible/TextureGeneratorGUI/main.cpp"
	"E:/z0rg/Projects/Tricible/TextureGeneratorGUI/UnitTesting_Tools.cpp"
)
set(
	"${CMAKE_PROJECT_NAME}${FOLDER_GROUP}Includes"
	"E:/z0rg/Projects/Tricible/TextureGeneratorGUI/UnitTesting_Tools.hpp"
)
source_group(
	"\\"
	FILES
	${${CMAKE_PROJECT_NAME}${FOLDER_GROUP}Sources}
)
source_group(
	"\\"
	FILES
	${${CMAKE_PROJECT_NAME}${FOLDER_GROUP}Includes}
)

#### Unit_Testing ####
##########

set(FOLDER_GROUP Unit_Testing)
set(
	"${CMAKE_PROJECT_NAME}${FOLDER_GROUP}Sources"
	"E:/z0rg/Projects/Tricible/TextureGeneratorGUI/Unit_Testing/PerlinNoise.cpp"
)
set(
	"${CMAKE_PROJECT_NAME}${FOLDER_GROUP}Includes"
	"E:/z0rg/Projects/Tricible/TextureGeneratorGUI/Unit_Testing/PerlinNoise.hpp"
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
	${${CMAKE_PROJECT_NAME}RootSources}
	${${CMAKE_PROJECT_NAME}RootIncludes}
	${${CMAKE_PROJECT_NAME}Unit_TestingSources}
	${${CMAKE_PROJECT_NAME}Unit_TestingIncludes}
)
## SOURCE_CODE_INJECTION_END ## DO NOT REMOVE THIS LINE, IT'S USED BY A PYTHON SCRIPT TO INJECT SOURCE FILES THE WAY WE WANT

add_executable(
    TricibleTextureGeneratorGUI
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
    TricibleTextureGeneratorGUI
    TricibleEngine
	TricibleTextureGenerator
)

TARGET_LINK_LIBRARIES(TricibleTextureGeneratorGUI optimized ${DIR_LIB_SFML}/${STATIC_LIB_PREFIX}sfml-graphics.${STATIC_LIB_EXT} debug ${DIR_LIB_SFML}/${STATIC_LIB_PREFIX}sfml-graphics-d.${STATIC_LIB_EXT})
TARGET_LINK_LIBRARIES(TricibleTextureGeneratorGUI optimized ${DIR_LIB_SFML}/${STATIC_LIB_PREFIX}sfml-window.${STATIC_LIB_EXT} debug ${DIR_LIB_SFML}/${STATIC_LIB_PREFIX}sfml-window-d.${STATIC_LIB_EXT})
TARGET_LINK_LIBRARIES(TricibleTextureGeneratorGUI optimized ${DIR_LIB_SFML}/${STATIC_LIB_PREFIX}sfml-system.${STATIC_LIB_EXT} debug ${DIR_LIB_SFML}/${STATIC_LIB_PREFIX}sfml-system-d.${STATIC_LIB_EXT})
TARGET_LINK_LIBRARIES(TricibleTextureGeneratorGUI optimized ${DIR_LIB_SFML}/${STATIC_LIB_PREFIX}sfml-network.${STATIC_LIB_EXT} debug ${DIR_LIB_SFML}/${STATIC_LIB_PREFIX}sfml-network-d.${STATIC_LIB_EXT})

include_directories(${DIR_LIB_SFML_ROOT}/include)
include_directories(${DIR_LIB_EXT}/FreeImage/${DIR_ARCH}/)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "${DIR_DLL_SFML}/sfml-graphics$<$<CONFIG:debug>:-d>-2.dll" $<TARGET_FILE_DIR:${PROJECT_NAME}>)
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "${DIR_DLL_SFML}/sfml-system$<$<CONFIG:debug>:-d>-2.dll" $<TARGET_FILE_DIR:${PROJECT_NAME}>)
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "${DIR_DLL_SFML}/sfml-window$<$<CONFIG:debug>:-d>-2.dll" $<TARGET_FILE_DIR:${PROJECT_NAME}>)
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "${DIR_DLL_SFML}/sfml-network$<$<CONFIG:debug>:-d>-2.dll" $<TARGET_FILE_DIR:${PROJECT_NAME}>)

