#include <array>
#include <iostream>
#include <string>
#include <fstream>
#include <utility>

/*
   std::string_view
   ================
   Nos sirve para acceder a una cadena original sin tener que realizar una copia.

   Útil para evitarnos estas firmas...

   void print_string( const std::string );
   void print_string( const char * );
*/

void print_string( const std::string_view _Cadena )
{
	std::cout << "Texto: " << _Cadena  << ", Size: " << _Cadena.size() << '\n';
}

void palabra_string_view() noexcept
{
	print_string( "Hola al curso 8 de Denis" );

	std::string mensaje{ "Hola de nuevo hijos de su perra madre" };
	print_string( mensaje );

	std::cout << std::endl;
}

/*
						SENTENCIAS DE CONTROL
	
	if
	if constexpr
	switch
	while
	do-while
	for
	range-for
 
	Operadores de comparación
	=========================

	!	(Negación)
	==
	!=
	<
	<=
	>
	>=
	<=>
*/

// if ()
// =====
auto sentencia_if() noexcept -> void
{
	using namespace std;

	// if ( [declaración_de_variable;] <número> )
	// {}

	if ( 0 )
		std::cout << "Esta sentencia no será mostrada" << '\n';

	// cualquier valor diferente de 0 será tomado TRUE. Ya sea entero, negativo, decimal, etc..
	if ( -2344234 )
		std::cout << "Este enunciado sí será mostrado" << '\n';

	std::cout << endl;

	// Operador !
	/* !<numero_diferente_de_cero> = 0 / false
	* !<cero> = 1 / true */

		int32_t entero_1 = 4'763;
		bool booleano_1 = !entero_1;
		cout << boolalpha << booleano_1 << endl;	// boolalpha: 	para que salga <true> o <false>
													// 				en vez de 0 y 1;
		
		// Usando la negación con std::string.
		
		struct string_wrapper {
			std::string cadena;
			bool operator!()
			{
				return cadena.empty();
			};
		};

		string_wrapper texto;
		bool boolean_text = !texto;
		cout << "boolean_texto está vacío; al negarlo obtenenos: " << boolean_text << '\n';

		texto = { "Caprichosa" };
		boolean_text = !texto;
		cout << "boolean_texto está lleno; al negarlo obtenenos: " << boolean_text << '\n';

		cout << '\n';

		//
		// Con archivos * Es importante notar que AL EJECUTARSE UN PROGRAMA EN LINA DE COMANDOS
		// 					se considera carpeta raíz a la carpeta desde donde se invoca el programa
		// 					y no donde se encuentra el archivo executable. Si se ejecuta el programa:
		// 					bin/course 8, se considera la raíz desde donde se invocó y no bin/

		ifstream archivo_que_no_existe { "texto.txt" };
		ifstream archivo_que_si_existe { "prueba_negacion.txt" };
		bool is_open_negation;

		is_open_negation = !archivo_que_no_existe;
		cout << "Hubo un problema al abrir \"text.txt\"?: " << boolalpha << is_open_negation << '\n';
		
		is_open_negation = !archivo_que_si_existe;
		cout << "Hubo un problema al abrir \"prueba_negacion.txt\"?: " << boolalpha << is_open_negation
																						<< '\n';
		cout << endl;

	// ==
	/* <numero_1> == <numero_2>
	 * A nivel máquina, solo sabe realizar sumas y restas, así que intérnamente realiza una resta
	 * para calcular la igualdad */

		bool comparing_result = 100 == 100;
		cout << "El resultado de la comparación 100 == 100 es: " << comparing_result << '\n';
	
		comparing_result = 101 == 100;
		cout << "El resultado de la comparación 101 == 100 es: " << comparing_result << '\n';
	
		array<int32_t, 1> arreglo_vacio;
		comparing_result = "gatitas hermosas"s.empty() == arreglo_vacio.empty();
		cout	<<	"El resultado de la comparación "
					"\"gatitas hermosas\"s.empty() == arreglo_vacio.empty() es: "
				<< 	comparing_result << '\n';

	std::cout << '\n';
}
	// <, <=, >, >=
void comparacion( int32_t _Valor ) noexcept
{
	// la variable inicializada se hereda a toda la estructura if
	if ( int32_t valor_al_cuadrado = _Valor * _Valor; valor_al_cuadrado > 100 )
		std::cout	<< _Valor
					<< " al cuadrado es igual a " << valor_al_cuadrado
					<< " y es mayor a 100\n";

	else if ( int32_t valor_al_cuadrado = _Valor * _Valor; valor_al_cuadrado < 100 )
		std::cout	<< _Valor
					<< " al cuadrado es igual a " << valor_al_cuadrado
					<< " y es menor a 100\n";
	else
		std::cout	<< _Valor
					<< " al cuadrado es igual a " << valor_al_cuadrado
					<< " y es igual a 100\n";
}

