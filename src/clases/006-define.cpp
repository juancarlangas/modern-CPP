// CLASE 6: #define

// Las líneas que empiezan con signo gato ("#") son DIRECTIVAS DE PREPROCESADOR
// Ninguna formará parte del código preprocesado
#include <bits/stdint-intn.h>
#include <cstdio>
#include <iostream>
#include <ostream>
#include <string>

using namespace std;

//--------------------------- #define (Directivas de sustitución) --------------------------------
// #define <identificador> <lo que se va a sustituir>
//-----------------------------------------------------------------------------------------------

// Palabras
#define SIN_REGRESO void
#define NOMBRE_DE_FUNCION define
#define LK {
#define RK }
#define ESCRIBIR std::cout <<
#define FIN_DE_LINEA << std::endl
#define RETORNAR return

SIN_REGRESO NOMBRE_DE_FUNCION()
LK
    ESCRIBIR "Esto se imprimió usando #define" FIN_DE_LINEA;

    RETORNAR;
RK

//--------------------------- #define (Sustitución de BLOQUES) --------------------------------
// #define <identificador> 	\
// 		<linea de texto>	\
// 		.					\
// 		.					\
// 		<linea de texto>
//-----------------------------------------------------------------------------------------------

#define BLOQUE_DE_CODIGO				\
{										\
	int32_t var = 10;					\
	std::cout << var++ << std::endl;	\
	std::cout << var++ << std::endl;	\
	std::cout << var++ << std::endl;	\
	std::cout << var++ << std::endl;	\
	std::cout << var++ << std::endl;	\
	std::cout << std::endl;				\
}

void bloques_de_codigo()
{
	BLOQUE_DE_CODIGO
	BLOQUE_DE_CODIGO
	BLOQUE_DE_CODIGO
}

//--------------------------------- Define (Macros) -------------------------------------------
// #define <identificador>( <argumentos>... ) <lo que se va a sustituir>
// ---------------------------------------------------------------------------------------------

#define MACRO_DE_BLOQUE( valor )		\
{										\
	int32_t var = valor;				\
	std::cout << var++ << std::endl;	\
	std::cout << var++ << std::endl;	\
	std::cout << var++ << std::endl;	\
	std::cout << var++ << std::endl;	\
	std::cout << var++ << std::endl;	\
	std::cout << std::endl;				\
}

void macros_de_bloque()
{
	MACRO_DE_BLOQUE( 10 )
	MACRO_DE_BLOQUE( 100 )
	MACRO_DE_BLOQUE( 1'000 )
}

// PLantillas
// Token: Conjunto contiguo de caracteres. Cada palabra individual
	int32_t palabra;	// <- int32: token	|	palabra: token

// Operador ## - Concatenador de tokens.

#define GENERAR_TIPO( size_bits )	\
struct Entero_ ## size_bits {		\
	int ## size_bits ## _t variable;\
};									\

void macros_de_plantilla()
{
	GENERAR_TIPO( 8 )
	GENERAR_TIPO( 16 )
	GENERAR_TIPO( 32 )
	GENERAR_TIPO( 64 )

	Entero_32 entero_32;
	Entero_64 entero_64;
}

/////////////////////////////////// USO DE VARIOS ARCHIVOS ////////////////////////////////////////
// (Las comillas nos permiten separar una cadena en varias líneas)
	string cadena = "Hola "
					"grandísimo imbecil";

// (El símbolo '\' nos permite separar un token en varias líneas - sin sangría)
	string werwfsdfwer\
werwerhjwerwerwrwkjerh\
wekrjwherkwjrwkrjwekrw = "Qué nombre tan largo";

// Estructura Básica de un proyecto

//	/ Programa
//		/ include -- definiciones h o headers, declaraciones (.h, .hpp, .hxx)
//			/ Redes
//			/ UI
//			/ Utilería
//		/ src -- definiciones (.cpp)
//			/ Redes
//			/ UI
//			/ Utilería

#include <ctype.h>	// "<>" significa que el archivo está en la misma carpeta que el compilador
#include "../include/misFuncionesMatematicas.hpp" 	// "" significa que partes de la carpeta
													// del actual .cpp o .hpp

// Operador # -> Transforma valor numerico en una cadena dentro de una definición o macro
#define SHOW_SUMA( v1, v2 ) cout << #v1 " + " #v2 " = " << sumar( v1, v2 ) << "\n";

void varios_archivos()
{
	SHOW_SUMA( 10, 20 )
	SHOW_SUMA( 20, 40 )
	SHOW_SUMA( 100, 200 )
	SHOW_SUMA( 1000, 2000 )
}

////////////////////////////// #if (Compilación condicional) ////////////////////////////// 
//
//#if <numero o identificador definido como un número (cero o no cero)>
//-> sepuede usar la función defined( <numero o identificador> ) dentro de #if
//

#define RELEASE_1

#define BANDERA( logic, number ) cout << #logic " existe RELEASE_" #number << endl;

void compilacion_condicional()
{
	cout << "\n";

#if defined( RELEASE_1 )
	BANDERA( Sí, 1 )
#endif

#if RELEASE_2
	BANDERA( Sí, 2 )
#endif

#if !defined( RELEASE_2 ) // equivalente a #ifndef <identificador>
	BANDERA( No, 2 )
#endif

}

// podemos incluir varias veces el mismo archivo pues está protegido por #ifndef
#include "../include/misFuncionesMatematicas.hpp"
#include "../include/misFuncionesMatematicas.hpp"
#include "../include/misFuncionesMatematicas.hpp"
#include "../include/misFuncionesMatematicas.hpp"

// #pragma once	<- Versión moderna: funciona igual que meter #ifndef, #define y #endif

////////////////////////////// NIVELES DE ACCESO ////////////////////////////////////////
// o Alcance

// static <- privado
static void funcion_privada()
{}

// extern <- público (default)
extern void funcion_publica() 
{}

void niveles_de_acceso()
{
	// uso de una función estática pero incluida en el archivo de cabecera
		cout << "Función externa para sumar 20 + 40 " << sumar( 20, 40 ) << "\n";

	// También usamos -extern- para declarar una variable o función de otro ámbito o archivo
	// dentro del mismo archivo donde está la función llamadora

	// definidas en .cpp
		extern int32_t restar_publica( const int _valor1, const int _valor2 ) noexcept;
		extern int32_t restar_privada( const int _valor1, const int _valor2 ) noexcept;

	// sí funciona
		cout << "Función publica para 10 - 100: " << restar_publica( 10, 100 ) << "\n";

	// no funciona
	// 	cout << "Función privada para 10 - 100: " << restar_privada( 10, 100 ) << "\n";
	
	//	También para declarar variables que estarán fuera de un ámbito
		extern string cadena_externa;
		cout << cadena_externa << "\n";
}

string cadena_externa{ "Esto es un texto muy, pero muy largo" };

////////////////////////////// TIPOS DE IDENTIFICADORES /////////////////////////////////////// 
void tipos_de_identificadores()
{
    int32_t
        v1,         // variable
        &v2 = v1,   // referencia
        *v3 = &v2,  // apuntador
        v4[10],     // arreglo
        **v5,       // doble apuntador
        *&v6 = v3,  // referencia a un apuntador
        ( *v7 )();  // apuntador a una función
}
