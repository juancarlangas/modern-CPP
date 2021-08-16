#include <iostream>

extern int32_t restar_publica( const int _valor1, const int _valor2 ) noexcept
{
    return _valor1 - _valor2;
}

static int32_t restar_privada( const int _valor1, const int _valor2 ) noexcept
{
    return _valor1 - _valor2;
}
