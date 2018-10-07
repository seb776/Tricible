##
## Author: Sebastien Maire
## Contribs:
##

cmake_minimum_required(VERSION 2.8)
project(TricibleGUI)

## SOURCE_CODE_INJECTION_START ## DO NOT REMOVE THIS LINE, IT'S USED BY A PYTHON SCRIPT TO INJECT SOURCE FILES THE WAY WE WANT
#### Root ####
##########

set(FOLDER_GROUP Root)
set(
	"${CMAKE_PROJECT_NAME}${FOLDER_GROUP}Sources"
	"E:/z0rg/Projects/Tricible/GUI/main.cpp"
)
set(
	"${CMAKE_PROJECT_NAME}${FOLDER_GROUP}Includes"
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

set(
	"SourceFiles"
	${${CMAKE_PROJECT_NAME}RootSources}
	${${CMAKE_PROJECT_NAME}RootIncludes}
)
## SOURCE_CODE_INJECTION_END ## DO NOT REMOVE THIS LINE, IT'S USED BY A PYTHON SCRIPT TO INJECT SOURCE FILES THE WAY WE WANT

add_executable(
    TricibleGUI
    ${SourceFiles}
)

target_link_libraries(
    TricibleGUI
    TricibleEngine
)

include_directories(${DIR_LIB_SFML_ROOT}/include)
include_directories(${DIR_LIB_EXT}/FreeImage/${DIR_ARCH}/)

TARGET_LINK_LIBRARIES(TricibleGUI optimized ${DIR_LIB_SFML}/${STATIC_LIB_PREFIX}sfml-graphics.${STATIC_LIB_EXT} debug ${DIR_LIB_SFML}/${STATIC_LIB_PREFIX}sfml-graphics-d.${STATIC_LIB_EXT})
TARGET_LINK_LIBRARIES(TricibleGUI optimized ${DIR_LIB_SFML}/${STATIC_LIB_PREFIX}sfml-window.${STATIC_LIB_EXT} debug ${DIR_LIB_SFML}/${STATIC_LIB_PREFIX}sfml-window-d.${STATIC_LIB_EXT})
TARGET_LINK_LIBRARIES(TricibleGUI optimized ${DIR_LIB_SFML}/${STATIC_LIB_PREFIX}sfml-system.${STATIC_LIB_EXT} debug ${DIR_LIB_SFML}/${STATIC_LIB_PREFIX}sfml-system-d.${STATIC_LIB_EXT})
TARGET_LINK_LIBRARIES(TricibleGUI optimized ${DIR_LIB_SFML}/${STATIC_LIB_PREFIX}sfml-network.${STATIC_LIB_EXT} debug ${DIR_LIB_SFML}/${STATIC_LIB_PREFIX}sfml-network-d.${STATIC_LIB_EXT})

target_link_libraries(
	TricibleGUI
	optimized
	${DIR_LIB_EXT}/FreeImage/${DIR_ARCH}/FreeImage.lib
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "${DIR_DLL_SFML}/sfml-graphics$<$<CONFIG:debug>:-d>-2.dll" $<TARGET_FILE_DIR:${PROJECT_NAME}>)
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "${DIR_DLL_SFML}/sfml-system$<$<CONFIG:debug>:-d>-2.dll" $<TARGET_FILE_DIR:${PROJECT_NAME}>)
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "${DIR_DLL_SFML}/sfml-window$<$<CONFIG:debug>:-d>-2.dll" $<TARGET_FILE_DIR:${PROJECT_NAME}>)
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "${DIR_DLL_SFML}/sfml-network$<$<CONFIG:debug>:-d>-2.dll" $<TARGET_FILE_DIR:${PROJECT_NAME}>)
	
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD TARGET  COMMAND ${CMAKE_COMMAND} -E copy_if_different  "${DIR_LIB_EXT}/FreeImage/${DIR_ARCH}/FreeImage.dll" $<TARGET_FILE_DIR:${PROJECT_NAME}>)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory $<TARGET_FILE_DIR:TricibleEngine>/Resources/ $<TARGET_FILE_DIR:${PROJECT_NAME}>/Resources/
)

## This command triggers the sources list update, it generates ${SourceFiles} and filters
add_custom_command(TARGET  ${PROJECT_NAME}
					PRE_BUILD
					COMMAND 
				    ${DIR_TOOLS}/CMakeScript.py ${CMAKE_PROJECT_NAME} ${PROJECT_SOURCE_DIR} ${PROJECT_NAME}
					DEPENDS ${DIR_TOOLS}/CMakeScript.py
)
	
## ATTENTION VS SPECIFIC
set_target_properties(${PROJECT_NAME} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/$(Configuration)")