#include <bits/stdint-intn.h>
#include <iostream>
#include <fstream>
#include <string>
#include <string_view>
#include <bitset> // para impresión en números binarios


/*--------------------------------------- ÁMBITOS -----------------------------------------------*/

int32_t var1; // variable de ÁMBITO GLOBAL

void ambitos()
{
	// ::	operador de resolución de ámbito. Toda variable que pertenece al ámbito global
	//		también lo lleva
	::setlocale( LC_ALL, "es-MX.utf8" );

	// Cada -var1- tiene su propio ámbito
	int32_t var1;
	{
		int32_t var1;
		{
			int32_t var1;

			var1 = 10;		// local
							// ni idea cómo acceder a la de enmedio
			::var1 = 10;	// global
		}
	}
}

/*----------------------------- NAMESPACES BÁSICOS -----------------------------------------------*/
namespace MiEspacioDeNombres
{
	int32_t var2 = 0;
	int32_t var3 = 0;
	void funcion()
	{}
}

int32_t var2;	// variable global con mismo nombre que en MiEspacioDeNombres

void namespace_basico()
{
	int32_t MiEspacioDeNombres; // una variable local con el mismo nombre no choca por no llevar ::

	// Accediendo a las variables
	::MiEspacioDeNombres::var3 = 32;
	::MiEspacioDeNombres::funcion();

	using namespace MiEspacioDeNombres;	// los using se recomiendan declararlos LOCALMENTE

	// accediendo sin namespace::
	var3 = 50;
	funcion();

	// var 2 debe referenciar su namespace al haber versión global y versión en namespace
	::var2 = 10;
	::MiEspacioDeNombres::var2 = 10;

	// usings especificos : también áltamente recomendable
	using std::cout;
	using std::endl;
	using std::bitset;

	// accediendo a ellos
	cout << "Mensaje" << endl;
	endl( cout.put( 'T' ) );
}

/*----------------------------- NAMESPACES INLINE -----------------------------------------------*/
// Útil para versionar nuestro código

namespace RegistroEstudiantil
{
	namespace V1
	{
		// Implementación del 2011
		void registrar_alumno()
		{}

		void constultar_notas()
		{}
	}
	inline namespace V2 // se consifera la oficial, la ACTUAL, y no requerirá ::V2
	{
		// Implementación del 2015
		void registrar_alumno()
		{}

		void constultar_notas()
		{}
	}
}

void namespace_inline()
{
	::RegistroEstudiantil::V1::constultar_notas(); 	// se referirá a la de 2011
	::RegistroEstudiantil::constultar_notas();		// en automático se referirá a la de 2015
}

/*----------------------------- ALIAS DE NAMESPACES -----------------------------------------------*/
namespace RegistroEstudiantil
{
	namespace Consultas
	{
		namespace Universitarias
		{
			namespace Grado1
			{
				void ver_registros() // perrazera de intrincado
				{}
			}
		}
	}
}

// definimos un nuevo namespace derivado de ::RegistroEstudiantil.
// Estos tipos de definiciones llevan punto y coma
namespace ConsultasGrado1 = ::RegistroEstudiantil::Consultas::Universitarias::Grado1;

void namespace_alias()
{
	::ConsultasGrado1::ver_registros();	// se accede directo
}

/*----------------------------- NAMESPACES ABREVIADOS --------------------------------------------*/

namespace Dios::VidaEspectacular::Gracias_a_Dios::TeAmo
{
	void Amen()
	{}
}

namespace GraciasDios = Dios::VidaEspectacular::Gracias_a_Dios::TeAmo;

void namespace_abreviado()
{
	::GraciasDios::Amen();	// se accede a una función declarada en modo abrebiado
}


/*----------------------------- DESPLAZAMIENTO -----------------------------------------------*/

// IMpresión en binario
// bitset<numero_de_bits>( numero_a_convertir )

using std::cout;
using std::bitset;
using std::endl;

void binario_y_desplazamiento()
{
	cout << "El número 10 en binario a 32 bits es: " << bitset<32>( 10 ) << endl;
	cout << "Y desplazado 12 a la izquierda es: " << ( bitset<32>( 10 ) << 12 ) << endl;
}
