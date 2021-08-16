#include <cctype>
#include <iostream>
#include <string_view>

////////////////////////////////////////// FUNCIONES /////////////////////////////////////////

	int32_t sumar_original( int32_t val1, int32_t _val2 );

	int32_t sumar_noexcept( int32_t val1, int32_t val2 ) noexcept;

	auto sumar_auto( int32_t val1, int32_t val2 ) noexcept;

	decltype( auto ) sumar_decltype( int32_t val1, int32_t val2 ) noexcept;

	auto sumar_con_flecha( int32_t val1, int32_t val2 ) noexcept -> int32_t;

/////////////////////////////////////// ESTADOS //////////////////////////////////////////
void estados()
{	/*
	auto - Almacenamiento automátito (C / deprecated)
	==================================================
	 - Está en la pila
	 - se destruye al salir del ámbito */
		int32_t entero_automatico;	/* auto unsigned int v1
	
	const - Coinstante
	==================
	 - Es automática también
	 . No se puede modificar (es constante o "variable inmutable") */
		const uint32_t entero_constante = 1; // const unsigned int
		uint32_t const constante_entera = 1; // unsigned const int

}


///////////////////////////// CATEGORIAS //////////////////////////////////////////////////	
void categorias()
{	/*
	Expresiones l (left)
	===================
	- Tiene una memoria existente yu se hace referencia mediante un identificador
	- Se puede asignar
	- Casi siempre se coloca a la izquierda

	Expresiones r (right o TEMPORALES) - litarales, expresiones constantes o constexpr
	===========
	- No existen en memoria
	- No se pueden asignar
	- CAsi siempre van a la derecha
		- numeros
		- cadenas ANSI "cadena ansi"
		- cadenas UNICODE u8"cadena utf8"
		- etc..
*/
}

/////////////////////////////////////// ALIAS //////////////////////////////////////////////////
void alias()
{	
	using namespace std; /*

	De tipos:
	=========
	
	- typedef <tipo_original> <tipo_nuevo> // Clásica de C y C+11 */
		typedef int32_t entero_32;
		entero_32 entero1 = 10; /*

	- using <tipo_nuevo> = <tipo_original>	// C++14 */
		using cadena = basic_string<char, char_traits<char>, allocator<char>>; // el tipo de string
		cadena miCadena = "Texto de la cadena";

		// Otros ejemplos
		int32_t entero;	// de 32 bits, sí o sí
		int_fast32_t entero_rapido;	// al menos de 32 bits y sea el más rápido
		int_least32_t entero_al_menos_de_32_bits; /* al menos sea de 32
		

	 De variables:
	 =============

	<tipo> &<nombre_nuevo> = <nombre_original> */
		
		long double v3 = 10;
		long double &v3_alias = v3;
		long double &v3_alias_de_alias = v3_alias;

		cout << "El valor de v3 es: " << v3 << endl;

		v3 = 30;
		cout << "El valor de v3_alias es: " << v3_alias << endl;

		v3 = 50;
		cout << "El valor de v3_alias_de_alias es: " << v3_alias_de_alias << endl;

		cout << "La dirección de v3 es: " << &v3 << endl;
		cout << "La dirección de v3_alias es: " << &v3_alias << endl;
		cout << "La dirección de v3_alias_de_alias es: " << &v3_alias_de_alias << endl;
}

/*/////////////////////////// ALIAS_COMO_PARAMETROS //////////////////////////////////////////

	---------------------------------------------------------------------------------------
	string_view: Obtiene el apuntador de lo que le pasen, evitando usar alias. Más moderno
	Lo usamos si le vamos a pasar un alias sobre una literal de cadena
	o si pasamos una cadena que no vamos a modificar usamos <string_view>
	--------------------------------------------------------------------------------------*/

void hago_muchas_cosas( const std::string_view _Texto, size_t &_Tamano,
						char &_Upper_first_letter, char &_Upper_last_letter,
						std::string &_Cadena_invertida ) noexcept
{
	_Tamano = _Texto.length();
	_Upper_first_letter = _toupper( _Texto.front() );
	_Upper_last_letter = _toupper( _Texto.back() );
	_Cadena_invertida = ::std::string( _Texto.crbegin(), _Texto.crend() );
}

namespace prueba
{
	const std::string &cadena_original_alias = "la clase de CPp";
	size_t tamaño;
	char upper_first_letter, upper_last_letter;
	std::string cadena_invertida;
}

void alias_como_parametros()
{	
	using namespace std;
	using namespace prueba;
/*
	A pesar de que

		std::string &texto_alias = "texto";

	está prohibido, puesto que a un alias debe de serle asignado una valor l,
	al decir const std::string permitimos que se cree el objeto const std::string de la cadena
	y de esa forma asignarle un valor r a un valor R.
	Muy util a la hora de enviar cadenas como argumento a una función. */


		hago_muchas_cosas( "la Clase de CPp" , 	tamaño, upper_first_letter, upper_last_letter,
												cadena_invertida );

		cout << "La cadena es: " << cadena_original_alias << endl
			 << "El tamaño de la cadena es: " << tamaño << endl
			 << "La primera y la ultima letra en mayúscula son: "
			 << upper_first_letter << " y " << upper_last_letter << endl
			 << "La cadena invertida es " << cadena_invertida << endl;
}


//////////////////////////////// APUNTADORES Y ALIAS A FUNCIONES ///////////////////////////////
auto apuntadores_y_alias_a_funciones() -> void
{
	using namespace std;
	using namespace prueba; /*

	Apuntadores
	===========
	<tipo> ( *<nombre_de_la_funcion> )( <argumentos...> ); <-	los nombres de parametros
	 															son opcionales */
	void ( *hago_muchas_cosas_Ptr )( const ::std::string_view,
									 size_t &,
									 char &_upper_first_letter,
									 char &_upper_last_letter,
									 std::string &_cadena_invertida ) noexcept = hago_muchas_cosas;
									 
	// forma simplificada: Al asignarlo con auto, se crea un apuntador a la función.
	auto variable_hago_muchas_cosas_Ptr = hago_muchas_cosas;

	// y se invoca...
	hago_muchas_cosas_Ptr( "la Clase de CPp" , 
							tamaño, upper_first_letter, upper_last_letter, cadena_invertida );
	// o...														
	( *hago_muchas_cosas_Ptr )( "la Clase de CPp",
								tamaño, upper_first_letter, upper_last_letter, cadena_invertida ); /*


	Alias
	=====
	<tipo> ( &<nombre_de_la_funcion> )( <argumentos...> ); <-- los nombres de parametros
																son opcionales */

	void ( &alias_a_hago_muchas_cosas )( const ::std::string_view,
										 size_t &,
										 char &_upper_first_letter,
										 char &_upper_last_letter,
										 ::std::string &_cadena_invertida ) = hago_muchas_cosas;
									 
	// forma simplificada
	auto &alias_hago_muchas_cosas_Ptr = hago_muchas_cosas;

	// y se invoca...
	alias_a_hago_muchas_cosas( "la Clase de CPp" , 	tamaño, upper_first_letter, upper_last_letter,
													cadena_invertida );
	// o...
	( *alias_a_hago_muchas_cosas )( "la Clase de CPp" , 	tamaño, upper_first_letter, upper_last_letter,
															cadena_invertida );

	// ... tanto los apuntadores a función como los alias a funcion
	// se invocan con el <nombre>() o con *<nombre>() como si se estuvieran desreferenciando

}
