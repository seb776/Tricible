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

TARGET_LINK_LIBRARIES(TricibleGUI optimized ${DIR_LIB_SFML}/sfml-graphics.lib debug ${DIR_LIB_SFML}/sfml-graphics-d.lib)
TARGET_LINK_LIBRARIES(TricibleGUI optimized ${DIR_LIB_SFML}/sfml-window.lib debug ${DIR_LIB_SFML}/sfml-window-d.lib)
TARGET_LINK_LIBRARIES(TricibleGUI optimized ${DIR_LIB_SFML}/sfml-system.lib debug ${DIR_LIB_SFML}/sfml-system-d.lib)
TARGET_LINK_LIBRARIES(TricibleGUI optimized ${DIR_LIB_SFML}/sfml-network.lib debug ${DIR_LIB_SFML}/sfml-network-d.lib)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "${DIR_DLL_SFML}//sfml-graphics$<$<CONFIG:debug>:-d>-2.dll" $<TARGET_FILE_DIR:${PROJECT_NAME}>)
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "${DIR_DLL_SFML}/sfml-system$<$<CONFIG:debug>:-d>-2.dll" $<TARGET_FILE_DIR:${PROJECT_NAME}>)
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "${DIR_DLL_SFML}/sfml-window$<$<CONFIG:debug>:-d>-2.dll" $<TARGET_FILE_DIR:${PROJECT_NAME}>)
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "${DIR_DLL_SFML}/sfml-network$<$<CONFIG:debug>:-d>-2.dll" $<TARGET_FILE_DIR:${PROJECT_NAME}>)


##set(
  ##  "${CMAKE_PROJECT_NAME}_")