#pragma once
#include <string>
#include <algorithm>
#include <iostream>
#include "System.h"
#include <sstream>
#include <fstream>
#include "Util.h"
using namespace std;

#define PRINT(message) cout << message;
#define PRINTLN(message) cout << message<< "\n";
#define DPRINTLN(message) cout << message << endl;

/// <summary>
/// Se encarga de las impresiones por pantalla, asi como la captura de datos por teclado
/// </summary>
class UserInterface
{
private:

	#pragma region CLASS_ATRIBUTES

	System* system;

	#pragma endregion

	#pragma region UTIL_METHODS

	/// <summary>
	/// Simplifica la tarea de recibir entrada por teclado
	/// </summary>
	/// <param name="message">String con el mensaje a imprimir antes de solicitar una entrada</param>
	/// <returns></returns>
	string input(string message);
	#pragma endregion

	#pragma region CLASS_METHODS

	/// <summary>
	/// Despliega el menu principal
	/// </summary>
	void main_menu();

	/// <summary>
	/// Agrega los alumnos con pruebas pendientes al sistema
	/// </summary>
	void load_data();

	/// <summary>
	/// Lee la informacion contenida en el archivo txt
	/// </summary>
	void read_students_file();

	/// <summary>
	/// Permite cambiar la nota de algun estudiante
	/// </summary>
	void change_mark();

	/// <summary>
	/// Despliega el menu de estadisticas
	/// </summary>
	void get_statistics();

	/// <summary>
	/// Despliega el menu de estadisticas 
	/// </summary>
	void statistics_menu();

	/// <summary>
	/// Verifica que la carga de datos fue realizada previamente
	/// </summary>
	/// <returns>True si fue realizada</returns>
	bool load_data_verifier();

	/// <summary>
	/// Imprime los estudiantes que tenga reprobado taller, segun su paralelo
	/// </summary>
	void project_disapproved_students();

	/// <summary>
	/// Imprime el porcentaje estudiantes que estan reprobando la asignatura
	/// </summary>
	void non_approved_students();

	/// <summary>
	/// Imprime el desempeño final de cada alumno.
	/// </summary>
	void final_score_students();

	/// <summary>
	/// Despliega un mensaje de aviso que regreso al menu principal
	/// </summary>
	void back_to_main_menu();

	/// <summary>
	/// Filtra de la matriz a todos los alumnos que reprobaron por taller
	/// </summary>
	void matrix_filter();

	/// <summary>
	/// Imprime ordenadamente los alumnos contenidos en el sistema
	/// </summary>
	void print_matrix();

	/// <summary>
	/// Guarda los datos y cierra el sistema
	/// </summary>
	void shutdown();

	/// <summary>
	/// Escribe la informacion en un archivo txt
	/// </summary>
	void save_data();

	#pragma endregion

public:
	/// <summary>
	/// Constructor
	/// </summary>
	UserInterface();
	/// <summary>
	/// Destructor
	/// </summary>
	~UserInterface() = default;
	/// <summary>
	/// Inicializa el programa
	/// </summary>
	void initialization();
};

