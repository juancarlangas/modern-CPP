#include "../util/utilities.hpp"

#include <bits/stdint-intn.h>
#include <iomanip>
#include <iostream>
#include <ciso646> // Para usar las palabras 'and' y 'or'
#include <algorithm> // para usar std::find(), std::begin() y std::end()
#include <iterator>
#include <ostream>
#include <array>
#include <tuple>
#include <string>
#include <string_view>
#include <type_traits>

/// 007 - Condicionales
//
// Basados en el tipo -bool- que puede adquirir un valor
// 		true: (0)
// 		false: (1)
//
// Expresiones true: Cualquier valor NO CERO, o cadenas vacías ANSI "" o UNICODE u8""
// 				false: cero, nullptr, NULL
//
// Operadores de comparación
//
// 		<, >, <=, >=, ==, !=
// 			<operador left> <operando> <operador right> -> true / false
//
// 		<=> (operador de tres vías "nave espacial")
// 			<operador left> <operando> <operador right> -> objeto (puede ser de 3 tipos)

//		& AND binario / AND de operación binaria
//		| OR binario / OR de operación binaria

//		&& (and con <ciso646>) AND lógico
//		|| (or  con <ciso646>) OR lógico
//
#define COMPARAR( _Valor1, _Signo, _Valor2 )\
	std::cout << _Valor1 << " "#_Signo" " << _Valor2 << " = " << ( _Valor1 _Signo _Valor2 )\
			  << std::endl;

void expresiones()
{
	int32_t valor1 = 10, valor2 = 20;
	bool comparacion = valor1 == valor2;

	std::cout << std::boolalpha; // para que imprima true o false en lugar de 0 y 1
	COMPARAR( valor1, <, valor2 );
	COMPARAR( valor1, >, valor2 );
	COMPARAR( valor1, <=, valor2 );
	COMPARAR( valor1, >=, valor2 );
	COMPARAR( valor1, ==, valor2 );
	COMPARAR( valor1, !=, valor2 );

	bool son_iguales_y_pares = valor1 == valor2 and ( valor1 % 2 == 0 ) and ( valor2 % 2 == 0 );

	return;
}

// OPeraciones en CORTO CIRCUITO
// Sirve para que no haga comparaciones a lo puro pendejo

bool regresar_true()
{
	std::cout << __func__ << " "; // __func__ regresa el nombre de la función
	return true;
}

bool regresar_false()
{
	std::cout << __func__ << " ";
	return false;
}

void corto_circuito()
{
	// BASTANTE UTIL PARA ARMAR UNA ESTRUCTURA DE EJECUCIÓN CONDICIONAL

	bool prueba;

	imprimir_nombre_de_funcion( __func__ );

	std::cout << "\nregresar_false() and regresar_true: ";
	prueba = regresar_false() and regresar_true(); 	// evalúa e imprime solo el primero

	std::cout << "\nregresar_true() and regresar_false: ";
	prueba = regresar_true() and regresar_false();	// evalúa e imprime ambas

	// Los apuntadores sin inicializar, el compilador los inicializa a 0
	int32_t *apuntador_entero;
	std::cout << "\n<apuntador sin inicializar> or regresar_false(): ";
	prueba = apuntador_entero or regresar_false();	// evalúa ambos e imprime el segundo

	// Las cadenas vacías se consideran TRUE, porque tienen un caracter ('\0')
	std::cout << "\n<cadena vacía> and regresar_false(): ";
	prueba =  "" and regresar_false();	// evalúa e imprime ambas

	// NEGACIÓN
	// ! true -> false
	// ! 0.01 -> 0
	// ! ""	char *ptr{ 0x123343232 }
	// ! 'H' -> 0

	return;
}

// NUEVA SINTAXIS
// if ( <declaración-de-variable>; <condición-lógica> )

void if_nueva_sintaxis()
{
	int32_t valores[] = { 10, 27, 28, 47, 69, 78 };

	if ( auto busqueda = std::find( std::begin( valores ), std::end( valores ), 47 );
			busqueda != std::end( valores ) )
		std::cout << "\nEl valor encontrado es " << *busqueda << std::endl;
	else {
		std::cout << "\nEl valor no ha sido encontrado\n";
		std::cout << "El arreglo tiene " << busqueda - valores << " elementos" << std::endl;
	}

	if ( auto busqueda = std::find( std::begin( valores ), std::end( valores ), 100 );
			busqueda != std::end( valores ) )
		std::cout << "\nEl valor encontrado es " << *busqueda << std::endl;
	else {
		std::cout << "\nEl valor no ha sido encontrado\n";
		std::cout << "El arreglo tiene " << busqueda - valores << " elementos" << std::endl;
	}

	return;
}
	
// if constexpr
// Para poder crear una función con retorno múltiple al estilo de JavaScript

template<int32_t opcion> // para convertir a -opcion- en una EXPRESIóN CONSTANTE

constexpr decltype( auto ) retorno_lo_que_sea()
{
	using namespace std::literals; // nos permite hacer estas payasadas de ""sv y "s"

	if constexpr ( opcion == 1 )
		return std::array<int32_t, 5> { 1, 2, 3, 4, 5 };
	else if constexpr ( opcion == 2 )
		return std::tuple{ "Hola"sv, "Mundo"sv};
	else if constexpr ( opcion == 3 )
		return "Cadena de retorno"s;
	else if constexpr ( opcion == 4 )
		return 453;
	else if constexpr ( opcion == 5 )
		return [] { std::cout << "Ejecutando esta función.\n"; };
	else
		return ( std::cout );
}