auto sentencia_if_2() noexcept -> void
{
	comparacion( 50 );
	comparacion( 2 );
	comparacion( 10 );
	std::cout << '\n';

	return;
}

// PARÁMETROS VARIABLES

/**
 * decltype( <variable> )
 * 
 * Permite obtener el tipo de cualquier variable, algo así como un cast a la inversa
 */

// Vamos a sobrecargar operator<<() para poder enviarle un arreglo
decltype( std::cout ) &operator<<( decltype( std::cout ) &_os, const std::array<int32_t, 3> &_Arreglo )
{
	return _os << '[' << _Arreglo[0] << ", " << _Arreglo[1] << ", " << _Arreglo[2] << ']';
}

void funcion( const auto &_Valor )
{
	std::cout	<< "El valor es: " << _Valor << " "
				<< "y el tipo es: " << typeid( _Valor ).name()
				<< "\n";
}

void parametros_variables() noexcept
{
	std::string texto = "texto";
	std::array<int32_t, 3> arreglo { 10, 20, 30 };

	funcion( 10 );
	funcion( 'L' );
	funcion( 0.0 );
	funcion( 0.0f );
	funcion( texto );
	funcion( arreglo );
	std::cout << '\n';
}

// RETORNOS VARIABLES

/*
---------------------------------------- if constexpr() --------------------------------------------------

	Como el -if- pero lo demás no solo no lo ejecuta, sino que NO LO COMPILA.
	Es parte de la COMPILACIÓN CONDICIONAL

-----------------------------------------------------------------------------------------------------------
*/

#include <cmath>
#include <numeric>

// Vamos a sobrecargar operator<<() para que el cout pueda imprimir un emoji (utf8)
decltype( std::cout ) &operator<<( decltype( std::cout ) &_os, const char8_t *_Emoji )
{
	return _os << reinterpret_cast<const char *>( _Emoji );
}

void imprimir_info( const auto &_Valor )
{
	std::cout	<< "El valor que retornó la función es: " << _Valor << " "
				<< "y es del tipo: " << typeid( _Valor ).name() << "\n\n";
}

/*
	array<>.begin() // devuelve un apuntador al primer elemento
	array<>.end()	// devuelve un apuntador a la sieguiente posición en memoria del último elemento

	typeid( <variable> ).name // devuelve una cadena con el nombre del tipo de <variable>

	std::remove_cvref_t<decltype( <tipo> ) // nos devuelve <tipo> pero sin const, volatile ni reference

	std::reduce( &array[<inicio>] *, &array[<fin + 1>] ) // devuelve la suma de los elementos de un arreglo
															desde el valor en inicio hasta el valor en fin
*/

auto funcion_de_retorno_variable( const auto &valor )
{
	// Creamos un alias del tipo de <valor> pero despulgado
	using valor_con_cvref_removido = std::remove_cvref_t<decltype( valor )>;

	// para const int & usamos el alias despulgado
	if constexpr ( std::is_integral_v<valor_con_cvref_removido> ) {
		std::cout	<< "El argumento es un ( const int & ) "
					<< "representado por: " << typeid( valor ).name() << "\n";
		return std::pow( valor, 3 );
	}
	
	// aquí usamos <valor> original, y lo comparamos con un const std::string &
	else if constexpr ( std::is_same_v<const std::string &, decltype( valor )> ) {
		std::cout	<< "El argumento es un ( const std::string & ) "
					<< "representado por: " << typeid( valor ).name() << "\n";
	 	return "Mensaje" + valor;
	}
	
	// aquí lo mismo que el anterior
	else if constexpr ( std::is_same_v< const std::array<int32_t, 3> &, decltype( valor )> ) {
		std::cout	<< "El argumento es un ( const std::array<int32_t, 3> & ) "
					<< "representado por: " << typeid( valor ).name() << "\n";
		return ( std::reduce( valor.begin(), valor.end() ) );
	}
	
	// aquí lo que no cuadre
	else {
		std::cout	<< "El argumento no coincide con nungún if constexpr "
					<< "y su tipo está representado por: " << typeid( valor ).name() << "\n";
		return u8"\U0001F603";
	}
}

void retornos_variables() noexcept
{
	std::string texto = "texto";
	std::array<int32_t, 3> arreglo { 10, 20, 30 };

	imprimir_info( funcion_de_retorno_variable( 3 ) );			// 27
	imprimir_info( funcion_de_retorno_variable( 'L' ) );		// :-)
	imprimir_info( funcion_de_retorno_variable( arreglo ) );	// 60
	imprimir_info( funcion_de_retorno_variable( 0.0 ) );		// :-)
	imprimir_info( funcion_de_retorno_variable( 0.0f ) );		// :-)
	imprimir_info( funcion_de_retorno_variable( texto ) );		// Mensaje: texto

	std::cout << '\n';
}
