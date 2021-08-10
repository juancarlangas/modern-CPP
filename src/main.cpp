#include "clases/temas.hpp"

#include <cstdint>
#include <stdlib.h>
#include <iostream>

int32_t main()
{
    atributo_noreturn();
    atributo_deprecated();
    atributo_no_unique_adress();
    atributo_maybe_unused();
    atributos_de_switch();

    enumeracion_sin_ambito();
    enumeracion_con_ambito();

    estructura_switch();

    return EXIT_SUCCESS;
}