##
## Author: Sebastien Maire
## Contribs:
##

cmake_minimum_required(VERSION 3.5)
project(TricibleEngine)

execute_process(COMMAND ${PROJECT_SOURCE_DIR}/CMakeScript.py -s ${CMAKE_PROJECT_NAME} -d ${PROJECT_SOURCE_DIR} -p ${PROJECT_NAME})

include_directories(${DIR_LIB_EXT}/FreeImage/${DIR_ARCH}/)
include_directories(${DIR_LIB_EXT})

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

#### GLSLRendererCPP ####
##########

set(FOLDER_GROUP GLSLRendererCPP)
set(
	"${CMAKE_PROJECT_NAME}${FOLDER_GROUP}Sources"
	"./GLSLRendererCPP/GLSLFunctions.cpp"
	"./GLSLRendererCPP/mat2.cpp"
	"./GLSLRendererCPP/mat3.cpp"
	"./GLSLRendererCPP/SwizzleProxies.cpp"
	"./GLSLRendererCPP/VariableArray.cpp"
	"./GLSLRendererCPP/vec2.cpp"
	"./GLSLRendererCPP/vec3.cpp"
	"./GLSLRendererCPP/vec4.cpp"
)
set(
	"${CMAKE_PROJECT_NAME}${FOLDER_GROUP}Includes"
	"./GLSLRendererCPP/bvec2.hpp"
	"./GLSLRendererCPP/bvec3.hpp"
	"./GLSLRendererCPP/bvec4.hpp"
	"./GLSLRendererCPP/GLSLFunctions.hpp"
	"./GLSLRendererCPP/ivec2.hpp"
	"./GLSLRendererCPP/ivec3.hpp"
	"./GLSLRendererCPP/ivec4.hpp"
	"./GLSLRendererCPP/mat2.hpp"
	"./GLSLRendererCPP/mat3.hpp"
	"./GLSLRendererCPP/mat4.hpp"
	"./GLSLRendererCPP/Samplers.hpp"
	"./GLSLRendererCPP/Scalars.hpp"
	"./GLSLRendererCPP/Swizzle.glsl.hpp"
	"./GLSLRendererCPP/SwizzleProxies.hpp"
	"./GLSLRendererCPP/uvec2.hpp"
	"./GLSLRendererCPP/uvec3.hpp"
	"./GLSLRendererCPP/uvec4.hpp"
	"./GLSLRendererCPP/VariableArray.hpp"
	"./GLSLRendererCPP/vec2.hpp"
	"./GLSLRendererCPP/vec3.hpp"
	"./GLSLRendererCPP/vec4.hpp"
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
	"./Rendering/CPURenderer.cpp"
	"./Rendering/GLSLRenderer.cpp"
	"./Rendering/Renderer.cpp"
	"./Rendering/TestRender.glsl.cpp"
)
set(
	"${CMAKE_PROJECT_NAME}${FOLDER_GROUP}Includes"
	"./Rendering/CPURenderer.hpp"
	"./Rendering/GLSLRenderer.hpp"
	"./Rendering/OpenCLRenderer.hpp"
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
	"./Scene/AABBB.hpp"
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
	"./Tools/RNG.cpp"
	"./Tools/Tools.cpp"
	"./Tools/Vector3.cpp"
)
set(
	"${CMAKE_PROJECT_NAME}${FOLDER_GROUP}Includes"
	"./Tools/3x3Matrix.hpp"
	"./Tools/Interpolation.hpp"
	"./Tools/Interpolation.tpp"
	"./Tools/Macros.hpp"
	"./Tools/RNG.hpp"
	"./Tools/RNG.tpp"
	"./Tools/Tools.hpp"
	"./Tools/Vector3.hpp"
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
	${${CMAKE_PROJECT_NAME}GLSLRendererCPPSources}
	${${CMAKE_PROJECT_NAME}GLSLRendererCPPIncludes}
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

FIND_LIBRARY(OPENCL_LIBRARIES opencl64 )
	IF( OPENCL_LIBRARIES )
		FIND_LIBRARY(OPENCL_LIBRARIES opencl32 )
	ENDIF( OPENCL_LIBRARIES )
	
	SET( OPENCL_FOUND "NO" )
IF(OPENCL_LIBRARIES )
	SET( OPENCL_FOUND "YES" )
ENDIF(OPENCL_LIBRARIES)


TARGET_LINK_LIBRARIES(TricibleEngine ${OpenCL_LIBRARIES})

find_package(OpenGL REQUIRED)

# GLFW
set(glfw3_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../ext/glfw3_x64-windows/share/glfw3")
find_package(glfw3 CONFIG REQUIRED)


target_link_libraries(TricibleEngine
    OpenGL::GL
    glfw
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

## COPYFILES_CODE_INJECTION_START ## DO NOT REMOVE THIS LINE, IT'S USED BY A PYTHON SCRIPT TO INJECT SOURCE FILES THE WAY WE WANT
set(ENGINE_OPENCL_FILES)
# OpenCL Files
list(APPEND ENGINE_OPENCL_FILES C:/Users/z0rg/Projects/Perso/Tricible/Engine/GLSLRendererCPP/Swizzle.glsl.hpp)
add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy C:/Users/z0rg/Projects/Perso/Tricible/Engine/GLSLRendererCPP/Swizzle.glsl.hpp $<TARGET_FILE_DIR:${PROJECT_NAME}>/GLSLRendererCPP/Swizzle.glsl.hpp
)
# OpenCL Files
list(APPEND ENGINE_OPENCL_FILES C:/Users/z0rg/Projects/Perso/Tricible/Engine/Rendering/TestRender.glsl.cpp)
add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy C:/Users/z0rg/Projects/Perso/Tricible/Engine/Rendering/TestRender.glsl.cpp $<TARGET_FILE_DIR:${PROJECT_NAME}>/Rendering/TestRender.glsl.cpp
)
set_property(TARGET ${PROJECT_NAME}
    PROPERTY ENGINE_OPENCL_FILES "${ENGINE_OPENCL_FILES}")
set_property(TARGET ${PROJECT_NAME}
    PROPERTY PROJECT_ENGINE_SOURCEDIR "${PROJECT_SOURCE_DIR}")
message("${ENGINE_OPENCL_FILES}")
function(engine_attach_runtime target)
    get_target_property(OPEN_CL_FILES TricibleEngine ENGINE_OPENCL_FILES)
    get_target_property(PROJECT_ENGINE_SOURCEDIR_ TricibleEngine PROJECT_ENGINE_SOURCEDIR)
    message("${OPEN_CL_FILES}")
    foreach(file IN LISTS OPEN_CL_FILES)
        file(RELATIVE_PATH rel_path
             ${PROJECT_ENGINE_SOURCEDIR_}
             ${file})
        add_custom_command(
            TARGET ${target}
            POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
                ${file}
                $<TARGET_FILE_DIR:${target}>/${rel_path}
        )
    endforeach()
add_custom_command(
    TARGET ${target} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "$<IF:$<CONFIG:Debug>,${CMAKE_CURRENT_SOURCE_DIR}/../ext/glfw3_x64-windows/debug/bin/glfw3.dll,${CMAKE_CURRENT_SOURCE_DIR}/../ext/glfw3_x64-windows/bin/glfw3.dll>"
        $<TARGET_FILE_DIR:${target}>
)
endfunction()
## COPYFILES_CODE_INJECTION_END ## DO NOT REMOVE THIS LINE, IT'S USED BY A PYTHON SCRIPT TO INJECT SOURCE FILES THE WAY WE WANT