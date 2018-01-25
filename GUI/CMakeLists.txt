##
## Author: Sebastien Maire
## Contribs:
##

cmake_minimum_required(VERSION 2.8)
project(TricibleGUI)

set (
    "${CMAKE_PROJECT_NAME}RootSources"
    "main.cpp"
)

set(
    "${CMAKE_PROJECT_NAME}Sources}"
    ${${CMAKE_PROJECT_NAME}RootSources}
)

MESSAGE (${DIR_LIB_SFML_ROOT})

add_executable(
    TricibleGUI
    "${${CMAKE_PROJECT_NAME}RootSources}"
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

