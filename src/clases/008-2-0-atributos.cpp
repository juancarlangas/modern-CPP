/*                      ATRIBUTOS DE C++

Nos permiten especificar comportamientos al compilador
para que produzca un código mucho más eficiente
*/

#include "../util/utilities.hpp"
#include <iostream>

/****************************** [[ noreturn ]] ********************************

Indica que la función NO RETORNA. No que es VOID sino literalmente
se va a la chingada el programa. Usado por ejemplo con la instrucción
-throw-

-trow-: Sirve para lanzar un error y tirar a la chingada el programa

------------------------------------------------------------------------------

    [[ noreturn ]] <tipo> <nombre>() // antes del tipo

    <tipo> <nombre> [[ noreturn ]] () // después del nombre 

---------------------------------------------------------------------------- */    

namespace Errors
{
    [[ noreturn ]] void numero_no_valido()
    {
        throw "El número no es válido";
    }
}

void atributo_noreturn() noexcept
{
    print_function_title( __func__ );
    // Errors::numero_no_valido(); // no se utiliza porque sino vale verga
    std::cout << "... nada que imprimir culeros\n\n";
}

/***************************** [[ deprecated ]] ******************************

Para que el compilador sepa que esa chingadera ya no se utiliza
    
------------------------------------------------------------------------------

    [[ deprecated ]] ["Mensaje de advertencia"]

---------------------------------------------------------------------------- */    

namespace Test
{
    namespace V1
    {
        [[ deprecated( "Utilizar la funcin del namespace V2") ]]
            void mostrar_algo() noexcept
        {
            std::cout << "Mostrando algo en versión antigua\n";

        }
    }
    inline namespace V2
    {
        void mostrar_algo() noexcept
        {
            std::cout << "Mostrando algo en versión nueva\n";

        }

    }
}

void atributo_deprecated() noexcept
{
    print_function_title( __func__ );

    Test::V1::mostrar_algo(); // Mostrará advertencia
    Test::V2::mostrar_algo(); // No mostrará advertencia
    
    std::cout << '\n';
}

/************************** [[ no_unique_adress ]] ****************************
 * 
 * Para especificar que un elemento vacío (una variable) compartirá
 * la misma dirección que su contenedor (como un struct).
 */

struct EmptyStruct {};

struct Container {
    int32_t entero;
    [[ no_unique_address ]] EmptyStruct estructura_vacia;
};

void atributo_no_unique_adress() noexcept
{
    print_function_title( __func__ );

    Container contenedor;

    std::cout   << "La dirección de -contenedor- es: " << &contenedor << '\n'
                << "La dirección de (contenedor.entero) es: " << &contenedor.entero << '\n'
                << "La dirección de (contenedor.estructura_vacia) es: "
                    << &contenedor.estructura_vacia << "\n\n";
}

/*************************************** [[ maybe_unused ]] ***************************************
 * Sirve para que el compilador no nos mande warning cuando tengamos una variable
 * que posíblemente no sea utilizada.
 * Se utiliza ANTES DEL TIPO
 * 
 *              [[ maybe_unused ]] <tipo> <nombre>;
*/

void prueba_con_maybe_unused( [[ maybe_unused ]] int32_t value ) noexcept
{
    std::cout << __func__ <<    "() no usa su parámetro y el compilador lanza advertencia "
                                " pero gracias a [[ maybe_unused ]] ya no lo da";
    
    std::cout << "\n\n";
}

void atributo_maybe_unused() noexcept
{
    print_function_title( __func__ ); 

    prueba_con_maybe_unused( 50 );
}

/***************************** atributos de switch ***************************************
 * [[falltrough]] 
 * 
 * Sirve para decirle al compilador que explícitamente NO ESTAMOS USANDO break en un case,
 * por lo tanto, que se ha de comportar como un switch es originalmente
 * 
 * [[likely]]
 * 
 * Decirle al compilador que se trata del case que tiene MÁS posibilidades de ejecutarse
 * 
 * [[unlikely]]
 * 
 * Decirle al compilador que se trata del case que tiene MENOS posibilidades de ejecutarse
 * */

void atributos_de_switch() noexcept
{
    print_function_title( __func__ );

    int32_t value = 4;

    switch( value ) {
        [[unlikely]] case 0: // caso menos probable
            std::cout << "Value es igual a cero.";
            break;
        case 1:
            std::cout << "Value es igual a uno.";
            break;
        case 2:
            std::cout << "Value es igual a uno.";
            [[fallthrough]]; // escalerita
        case 3:
            std::cout << "Value es igual a tres.";
            break;
        [[likely]] case 4: // Caso más probable
            std::cout << "Value es igual a cuatro.";
            break;
        default:
            ;
    }
    
    std::cout << "\n\n";
}