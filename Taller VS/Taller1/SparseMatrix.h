#pragma once
#include <string>
#include "Node.h"
using namespace std;

/// <summary>
/// Permite instanciar Matrices poco pobladas
/// </summary>
class SparseMatrix
{
private:
	Node* a_row;
	Node* a_col;

public:
	/// <summary>
	/// Constructor Basico
	/// </summary>
	SparseMatrix();
	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="row">Numero de filas</param>
	/// <param name="column">Numero de columnas</param>
	SparseMatrix(int row,int column);
	/// <summary>
	/// Destructor basico
	/// </summary>
	~SparseMatrix() = default;
	/// <summary>
	/// Agrega un estudiante a la matriz
	/// </summary>
	/// <param name="student">Instancia de Student</param>
	void add_student(Student* student);
	/// <summary>
	/// Busca un estudiante
	/// </summary>
	/// <param name="rut">Rut del estudiante</param>
	/// <returns>Puntero Node con que contiene un Student</returns>
	Node* search_student(string rut);
	/// <summary>
	/// Busca un estudiante
	/// </summary>
	/// <param name="row">Fila del estudiante (Paralelo)</param>
	/// <param name="column">Columna del estudiante (Numero lista)</param>
	/// <returns>Puntero Node con que contiene un Student</returns>
	Node* search_student(int row,int column);
	/// <summary>
	/// Elimina un estudiante de la matriz
	/// </summary>
	/// <param name="row">Fila del estudiante (Paralelo)</param>
	/// <param name="column">Columna del estudiante (Numero lista)</param>
	/// <returns>True si se pudo eliminar</returns>
	bool delete_student(int row,int column);


	#pragma region getters

	/// <summary>
	/// Obtiene el vector de filas de la matriz
	/// </summary>
	/// <returns>Puntero Node al inicio del vector</returns>
	Node* get_a_row() { return this->a_row; }
	/// <summary>
	/// Obtiene el vector de columnas de la matriz
	/// </summary>
	/// <returns>Puntero Node al inicio del vector</returns>
	Node* get_a_col() { return this->a_col; }

	#pragma endregion

};

