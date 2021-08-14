#include <cstdint> // sinónimos

void referencias() noexcept
{
    int32_t valor;

    // Las dos formas en C++ para declarar una referencia son:
    int32_t &ref1 = valor;
    decltype( auto ) ref2 = ( valor );
}