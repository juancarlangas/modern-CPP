#include "../util/utilities.hpp"

#include <iostream>

// ESTRUCTURA SWITCH:

/* -------------------------------------------------------------------------------- 

    [attr] switch ( [init statement] <condición> ) <sentencia>

   -------------------------------------------------------------------------------- 

   En la condición se usará un valor numérico, puede ser decimal
   pero preferentemente entero o enumeración
*/

// vamos con el mismo enum

enum class Colour { GREEN, BLUE = 4, GRAY, OCRE, TEAL };

static const int32_t colorID = std::ostream::xalloc();

void mostrar_color_value( std::ostream &_Out, const auto _Valor )
{
    if constexpr ( std::is_enum_v<std::remove_cvref_t<decltype( _Valor )>> )
        _Out << static_cast<std::underlying_type_t<std::remove_cvref_t<decltype( _Valor )>>>( _Valor );
    else
        _Out << _Valor;
}

std::ostream &operator<<( std::ostream &_Out, const Colour _Color )
{
auto print = [&]( const char *_Texto )
{
    if ( _Out.iword( colorID ) )
        mostrar_color_value( _Out, _Color );
    else
        mostrar_color_value( _Out, _Texto );
};

/* por ahora dejamos pendiente el uso de using enum, debido a que las implementaciones
* que tenemos en Debian Bullseye y Termux de GCC y Clang no lo han integrado */

// using enum Colour;

switch ( _Color )
{
	case Colour::GREEN: print( "rojo" ); break;
	case Colour::BLUE:  print( "azul" ); break;
	case Colour::GRAY:  print( "gris" ); break;
	case Colour::OCRE:  print( "ocre" ); break;
	case Colour::TEAL:  print( "teal" ); break;
    default:    print( "desconocido" ); break;
    }

    return _Out;
}

std::ostream &show_number( std::ostream &_Out )
{
    _Out.iword( colorID ) = true;
    return _Out;
}

std::ostream &show_name( std::ostream &_Out )
{
    _Out.iword( colorID ) = false;
    return _Out;
}

void estructura_switch() noexcept
{
    print_function_title( __func__ );

    std::cout   << "Colour::BLUE tiene el valor de: " << show_number << Colour::BLUE
                << " y el nombre es: " << show_name  << Colour::BLUE;
    
    std::cout << "\n\n";
}
