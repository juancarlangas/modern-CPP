#include "../util/utilities.hpp"

#include <iostream> // int32_t
#include <array>

/*///////////////////////////////// ARREGLOS //////////////////////////////////////////

--------------------------------------------------------------------------------

                std::array<tipo, n_elementos> nombre;

--------------------------------------------------------------------------------

std::array se pasa por valor, a diferencia del arreglo clásico.
*/

void clase_array() noexcept
{
    print_function_title( __func__ );

    /*
    Un arreglo clásico es del tipo:
        <tipo> *const <variable> // apuntador constante a una variable o una
                                    "constante a un apuntador de 32 bits" */

    // por esta razón, no es posible asignar un arreglo clásico a otro de la forma...

        int32_t arreglo_1[5] = { 10, 20, 30, 40, 50 };
        // int32_t arreglo_2[5] = arreglo1; // ERROR

    // pero sí es posible asignar...

        std::array<int32_t, 5> array_1 = { 10, 20, 30, 40, 50 };
        auto array_2 = array_1;
}

//////////////////////////// REFERENCIAS A ARREGLOS ///////////////////////////////////
void referencias_a_arreglos() noexcept
{
    int32_t arreglo[5];
    int32_t ( &arreglo_ref )[5] = arreglo;
}

/////////////////////// ARREGLOS DE TAMAÑO FIJO COMO PARÁMETROS /////////////////////////

void imprimir_arreglo( std::array<int32_t, 5> &_Arreglo ) noexcept
{
    for ( int32_t i = 0; i < 5; ++i )
        std::cout << "array_1[" << i << "] = " << _Arreglo[i] << '\n';
    
    _Arreglo[2] = 150;
}

void arreglos_de_tamano_fijo_como_parametros() noexcept
{
    std::array<int32_t, 5> array_1 = { 10, 20, 30, 40, 50 };

    imprimir_arreglo( array_1 );    // Imprimimos por vez primera
    std::cout << "\n\n";
    imprimir_arreglo( array_1 );    // Imprimimos después de que internamente
                                        // la función modificó la referencia
}

/*///////////////////// ARREGLOS DE TAMAÑO FIJO COMO PARÁMETROS /////////////////////////
    
    Para recibir un arreglo como referencia a un arreglo de cualquer tamaño,
    usamos las plantillas
*/