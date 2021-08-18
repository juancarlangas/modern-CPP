#include <cstdlib>
#include <iostream>
#include <functional>
#include <array>
#include "clases/temas.hpp"

int32_t main( int argc, const char *argv[] )
{
	switch (atoi(argv[1])) {
		case 1:
			estandares_CPP();
			archivos_escritura_lectura();
			cout_y_operator();
			tipos_de_caracteres_y_cadenas();
			tipos_numericos();
			break;
		case 2:
			desarrollo_de_software();
			buffers();
			break;
		case 3:
			ambitos();
			namespace_basico();
			namespace_inline();
			namespace_alias();
			namespace_abreviado();
			binario_y_desplazamiento();
			break;
		case 4:
			estados();
			categorias();
			alias();
			alias_como_parametros();
			apuntadores_y_alias_a_funciones();
			break;
		case 5:
			variables_runtime_y_compiletime();
			funciones_runtime_y_compiletime();
			pre_y_post_incremento();
			prueba_de_rendimiento();
			break;
		case 6:
			define();
			bloques_de_codigo();
			macros_de_bloque();
            macros_de_plantilla();
			varios_archivos();
			compilacion_condicional();
			funcion_publica();
			// funcion_privada(); // <- No se puede usar porque es privada
            tipos_de_identificadores();
			break;
		case 7:
			expresiones();
			corto_circuito();
			if_nueva_sintaxis();
			if_constexpr();
			declare_type();
			enumeraciones();
			enumeraciones_con_ambito();
			break;

		case 8:
			// 008 - string_view (clase repuesta)
			palabra_string_view();
			sentencia_if();
			sentencia_if_2();
			parametros_variables();
			retornos_variables();

			// 008-2-atributos.cpp
			atributo_noreturn();
			atributo_deprecated();
			atributo_no_unique_adress();
			atributo_maybe_unused();
			atributos_de_switch();

			// 008-2-1-enumeraciones.cpp
			enumeracion_sin_ambito();
			enumeracion_con_ambito();

			// 008-2-2-switch.cpp
			estructura_switch();

			// 008-3-0-arreglos.cpp
			clase_array();

			break;
	}

	return EXIT_SUCCESS; // en realidad estas variables forman parte de la biblioteca
						// pero a la computadora le viene valiendo verguísima cuál le mandes.
						// Es el usuario quien debe saber qué significa cada cosa.
							EXIT_SUCCESS; // 0
							EXIT_FAILURE; // 1
}
