#include <bits/stdint-intn.h>
#include <cstdlib>
#include <iostream>
#include <chrono>
#include <utility>
#include <array>

////////////////////////////// RUN-TIME y COMPILE-TIME //////////////////////////////////////

//								-- Variables --

void variables_runtime_y_compiletime()
{/*
	
	----------------------------------------------------------------------------------------*/
	// Run-time
		int32_t variable_entera_runtime = 10;
		const int32_t constante_entera_runtime = 10; // en C: se usa <readonly>

	// Compile-time --constexpr-- (Datos "quemados", "cableados", "hardcodeados")
		constexpr int32_t variable_entera_compiletime = 10;
		constexpr const int32_t constante_entera_compiletime = 10;
		constexpr const char cadena_quemada[] = "Que tranza wero?"; /*
	 	*en C usamos --const-- 
	------------------------------------------------------------------------------------------*/

	// para dimensionar, utilizamos siempre un compile-time
	constexpr int32_t size_compiletime = 10;
	std::array<int32_t, size_compiletime> arreglo; /*

	*al asignar un compile-time a una variable const, se comporta como compile-time
		const <tipo> <nombre> = <variable_runtime> 	-> RUNTIME
		const <tipo> <nombre> = <cariable_comptime>	-> COMPILE TIME */

	const int size_runtime_1 = 20;
	std::array<int32_t, size_runtime_1> arreglo_2; // <- Correcto
	
	int32_t valor_runtime = 30;
	const int32_t size_runtime_2 = valor_runtime; // asignando un runtime a un --const--
	// array<int32_t, size_runtime_2> arreglo_3; <- ERROR

	int32_t arreglo_4[size_runtime_2];	/* <-	Por caracteríastica de C 'variable length array'
												en arreglos clásicos Sí se admite */
												
}

//									-- Funciones --

// Funciones RUNTIME
int32_t get_value_in_runtime() noexcept
{
	return 30;
}

int32_t sumar_en_runtime(const int32_t _val_1, const int32_t _val_2) noexcept
{
	return _val_1 + _val_2;
}

// Funciones COMPILE_TIME
consteval inline int32_t get_value_in_compiletime() noexcept
{
	return 30;
}

consteval int32_t sumar_en_compiletime(const int32_t _val_1, const int32_t _val_2) noexcept
{
	return _val_1 + _val_2;
}

// Funciones híbridas
constexpr inline int32_t get_value_in_rumtime_or_compiletime() noexcept
{
	if constexpr( std::is_constant_evaluated() )
		return 100; // compiletime
	else
		return 200; // runtime
}

void funciones_runtime_y_compiletime()
{
	// runtime
	int32_t valor_de_prueba = get_value_in_runtime();

	// compiletime
	std::array<int32_t, get_value_in_compiletime()> arreglo_de_prueba;

	switch( 15 ) {
		case get_value_in_compiletime():
			break;
		default:
			break;
	}

	// Híbridas
	int32_t entero_prueba_híbrida; // se declara para forzar runtime. NOTA: gcc no la está armando
	entero_prueba_híbrida = get_value_in_rumtime_or_compiletime();
	std::cout << entero_prueba_híbrida << "\n";

	std::cout << get_value_in_rumtime_or_compiletime() << std::endl; // se evalúa como compile-time

	std::array<int32_t, get_value_in_rumtime_or_compiletime()> arreglo_super_prueba;

	switch( 15 ) {
		case get_value_in_rumtime_or_compiletime():
			break;
		default:
			break;
	}

	// OTRO EJEMPLO DE RUNTIME VS COMPILE_TIME
	sumar_en_runtime( 10, 20 );
	sumar_en_compiletime( 10, 20 );	// <- 	Esta siempre SERÁ MÁS RÁPIDA puesto que 
									//		para la ejecición ya estará calculada
}

////////////////////////////// PREINCREMENTO Y POSTINCREMENTO ///////////////////////////////
void pre_y_post_incremento()
{
	int32_t var = 0;

	// postincremento++ <- regresa una copia del valor sin incrementar (r-value)
	const int32_t &var_alias = var++;

	// ++preincremento <- regresa una referencia al valor original ya incrementado (l-value)
	int32_t &var_alias_2 = ++var;
}

////////////////////////////// PRUEBA DE RENDIMIENTO ////////////////////////////////////////
class Timer {
public:
	Timer() noexcept : m_StartTimePoint{ std::chrono::high_resolution_clock::now() }
	{}

	~Timer() noexcept
	{
		stop();
	}

	void stop() noexcept
	{
		auto end_time_point{ std::chrono::high_resolution_clock::now() };
		auto start{ std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimePoint).time_since_epoch() };
		auto end{ std::chrono::time_point_cast<std::chrono::microseconds>(end_time_point).time_since_epoch() };
		auto duracion_micro{ end - start };
		auto duracion_mili{ duracion_micro.count() * 0.001 };

		std::cout << duracion_mili << "[ms]\n";
	}

private:
	std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimePoint;
};	

void prueba_de_rendimiento()
{
	using namespace std;

	{
		cout << "Prueba de rendimiento i++" << endl;
		int32_t acumulador{ };
		Timer timer;

		for ( int32_t i = 0; i < 1'000'000; i++ )
			acumulador += 2;

		cout << "Acumulador: " << acumulador << endl;
	}

	{
		cout << "Prueba de rendimiento ++i" << endl;
		int32_t acumulador{ };
		Timer timer;

		for ( int32_t i = 0; i < 1'000'000; i++ )
			acumulador += 2;

		cout << "Acumulador: " << acumulador << endl;
	}
}
