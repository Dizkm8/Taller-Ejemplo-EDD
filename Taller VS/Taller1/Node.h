#pragma once
#include <string>
#include "Student.h"
using namespace std;

/// <summary>
/// Permite crear nodos especificos del sistema
/// </summary>
class Node
{
private:
	Node* left;
	Node* up;
	Student* student;
	int row;
	int column;

public:
	/// <summary>
	/// Constructor
	/// </summary>
	Node();
	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="student">Instancia Student que contendra el nodo</param>
	Node(Student* student);
	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="student">Instancia Student que contendra el nodo</param>
	/// <param name="row">Ubicacion fila del nodo</param>
	/// <param name="column">Ubicacion columna del nodo</param>
	Node(Student* student,int row,int column);
	/// <summary>
	/// Destructor basico
	/// </summary>
	~Node();

	#pragma region getters_and_setters

	/// <summary>
	/// Obtiene el siguiente Nodo a la izquierda
	/// </summary>
	/// <returns>Puntero Node*</returns>
	Node* get_left() { return this->left; }
	/// <summary>
	/// Obtiene el siguiente hacia arriba
	/// </summary>
	/// <returns>Puntero Node*</returns>
	Node* get_up() { return this->up; }
	/// <summary>
	/// Obtiene el Student que contiene el nodo
	/// </summary>
	/// <returns>Puntero Student</returns>
	Student* get_student() { return this->student; }
	/// <summary>
	/// Obtiene la columna de ubicacion
	/// </summary>
	/// <returns>int</returns>
	int get_column() { return this->column; }
	/// <summary>
	/// Obtiene la fila de ubicacion
	/// </summary>
	/// <returns>int</returns>
	int get_row() { return this->row; }
	/// <summary>
	/// Establece un nuevo nodo izquierdo
	/// </summary>
	/// <param name="left">Puntero de Instancia de Nod</param>
	void set_left(Node* left) { this->left = left; }
	/// <summary>
	/// Establece un nuevo nodo hacia arriba
	/// </summary>
	/// <param name="up">Puntero de Instancia de Nodo</param>
	void set_up(Node* up) { this->up = up; }
	/// <summary>
	/// Establece un nuevo estudiante del nodo
	/// </summary>
	/// <param name="student">Puntero de Instancia de studiante</param>
	void set_student(Student* student) { this->student = student; }
	/// <summary>
	/// Establece nueva ubicacion columna
	/// </summary>
	/// <param name="column">Numero de columna</param>
	void set_column(int column) { this->column = column; }
	/// <summary>
	/// Establece nueva ubicacion fila
	/// </summary>
	/// <param name="row">Numero de fila</param>
	void set_row(int row) { this->row = row; }

	#pragma endregion

};

