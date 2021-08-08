#include "../util/utilities.hpp"

#include <utility>  // estructuras utilitarias para sacar información

/*--------------------- std::underlying_type_t<type> --------------------------------

Para obtener el tipo que está por debajo. Si es un enum, devuelve le tipo de entero,
si es un alias, devuelve le auténtico

------------------------------------------------------------------------------------*/

#include <iostream>

//////////////////////////////// ENUMERADOR SIN ÁMBITO ////////////////////////////////////////

/*  ---------------------------------------------------------
    enum <nombre> : [<tipo>]
    {
        <item_1 [= <value>]>, .....<item_n [= <value>]>
    }
    ----------------------------------------------------------

    En MSVC, <tipo> por default es **int32_t**. En GCC, es **uint32_t**

    Para referirnos a los miembros, podemos usar operador :: como un namespace, 
    pero al ser enumeradores globales, no será necesario
*/

enum Color : uint32_t { red, green = 4, blue, black, white };

void enumeracion_sin_ambito() noexcept
{
    print_function_title( __func__ );

    std::cout   << "El valor del verde es " << green << '\n';
    std::cout   << "El valor del blanco es " << Color::white << '\n';
    std::cout   << "El tipo asociado al color blanco es "
                << typeid( std::underlying_type_t<Color> ).name() << '\n';
    std::cout   << "En GNU, no es claro el tipo, así que lo comparamos con uint32_t.\n"
                << "El tipo del color blanco es igual al tipo uint32_t? :"
                << std::boolalpha
                << ( typeid( std::underlying_type_t<Color> ) == typeid( uint32_t ) );

    std::cout   << "\n\n";
}

//////////////////////////////// ENUMERADOR CON ÁMBITO ////////////////////////////////////////
/*
    Mucho más recomendable con ámbito.

    ---------------------------------------------------------
    enum class|struct <nombre> : [<tipo>]
    {
        <item_1 [= <value>]>, .....<item_n [= <value>]>
    }
    ----------------------------------------------------------

    Es forzoso referirse a los miembros con el operador de resolución de ámbito,
    como si fuera un namespace, si bien se puede usar using
    
    Ojo: una clase y una estructura es lo mismo, la diferencia es que class por defecto es privada
        y una estructura por defecto es pública
*/

enum class Kolor { brown, magenta = 4, cyan, yellow, maroon };

void enumeracion_con_ambito() noexcept
{
    print_function_title( __func__ );

    using enum Kolor;

    std::cout   << "El valor del cafe es "
                << static_cast<std::underlying_type_t<Kolor>>( Kolor::brown ) << '\n';
    std::cout   << "El valor del magenta es "
                << static_cast<std::underlying_type_t<Kolor>>( magenta ) << '\n';
    std::cout   << "El tipo asociado al color magenta es "
                << typeid( std::underlying_type_t<Kolor> ).name() << '\n';
    std::cout   << "En GNU, no es claro el tipo, así que lo comparamos con int32_t.\n"
                << "El tipo del color magenta es igual al tipo int32_t? :"
                << std::boolalpha
                << ( typeid( std::underlying_type_t<Kolor> ) == typeid( int32_t ) );

    std::cout   << "\n\n";
}