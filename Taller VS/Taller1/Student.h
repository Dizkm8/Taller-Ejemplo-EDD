#pragma once
#include <string>
using namespace std;

/// <summary>
/// Permite generar instancias de estudiantes del sistema
/// </summary>
class Student
{
private:
	string full_name;
	string rut;
	float* marks;
	int class_id;
	bool project_status;
	int list_number;

public:
	/// <summary>
	/// Constructor
	/// </summary>
	Student();
	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="full_name">Nombre del estudiante</param>
	/// <param name="rut">Rut del estudiante</param>
	/// <param name="marks">Notas del estudiante</param>
	/// <param name="class_id">Paralelo del estudiante</param>
	/// <param name="project_status">Estado de aprobacion del taller del estudiante</param>
	/// <param name="list_number">Numero de lista</param>
	Student(string full_name,string rut,float* marks,
		int class_id,bool project_status,int list_number);
	/// <summary>
	/// Destructor basico
	/// </summary>
	~Student();

	#pragma region getters_and_setters
	/// <summary>
	/// Obtiene el nombre del estudiante
	/// </summary>
	/// <returns>string con el nombre</returns>
	string get_full_name() const { return this->full_name; }
	/// <summary>
	/// Obtiene el rut del estudiante
	/// </summary>
	/// <returns>string con el rut</returns>
	string get_rut() const { return this->rut; }
	/// <summary>
	/// Obtiene las notas del estudiante
	/// </summary>
	/// <returns>vector de float con las 3 notas</returns>
	float* get_marks() const { return this->marks; }
	/// <summary>
	/// Obtiene el paralelo del estudiante
	/// </summary>
	/// <returns>int con el paralelo</returns>
	int get_class_id() const { return this->class_id; }
	/// <summary>
	/// Obtiene el estado de aprobacion de taller del estudiante
	/// </summary>
	/// <returns>booleano con el estado de aprobacion</returns>
	bool get_project_status() const { return this->project_status; }
	/// <summary>
	/// Obtiene el numero de lista del estudiante
	/// </summary>
	/// <returns>int con el numero</returns>
	int get_list_number() const { return this->list_number; }
	/// <summary>
	/// Obtiene una nota del estudiante mediante la posicion de esta
	/// </summary>
	/// <param name="position">posicion o numero de calificacion</param>
	/// <returns>float con la nota</returns>
	float get_mark_by_position(int position) const { return this->marks[position - 1]; }

	/// <summary>
	/// Establece una nueva nota para el alumno
	/// </summary>
	/// <param name="mark">valor de la nota</param>
	/// <param name="position">Posición de nota que reemplazará</param>
	void set_mark(float mark, int position);
	#pragma endregion

};

