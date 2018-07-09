##
## Author: Sebastien Maire
## Contribs:
##

cmake_minimum_required(VERSION 2.8)
project(TricibleTextureGeneratorGUI)

set (
    "${CMAKE_PROJECT_NAME}RootSources"
    "main.cpp"
	"UnitTesting_Tools.cpp"
	"UnitTesting_Tools.hpp"
	"Unit Testing/PerlinNoise.cpp"
	"Unit Testing/PerlinNoise.hpp"
)

set(
    "${CMAKE_PROJECT_NAME}Sources}"
    ${${CMAKE_PROJECT_NAME}RootSources}
)

MESSAGE (${DIR_LIB_SFML_ROOT})

add_executable(
    TricibleTextureGeneratorGUI
    "${${CMAKE_PROJECT_NAME}RootSources}"
)

target_link_libraries(
    TricibleTextureGenerator
)

include_directories(${DIR_LIB_SFML_ROOT}/include)



TARGET_LINK_LIBRARIES(TricibleTextureGeneratorGUI optimized ${DIR_LIB_SFML}/${STATIC_LIB_PREFIX}sfml-graphics.${STATIC_LIB_EXT} debug ${DIR_LIB_SFML}/${STATIC_LIB_PREFIX}sfml-graphics-d.${STATIC_LIB_EXT})
TARGET_LINK_LIBRARIES(TricibleTextureGeneratorGUI optimized ${DIR_LIB_SFML}/${STATIC_LIB_PREFIX}sfml-window.${STATIC_LIB_EXT} debug ${DIR_LIB_SFML}/${STATIC_LIB_PREFIX}sfml-window-d.${STATIC_LIB_EXT})
TARGET_LINK_LIBRARIES(TricibleTextureGeneratorGUI optimized ${DIR_LIB_SFML}/${STATIC_LIB_PREFIX}sfml-system.${STATIC_LIB_EXT} debug ${DIR_LIB_SFML}/${STATIC_LIB_PREFIX}sfml-system-d.${STATIC_LIB_EXT})
TARGET_LINK_LIBRARIES(TricibleTextureGeneratorGUI optimized ${DIR_LIB_SFML}/${STATIC_LIB_PREFIX}sfml-network.${STATIC_LIB_EXT} debug ${DIR_LIB_SFML}/${STATIC_LIB_PREFIX}sfml-network-d.${STATIC_LIB_EXT})

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "${DIR_DLL_SFML}/sfml-graphics$<$<CONFIG:debug>:-d>-2.dll" $<TARGET_FILE_DIR:${PROJECT_NAME}>)
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "${DIR_DLL_SFML}/sfml-system$<$<CONFIG:debug>:-d>-2.dll" $<TARGET_FILE_DIR:${PROJECT_NAME}>)
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "${DIR_DLL_SFML}/sfml-window$<$<CONFIG:debug>:-d>-2.dll" $<TARGET_FILE_DIR:${PROJECT_NAME}>)
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "${DIR_DLL_SFML}/sfml-network$<$<CONFIG:debug>:-d>-2.dll" $<TARGET_FILE_DIR:${PROJECT_NAME}>)

