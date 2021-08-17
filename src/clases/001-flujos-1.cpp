#include <iostream>

void estandares_CPP()
{
/*
	Estándares de C++
	=================

	C++98	(C++ Clasico)
	C++11	(C++ moderno)
	C++14
	C++17
	C++20
*/
}

void archivos_escritura_lectura()
{
/*	-----------------------------------------------------------------------------
		ARCHIVOS DE ESCRITURA
		=====================

		( ANSI )					( UTF-16 )
	
		std::cout					std::wcout
		std::clog					std::wclog		(c/buffer)
		std::cerr					std::wcerr		(s/buffer)

 		* En Windows: 	std::clog "funciona como" std::cout
		* 				std::wclog "funciona como" std::wcout

		ARCHIVOS DE LECTURA
		===================

		( ANSI )					(UTF-16)
		std::cin					std::wcin
*/
}

void cout_y_operator()
{
/*
	------------------------------ std::cout -------------------------------------------------

	std::cout.operator<<( int ) // Imprime un entero. Devuelve std::cout

	std::cout.operator<<( "Texto" ) // Imprime un texto. Devuelve std::cout

	std::cout.operator<<( std::ostream & )	// Recibe el std::ostream &
											// pero parece que no hace ni verga

	std::cout.write( "Texto", numero_de_caracteres ) // Imprime un texto. Devuelve std::cout.

	std::cout.put( '\n' ) // Impime un caracter, supongo que también regresa std::cout

	------------------------------------------------------------------------------------------
	*/
	std::cout.operator<<( 10 )
			 .operator<<( 20.3 )
			 .write( "Hola Mundo", 10 )
			 .operator<<( 20 )
			 .write( "\n", 1 );

	/*
	---------------------------------- std::operator ------------------------------------------

	std::operator<<( std::cout, "Texto") // Imprime un texto. Regresa std::cout

	------------------------------------------------------------------------------------------

	---------------------------------- std::endl ------------------------------------------

	std::ostream &endl( std::ostream &os )
	{
		os.put( os.wide( '\n' ) );
		os.flush();

		return os;
	}
	------------------------------------------------------------------------------------------
	*/

	// el std::endl se puede usar como función que recibe el std::ostream & ...
	std::endl( std::operator<<( std::cout.operator<<( 10 )
										 .operator<<( 20.3 )
										 .operator<<( 20 ), ", Hola Mundo" ) );

	// o como una variable que se comporta como función ( apuntador a variable )
	// de la forma int32_t( *main_ptr )() = main; ...
	std::cout.operator<<( "Hola de nuevo " ).operator<<( std::endl );


	// TESTING: Transformar la siguiente línea en forma completa
	std::cout << "El valor numerico es: " << 10 << ". Hay " << 159 << " estudiantes" << std::endl;
	
	std::endl(
	std::operator<<(
	std::operator<<(
	std::operator<<( std::cout, "El valor numerico es: " )
					.operator<<( 10 ), ". Hay " )
					.operator<<( 159 ), " estudiantes ") );

}

void tipos_de_caracteres_y_cadenas()
{
	// Nativo Show
	char c;				std::string s;			std::string_view sv;			//	   ''	   ""
	signed char sc;																//	   ''	   ""
	unsigned char uc;															//	   ''	   ""

	// Seudónimos
	char8_t u8c;		std::u8string u8s;		std::u8string_view u8sv;		//	 u8''	 u8""
	char16_t u16c;		std::u16string u16s;	std::u16string_view u16sv;		//	  u''	  u""
	char32_t u32c;		std::u32string u32s;	std::u32string_view u32sv;		//	  U''	  U""
	wchar_t wc;			std::wstring ws;		std::wstring_view wsv;			//	  L''	  L""
	// (macOS & Linux: wchar_t <=> char_32_t / Windows: wchar_t <=> char16_t)

	// Ejemplos

		char letra_ansi = 'T';
		char8_t letra_utf8 = u8'T';
		char16_t letra_utf16 = u'T';
		char32_t letra_utf32 = U'T';
		wchar_t letra_extendida = L'T';

	//-------------------------- TEXTO MULTILINEA ----------------------------------------//

	// R"etiqueta( Texto )etiqueta"

		std::cout << R"texto_multilinea(
			Sólo este contenido es el que se va a ver
		)texto_multilinea" << '\n';


								//// MARIO TEXT ART /////

	// utf-8 puede ser almacenado en un tipo ANSI y salir por std::cout porque son de 1 byte
	// Antes de C++17 no existía char8_t y el utf-8 se almacenaba en char.
	// Por lo tanto, un texto utf-8 es interpretado como ANSI a menos que se indique lo contrario

	std::cout <<
		#include "../../txt/mario-utf8.txt"
	;

	std::string marioANSI =
		#include "../../txt/mario-utf8.txt"
	;
	std::cout << marioANSI << std::endl;

	// se especifica que es utf8 y debe se casteado, pero igual sale
	std::u8string marioUTF8 =
		#include "../../txt/u8_mario-utf8.txt"
	;
	std::cout << (const char *)marioUTF8.data() << std::endl;

	// cuando excede los 8 bits, ya no puede ser interpretado como ANSI ni metido a std::cout
	/*
	marioUTF8 =
		#include "../txt/u8_mario-utf16.txt"
	;
	//std::cout << (const char *)marioUTF8.data() << std::endl;
	*/

	/*
	std::u16string marioUTF16 =
		#include "../txt/u_mario-utf16.txt"
	;
	// std::cout << (const char *)marioTextArt.data() << std::endl;
	*/

	// Los caracteres japoneses caben perféctamente en un std::string y salen por std::cout
	std::string cadena_japonesa_ANSI( "こんにちは私はc ++です" );
	std::cout << cadena_japonesa_ANSI << std::endl;

	// UTF-8 -> std::u8string
	std::u8string cadena_japonesa_UTF8( u8"こんにちは私はc ++です" );
	std::cout << (const char *)cadena_japonesa_UTF8.data() << std::endl;

}

void tipos_numericos() noexcept
{
/*								ENTEROS

	Nativos

		int (signed int)				unsigned int
		short (signed short)			unsigned short int
		long (signed long)				unsigned long int (*nix: 64 bits | Windows: 32 bits )
		long long (signed long long)	unsigned long long int

	Pseudónimos

		int8_t							uint8_t
		int16_t							uint16_t
		int32_t							uint32_t
		int64_t							uint64_t
		intptr_t						uintptr_t (depende de arquitectura - 32 o 64 bit)


								REALES

	Nativos

		float
		double
		long double (no tiene alias)
	
	Pseudónimos

		float_t
		double_t


								ESPECIALES

		bool
		nullptr
		void *


						Tipos de dato de usuario
	
		enum
		enum class
		enum struct
		struct
		class
		union

*/
		int8_t entero_8bits = 10;
		int16_t entero_16bits = 10;
		int32_t entero_32bits = 10;
		int64_t entero_64bits = 10;

}
