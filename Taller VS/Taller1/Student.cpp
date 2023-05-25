#include "Student.h"

Student::Student()
{
	this->full_name = "";
	this->rut = nullptr;
	this->marks = nullptr;
	this->class_id = -1;
	this->project_status = false;
	this->list_number = -1;
}

Student::Student(string full_name, string rut, float* marks,
	int class_id, bool project_status, int list_number)
{
	this->full_name = full_name;
	this->rut = rut;
	this->marks = marks;
	this->class_id = class_id;
	this->project_status = project_status;
	this->list_number = list_number;
}

Student::~Student()
{
}

void Student::set_mark(float mark, int position)
{
	position -= 1;
	*(this->marks + position) = mark;
}
