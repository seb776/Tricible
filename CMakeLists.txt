##
## Author: Sebastien Maire
## Contribs:
##

cmake_minimum_required(VERSION 3.5)
project(Tricible)

##set(TRICIBLE_LIB "TricibleEngine")

set (DIR_LIB_EXT ${CMAKE_CURRENT_SOURCE_DIR}/ext)
set (DIR_LIB_SFML_ROOT ${DIR_LIB_EXT}/SFML)

set(STATIC_LIB_EXT lib)
set(STATIC_LIB_PREFIX "")

if (MINGW)
    set(DIR_COMPILER GCC_SJLJ_4_8_1)
    set(STATIC_LIB_EXT a)
    set(STATIC_LIB_PREFIX lib)
elseif (MSVC14)
    set(DIR_COMPILER VC14)
elseif (MSVC12)
    set(DIR_COMPILER VC12)
else (MINGW)
    MESSAGE("Unsupported compiler")
endif(MINGW)

  if( CMAKE_SIZEOF_VOID_P EQUAL 8 )
    set( DIR_ARCH ./64 )
  else( CMAKE_SIZEOF_VOID_P EQUAL 8 )
    set( DIR_ARCH ./32 )
  endif( CMAKE_SIZEOF_VOID_P EQUAL 8 )

set (DIR_LIB_SFML ${DIR_LIB_SFML_ROOT}/${DIR_COMPILER}/${DIR_ARCH}/lib)
set (DIR_DLL_SFML ${DIR_LIB_SFML_ROOT}/${DIR_COMPILER}/${DIR_ARCH}/dll)

set (DIR_TOOLS ${CMAKE_CURRENT_SOURCE_DIR}/Tools)

add_subdirectory(GUI)
add_subdirectory(Engine)
add_subdirectory(TextureGenerator)
add_subdirectory(TextureGeneratorGUI)