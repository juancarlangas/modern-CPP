#include "utilities.hpp"

#include <iostream>

void imprimir_nombre_de_funcion( const char * ) noexcept
{
	std::cout << "///////////// void " << __func__ << "()";
}

void print_function_title( std::string_view _Nombre ) noexcept
{
    std::cout << _Nombre << '\n';
    for ( int32_t i = 0; i < _Nombre.length(); ++i )
        std::cout << '=';
    std::cout << "\n\n";
}
