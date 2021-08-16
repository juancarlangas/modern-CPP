#pragma once

#define NUMERO_DE_CLASES 8

// 001
	void estandares_CPP();
	void archivos_escritura_lectura();
	void cout_y_operator();
	void tipos_de_caracteres_y_cadenas();
	void tipos_numericos() noexcept;

// 002-flujos-2.cpp
	void desarrollo_de_software();
	void buffers();

// 003-namespaces.cpp
	void ambitos();
	void namespace_basico();
	void namespace_inline();
	void namespace_alias();
	void namespace_abreviado();
	void binario_y_desplazamiento();

// 004-funciones-1.cpp
	void estados();
	void categorias();
	void alias();
	void alias_como_parametros();
	void apuntadores_y_alias_a_funciones();

// 005-funciones-2.cpp
	void variables_runtime_y_compiletime();
	void funciones_runtime_y_compiletime();
	void pre_y_post_incremento();
	void prueba_de_rendimiento();

// 006-define.cpp
	void define();
	void bloques_de_codigo();
	void macros_de_bloque();
	void macros_de_plantilla();
	void multilinea();
	void varios_archivos();
	void compilacion_condicional();
	extern void funcion_publica();
	static void funcion_privada();
	void tipos_de_identificadores();

// 007 - condicionales.cpp
	void expresiones();
	void corto_circuito();
	void if_nueva_sintaxis();
	void if_constexpr();
	void declare_type();
	void enumeraciones();
	void enumeraciones_con_ambito();

// 008 - string_view (clase repuesta)
	void palabra_string_view() noexcept;
	auto sentencia_if() noexcept -> void;
	auto sentencia_if_2() noexcept -> void;
	void parametros_variables() noexcept;
	void retornos_variables() noexcept;

// 008-2-atributos.cpp
    void atributo_noreturn();
    void atributo_deprecated() noexcept;
    void atributo_no_unique_adress() noexcept;
    void atributo_maybe_unused() noexcept;
    void atributos_de_switch() noexcept;

// 008-2-1-enumeraciones.cpp
    void enumeracion_sin_ambito() noexcept;
    void enumeracion_con_ambito() noexcept;

// 008-2-2-switch.cpp
    void estructura_switch() noexcept;

// 008-3-0-arreglos.cpp
    void clase_array() noexcept;
