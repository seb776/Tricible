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


add_executable(
    "TricibleGUI"
    "${${CMAKE_PROJECT_NAME}RootSources}"
)

target_link_libraries(
    "TricibleGUI"
    TricibleEngine
)

##set(
  ##  "${CMAKE_PROJECT_NAME}_")