void if_constexpr()
{
	using namespace std;

	auto ar = retorno_lo_que_sea<1>();
								// v Patrón de Diseño Iterador / Patrón de Adaptador
	copy( ar.begin(), ar.end(), std::ostream_iterator<decltype(ar)::value_type>( std::cout, ", " ) );
	retorno_lo_que_sea<6>().put( '\n' );
	
	auto t = retorno_lo_que_sea<2>();
	retorno_lo_que_sea<6>() << "Tuple: " << get<0>( t ) << ", " << get<1>( t ) << std::endl;

	retorno_lo_que_sea<6>() << "La cadena de retorno es: " << retorno_lo_que_sea<3>() << std::endl;

	retorno_lo_que_sea<6>() << "El valor numérico es: " << retorno_lo_que_sea<4>() << std::endl;

	retorno_lo_que_sea<5>()();

	// NOTA: Resulta mucho más eficiente. Utilizar el constexpr siempre que se pueda
	return;
}
	
//---------------------------------------- decltype ----------------------------------------
//	Sirve para obtener ("captu tipo de datos de lo que sea que le pasemos
//------------------------------------------------------------------------------------------

auto obtener_objeto()
{
	class MiClase {
		public:
			int32_t valor;
			MiClase( int32_t _Valor ) : valor{ _Valor }
			{}
			
			void imprimir_valor()
			{
				std::cout << "\nEl valor de MiClase es: " << valor << "\n";
			}

			using custom_type = int32_t;
	};

	MiClase mi_clase( 1 );

	return mi_clase;
}	

void declare_type()
{
	// declaramos una variable con el tipo de retorno (clase) y la usamos
	auto objeto_1 = obtener_objeto(); // ya está instanciada
	objeto_1.imprimir_valor();

	// capturamos el tipo de retorno (clase) en un sinónimo
	// y la usamos para declarar otro objeto nuevo
	using tipo_de_clase = decltype( obtener_objeto() ) ;
	tipo_de_clase objeto_2( 2 ); // como es nueva no está instanciada y hay que construirla
	objeto_2.imprimir_valor();

	// directamente para crear nuevos objetos sin sinónimo
	decltype( obtener_objeto() ) objeto_3( 3 );
	objeto_3.imprimir_valor();

	// lo usamos pero con el objeto anterior
	decltype( objeto_3 ) objeto_4( 4 );
	objeto_4.imprimir_valor();

	// vamos a declarar una variable con el tipo que está dentro de la clase
	decltype ( obtener_objeto() )::custom_type custom_int = 4;
	std::cout << '\n' << custom_int << '\n';

	return;
}

//---------------------------------- ENUMERADORES ------------------------------------------//
//
// Sin Ámbito
// ==========
//
// enum <NOMBRE> [: <tipo entero del enum>]
// {
// 		<CONSTANTE_1> [= <valor>],
// 		.
// 		.
// 		<CONSTANTE_X> [= <valor>]
// 	}

enum Colores : int64_t {
	AZUL,
	ROJO,
	VERDE,
	AMARILLO = 20,
	NARANJA,
	ROSA,
	NEGRO = 100,
	BLANCO
};

void enumeraciones()
{
	std::cout << AZUL << '\n';
	std::cout << ROJO << '\n';
	std::cout << VERDE << '\n';
	std::cout << Colores::AMARILLO << '\n'; // se puede usar el operador :: pues es un ámbito
	std::cout << Colores::NARANJA << '\n';
	std::cout << Colores::ROSA << '\n';
	std::cout << Colores::NEGRO << '\n';
	std::cout << Colores::BLANCO << std::endl;
}


// Con Ámbito
// ==========
//
// Lo mismo que sin ámbito pero se usa la palabra class o struct
//
// enum [class/struct] <NOMBRE> [: <tipo entero del enum>]
// {
// 		<CONSTANTE_1> [= <valor>],
// 		.
// 		.
// 		<CONSTANTE_X> [= <valor>]
// 	}

enum class ColoresConAmbito : int64_t {
	AZUL,
	ROJO,
	VERDE,
	AMARILLO = 20,
	NARANJA,
	ROSA,
	NEGRO = 100,
	BLANCO
};

void enumeraciones_con_ambito()
{
	using cast_for_enum = std::underlying_type_t< ColoresConAmbito >;

	std::cout << static_cast<cast_for_enum>(ColoresConAmbito::AZUL) << '\n';
	std::cout << static_cast<cast_for_enum>(ColoresConAmbito::ROJO) << '\n';
	std::cout << static_cast<cast_for_enum>(ColoresConAmbito::VERDE) << '\n';
	std::cout << static_cast<cast_for_enum>(ColoresConAmbito::AMARILLO) << '\n';
	std::cout << static_cast<cast_for_enum>(ColoresConAmbito::NARANJA) << '\n';
	std::cout << static_cast<cast_for_enum>(ColoresConAmbito::ROSA) << '\n';
	std::cout << static_cast<cast_for_enum>(ColoresConAmbito::NEGRO) << '\n';
	std::cout << static_cast<cast_for_enum>(ColoresConAmbito::BLANCO) << std::endl;
}
