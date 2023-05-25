 #pragma once
#include <string>
#include <regex>
#include <windows.h>
using namespace std;

/// <summary>
/// Clase de apoyo de metodos, contiene operaciones generalizadas
/// </summary>
class Util
{
public:
	/// <summary>
	/// Intenta convertir un string a integer
	/// </summary>
	/// <param name="integer_str">string a convertir</param>
	/// <returns>True si la conversion fue satisfactoria</returns>
	bool static integer_verifier(string string);

	/// <summary>
	/// Intenta convertir un string a float
	/// </summary>
	/// <param name="string">string a convertir</param>
	/// <returns>True si la conversion fue satisfactoria</returns>
	bool static float_verifier(string string);

	/// <summary>
	/// Verifica que la posicion de prueba que se desea cambiar es correcta, ademas valida si se recibio un int
	/// </summary>
	/// <param name="string">string a validar</param>
	/// <returns>True si es un elemento valido</returns>
	bool static mark_position_verifier(string string);

	/// <summary>
	/// Verifica que la nota ingresada es correcta, ademas valida si se recibio un float
	/// </summary>
	/// <param name="string"></param>
	/// <returns></returns>
	bool static mark_verifier(string string);

	/// <summary>
	/// Valida que el formato de rut ingresado es correcto
	/// </summary>
	/// <param name="rut">string con el rut</param>
	/// <returns>True si el formato es valido</returns>
	bool static rut_validator(string rut);

	/// <summary>
	/// Elimina los espacios en un string.
	/// </summary>
	/// <param name="message">String con palabra a des-espaciar</param>
	/// <returns>palabra sin espacios</returns>
	string static strip(string message);

	/// <summary>
	/// Transforma todos los carácteres de un string a su formato mayuscula
	/// </summary>
	/// <param name="message">String a transformar</param>
	/// <returns>String en mayuscula</returns>
	string static to_upper_case(string message);

	/// <summary>
	/// Aproxima un float segun la norma de decima respectiva
	/// </summary>
	/// <param name="value">Valor a aproxima</param>
	/// <returns>Valor aproximado</returns>
	float static approximation(float value);

	/// <summary>
	/// Aproxima un float segun la norma de decima respectiva segun el multiplicador
	/// </summary>
	/// <param name="value">Valor a aproxima</param>
	/// <param name="multiplier">exponente para el multiplicador</param>
	/// <returns>Valor aproximado</returns>
	float static approximation(float value,int multiplier);

	/// <summary>
	/// Retrasa la ejecucion del codigo mediante un temporizador
	/// </summary>
	/// <param name="seconds">Segundos a detener el programa</param>
	void static timer(int seconds);
};

