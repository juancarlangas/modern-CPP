#include <iostream>
#include <fstream>
#include <string>
#include <string_view>

void desarrollo_de_software()
{
	setlocale( LC_ALL, "es-MX.utf8" ); // Codificación local

	/* PASOS EN EL DESARROLLO DE SOFTWARE

	1.	Edición -> Código fuente
	2.	Preprocesamiento -> Código completo
	3.	Ensamblado -> Código assembly
	4.	Compilación -> Código objeto
	5.	Enlazado -> Programa ejecutable
	*/
}

void buffers()
{
	/*--------------------------------------- std::cout ----------------------------------------

	std::cout.rdbuf()							 // Devuelve el buffer de std::cout
	std::cout.rdbuf( std::streambuf *<archivo> ) // Asigna un nuevo buffer a std::cout
													devolviendo el que tenía

	-------------------------------------------------------------------------------------------*/
	
	std::ofstream archivo{ "archivo.txt" }; // creamos un archivo
	std::streambuf *temp_buffer = std::cout.rdbuf(); // respaldamos el buffer de std::cout
	std::cout.rdbuf( archivo.rdbuf() ); // le asignamos a std::cout el buffer de archivo
	
    // lo que en un solo paso sería igual a:
	//	std::streambuf *temp_buffer = std::cout.rdbuf( archivo.rdbuf() );

	// Usando nuestro std::cout con el nuevo buffer
	std::cout << "Esta madrola aparecerá en el archivo" << std::endl;
	std::cout << "Esto también: áéíóú" << std::endl;

	// ahora con std::cout.write() y utf-8 ...
	std::u8string texto( u8"áéíóú\x0D\x0D" );
	std::cout.write( (const char *)texto.data(),
					texto.length() * sizeof( char8_t ) );

	// EJEMPLO DE EMOTICONS
	// ( los caracteres de escape no se combinan con texto multilinea
	// por lo tanto, debemos de incluirlos en una sola linea )

	// asignamos las caritas vomitando. con u8 se interpreta el texto en utf-8 y pasa a u8string
	std::u8string emoticones( u8"\U0001F92E \U0001F92E \U0001F92E \U0001F92E \U0001F92E \x0D" );

	// le añadimos la familia
	emoticones
		+= u8"\U0001F468\U0000200D\U0001F468\U0000200D\U0001F467\U0000200D\U0001F466 \x0DD \x0D";

	// le añadimos el zigo
	emoticones += u8"Si̫̾l͓̦̻̲̞͕͂ͭͬ̉̐̊v̭̘̫͇̼͙̤ë́͌̈̈́̐ͦs̋̐tr̅̒ͫ̑̎ė̱̙̔ ̙̯̟̼̔̏̃ͥS̯̳ͥ̓a̩̳͙n̙̺̯̣̼͖͋ͥ̓̾ͩ̇ ̜̤̩͍̯̈́̏͗̄̂G͕̹̤̲͚͐̉̑ͬͯe͌͆̊ͦ͑ͮ̚rm̖̹̮͂̇̄å̗̩̠̱̭͔̠ͦ͗ͭ͂͆͌n \x0D\x0D";

	// imprimimos con std::cout.write() ...
	std::cout.write( ( const char * )emoticones.data(), sizeof( char8_t ) * emoticones.length() );

	// Imprimimos con std::cout <<
	std::cout << (const char *)emoticones.data();

	// Al final le devolvemos a std::cout su buffer original
	std::cout.rdbuf( temp_buffer );

	/* Por ahora dejamos pendiente esta última parte debido a que no hemos podido hacer
	 * que funcione en GNU */

	// CREAR NUESTRO BUFFER
/*
		std::filebuf mi_buffer{ stdout };
		std::ostream miCout{ &mi_buffer };
	
		miCout << "Hola amiguitos";
*/
}
