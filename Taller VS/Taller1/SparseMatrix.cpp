#include "SparseMatrix.h"
#include <string>
using namespace std;

#include <iostream>

SparseMatrix::SparseMatrix()
{
	this->a_row = nullptr;
	this->a_col = nullptr;
}

SparseMatrix::SparseMatrix(int row, int column)
{
	this->a_row = new Node[row];
	this->a_col = new Node[column];

	for (int i = 0; i < row; ++i)
	{
		(this->a_row + i)->set_left(this->a_row + i);
		(this->a_row + i)->set_column(0);
		if (i < column)
		{
			(this->a_col + i)->set_up(this->a_col + i);
			(this->a_col + i)->set_row(0);
		}
	}
}

void SparseMatrix::add_student(Student* student)
{
	int row = student->get_list_number();
	int column = student->get_class_id();
	Node* newNode = new Node(student,row,column);

	Node* aux = &a_row[row - 1];

	while (aux->get_left()->get_column() > column)
	{
		aux = aux->get_left();
	}
	newNode->set_left(aux->get_left());
	aux->set_left(newNode);

	aux = &a_col[column - 1];

	while(aux->get_up()->get_row() > row)
	{
		aux = aux->get_up();
	}
	newNode->set_up(aux->get_up());
	aux->set_up(newNode);
}

Node* SparseMatrix::search_student(string rut)
{
	if(this->a_row == nullptr || this->a_col == nullptr)
	{
		return nullptr;
	}
	for (int i = 0; i < 25; ++i)
	{
		Node* aux = this->a_row+i;
		while(aux->get_left() != this->a_row+i)
		{
			if(aux != this->a_row+i)
			{
				if((aux->get_student()->get_rut()) == rut)
				{
					return aux;
				}
			}
			aux = aux->get_left();
		}
		if (aux != this->a_row+i)
		{
			if ((aux->get_student()->get_rut()) == rut)
			{
				return aux;
			}
		}
	}
	return nullptr;
}

Node* SparseMatrix::search_student(int row, int column)
{
	if(row>25 || row<1 || column>9 || column<0)
	{
		return nullptr;
	}

	Node* aux = this->a_row + row-1;
	while (aux->get_left()->get_column() >= column)
	{
		aux = aux->get_left();
	}
	if (aux != this->a_row + row-1)
	{
		if (aux->get_column() == column)
		{
			return aux;
		}
	}
	return nullptr;
}

bool SparseMatrix::delete_student(int row, int column)
{
	Node* aux = this->a_row + row - 1;

	while (aux->get_left()->get_column() > column)
	{
		aux = aux->get_left();
	}

	Node* delete_node;
	if (aux->get_left()->get_column() == column)
	{
		delete_node = aux->get_left();
		aux->set_left(delete_node->get_left());

		aux = this->a_col + column - 1;

		while (aux->get_up()->get_row() > row)
		{
			aux = aux->get_up();
		}

		if (aux->get_up()->get_row() == row)
		{
			delete_node = aux->get_up();
			aux->set_up(delete_node->get_up());
			delete_node->~Node();
			return true;
		}
	}
	return false;
}