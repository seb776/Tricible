##
## Author: Sebastien Maire
## Contribs:
##

cmake_minimum_required(VERSION 2.8)
project(TricibleEngine)

set(
    "${CMAKE_PROJECT_NAME}SceneSources"
    "./Scene/Sphere.cpp"
)

set(
    "${CMAKE_PROJECT_NAME}SceneIncludes"
    "./Scene/Sphere.hpp"
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

set(
    "EngineFiles"
    ${${CMAKE_PROJECT_NAME}SceneSources}
    ${${CMAKE_PROJECT_NAME}SceneIncludes}
)

add_library(
    "TricibleEngine"
    SHARED
    ${EngineFiles}
)
