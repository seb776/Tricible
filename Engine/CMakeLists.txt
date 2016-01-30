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
    "./Scene/ALight.hpp"
    "./Scene/AObject.hpp"
    "./Scene/Plan.hpp"
    "./Scene/Triangle.hpp"
)

set(
    "${CMAKE_PROJECT_NAME}RootSources"
)

set(
    "${CMAKE_PROJECT_NAME}RootIncludes"
    "./Point3.hpp"
    "./3x3Matrix.hpp"
    "./Renderer.hpp"
    "./Camera.hpp"
    "./Tools.hpp"
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

set(
    "EngineFiles"
    ${${CMAKE_PROJECT_NAME}SceneSources}
    ${${CMAKE_PROJECT_NAME}SceneIncludes}
    ${${CMAKE_PROJECT_NAME}RootSources}
    ${${CMAKE_PROJECT_NAME}RootIncludes}
)

add_library(
    TricibleEngine
    SHARED
    ${EngineFiles}
)
