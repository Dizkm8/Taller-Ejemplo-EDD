#pragma once
#include <string>
#include "SparseMatrix.h"
#include "Util.h"
using namespace std;

/// <summary>
/// Clases sistema del programa, contiene todos los algoritmos para los requerimientos
/// </summary>
class System
{
private:
	SparseMatrix* backup_matrix;
	SparseMatrix* system_matrix;
	SparseMatrix* deleted_matrix;
	string code;

public:
	/// <summary>
	/// Constructor Basico
	/// </summary>
	System();
	/// <summary>
	/// Destructor Basico
	/// </summary>
	~System() = default;
	/// <summary>
	/// Inicializa las matrices del sistema
	/// </summary>
	void initialization();
	/// <summary>
	/// Agrega un estudiante al sistema
	/// </summary>
	/// <param name="fullname">Nombre del estudiante</param>
	/// <param name="rut">Rut del estudiante</param>
	/// <param name="marks">Notas del estudiante</param>
	/// <param name="class_id">Paralelo del estudiante</param>
	/// <param name="project_status">Estado de aprobacion de taller del estudiante</param>
	/// <param name="list_number">Numero de lista del estudiante</param>
	void add_student(string fullname,string rut,float* marks,int class_id,
		bool project_status,int list_number);
	bool enter_mark(float mark,int mark_position,string student_rut);
	/// <summary>
	/// Obtiene los alumnos que No aprobaron taller por paralelo
	/// </summary>
	/// <returns>Retorna vector, en [n] contiene el numero de paralelo y en [n+1] la cantidad, con n Par</returns>
	int* project_disapproved_students();
	/// <summary>
	/// Obtiene el porcentaje de estudiantes que esta reprobando la asignatura
	/// </summary>
	/// <returns>float con el porcentaje</returns>
	float non_approved_students_system_matrix();
	/// <summary>
	/// Obtiene el porcentaje de estudiantes que esta reprobando la asignatura ANTES de cualquier cambio en las notas
	/// </summary>
	/// <returns>float con el porcentaje</returns>
	float non_approved_students_backup_matrix();
	/// <summary>
	/// Obtiene la calificacion final y si aprueba la asignatura
	/// </summary>
	/// <returns>string con la Informacion de los estudiantes</returns>
	string* final_score_students_system_matrix();
	/// <summary>
	/// Obtiene la calificacion final y si aprueba la asignatura ANTES  de hacer cambios en las notas
	/// </summary>
	/// <returns>string con la Informacion de los estudiantes</returns>
	string* final_score_students_backup_matrix();
	/// <summary>
	/// Filtra a los estudiantes que NO aprobaron por Taller
	/// </summary>
	void matrix_filter();
	/// <summary>
	/// Ordena todos los elementos del sistema
	/// </summary>
	/// <returns>Matriz de string con los elementos del sistema</returns>
	string** get_printed_system_matrix();
	/// <summary>
	/// Ordena todos los elementos del sistema
	/// </summary>
	/// <returns>Matriz de string con los elementos del sistema</returns>
	string** get_printed_deleted_matrix();
	/// <summary>
	/// Obtiene la informacion de todos los alumnos del sistema
	/// </summary>
	/// <returns>Puntero Vector string</returns>
	string* get_all_students_info();
	/// <summary>
	/// Obtiene el estado de creacion de la matriz inicial del sistema
	/// </summary>
	/// <returns>True si la matriz SI está inicializada</returns>
	bool matrix_exists() { return backup_matrix != nullptr; }
	/// <summary>
	/// Obtiene el codigo del curso
	/// </summary>
	/// <returns>string con el codigo</returns>
	string get_code() { return this->code; }
	/// <summary>
	/// Establece un nuevo codigo de curso
	/// </summary>
	/// <param name="code">string con el nuevo codigo</param>
	void set_code(string code) { this->code = code; }

};