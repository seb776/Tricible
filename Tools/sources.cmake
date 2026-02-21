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
	"./Rendering/TestRender.cl.c"
)
set(
	"${CMAKE_PROJECT_NAME}${FOLDER_GROUP}Includes"
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
