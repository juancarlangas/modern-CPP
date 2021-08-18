#set( CMAKE_CXX_STANDARD 20 )

cmake_minimum_required( VERSION 3.20.2 )

project( course 
    VERSION 1.0
    DESCRIPTION "Clases de modern C++ con Dennis Ritchie West"
    LANGUAGES CXX )

add_executable( course
    src/main.cpp
    src/clases/temas.hpp
	src/clases/001-flujos-1.cpp
	src/clases/002-flujos-2.cpp
	src/clases/003-namespaces.cpp
	src/clases/004-funciones-1.cpp
	src/clases/005-funciones-2.cpp
	src/clases/006-define.cpp
	src/clases/007-condicionales.cpp
	src/clases/008-string_view.cpp
    src/clases/008-2-0-atributos.cpp
    src/clases/008-2-1-enumeraciones.cpp
    src/clases/008-2-2-switch.cpp
    src/clases/008-3-0-referencias.cpp
    src/clases/008-3-1-arreglos.cpp
    src/util/utilities.cpp
	src/util/misFuncionesMatematicas.cpp )
 
# LA siguiente propiedad es la investigada,
# pero la subsecuente es la enseñada por Denis, que es especìfica para el TARGET
# y además permite que sean varias propiedades.

	# set_property( TARGET course PROPERTY CXX_STANDARD 20 )

set_target_properties( course PROPERTIES
	CXX_STANDARD 20
	RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin" )

target_compile_features( course PRIVATE cxx_std_20 )
set( CXX_STANDARD_REQUIRED ON )

if ( MSVC )
    target_compile_options( course PRIVATE "/W4" )
elseif ( CMAKE_COMPILER_IS_GNUCXX )
	target_compile_options( course PRIVATE -Wall -Wextra -Wpedantic -g )
endif ()

set( CMAKE_EXPORT_COMPILE_COMMANDS ON )
