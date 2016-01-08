##
## Author: Sebastien Maire
## Contribs:
##

cmake_minimum_required(VERSION 2.8)
project(Tricible)

##set(TRICIBLE_LIB "TricibleEngine")

set (DIR_LIB_EXT ${CMAKE_CURRENT_SOURCE_DIR}/ext)
set (DIR_LIB_SFML_ROOT ${DIR_LIB_EXT}/SFML)

set(STATIC_LIB_EXT lib)

if (MINGW)
    set(DIR_COMPILER GCC_DW2)
    set(STATIC_LIB_EXT a)
elseif (MSVC14)
    set(DIR_COMPILER VC14)
else (MINGW)
    MESSAGE("Unsupported compiler")
endif(MINGW)

  if( CMAKE_SIZEOF_VOID_P EQUAL 8 )
    set( DIR_ARCH ./64 )
  else( CMAKE_SIZEOF_VOID_P EQUAL 8 )
    set( DIR_ARCH ./32 )
  endif( CMAKE_SIZEOF_VOID_P EQUAL 8 )

set (DIR_LIB_SFML ${DIR_LIB_SFML_ROOT}/${DIR_COMPILER}/${DIR_ARCH}/lib)
set (DIR_DLL_SFML ${DIR_LIB_SFML_ROOT}/${DIR_COMPILER}/${DIR_ARCH}/bin)

add_subdirectory(Engine)
add_subdirectory(GUI)
