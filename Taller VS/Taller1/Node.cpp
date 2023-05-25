#include "Node.h"

Node::Node()
{
	this->left = nullptr;
	this->up = nullptr;
	this->student = nullptr;
	this->column = -1;
	this->row = -1;
}

Node::Node(Student* student)
{
	this->left = nullptr;
	this->up = nullptr;
	this->student = student;
	this->column = -1;
	this->row = -1;
}

Node::Node(Student* student, int row, int column)
{
	this->left = nullptr;
	this->up = nullptr;
	this->student = student;
	this->column = column;
	this->row = row;
}

Node::~Node()
{
	this->student->~Student();
	this->left = nullptr;
	this->up = nullptr;
}