#include "System.h"

#include <iostream>
#include <string>

System::System()
{
	this->backup_matrix = nullptr;
	this->system_matrix = nullptr;
	this->deleted_matrix = nullptr;
	this->code = "";
}

void System::initialization()
{
	this->backup_matrix = new SparseMatrix(25,9);
	this->system_matrix = new SparseMatrix(25,9);
	this->deleted_matrix = new SparseMatrix(25,9);
}

void System::add_student(string fullname, string rut, float* marks,
	int class_id, bool project_status, int list_number)
{
	this->backup_matrix->add_student(new Student(fullname, rut, marks, class_id, project_status, list_number));
	this->system_matrix->add_student(new Student(fullname, rut, marks, class_id, project_status, list_number));
	this->deleted_matrix->add_student(new Student(fullname, rut, marks, class_id, project_status, list_number));
}

bool System::enter_mark(float mark, int mark_position, string student_rut)
{
	Node* student_node = this->system_matrix->search_student(student_rut);

	if(student_node != nullptr)
	{
		if(student_node->get_student()->get_mark_by_position(mark_position) == 1)
		{
			student_node->get_student()->set_mark(mark,mark_position);
			return true;
		}
	}
	return false;
}

int* System::project_disapproved_students()
{
	int* info_vector = new int[9];
	for (int i = 1; i < 10; ++i)
	{
		int student_meter = 0;
		for (int j = 1; j < 26; ++j)
		{
			Node* aux = this->system_matrix->search_student(j, i);

			if (aux != nullptr)
			{
				if (!aux->get_student()->get_project_status())
				{
					student_meter++;
				}
			}
		}
		info_vector[i - 1] = student_meter;
	}
	return info_vector;
}

float System::non_approved_students_system_matrix()
{
	float non_approved_students_amount = 0;
	float total_students_amount = 0;

	for (int i = 1; i < 10; ++i)
	{
		for (int j = 1; j < 26; ++j)
		{
			Node* aux = this->system_matrix->search_student(j, i);

			if (aux != nullptr)
			{
				total_students_amount++;
				if(!aux->get_student()->get_project_status())
				{
					non_approved_students_amount++;
				}
				else if(Util::approximation(aux->get_student()->get_mark_by_position(1) * 0.3 +
					aux->get_student()->get_mark_by_position(2) * 0.4 +
					aux->get_student()->get_mark_by_position(3) * 0.3) < 4)
				{
					non_approved_students_amount++;
				}
			}
		}
	}

	float average = Util::approximation(100 * (non_approved_students_amount / total_students_amount), 10);
	return average;
}

float System::non_approved_students_backup_matrix()
{
	float non_approved_students_amount = 0;
	float total_students_amount = 0;

	for (int i = 1; i < 10; ++i)
	{
		for (int j = 1; j < 26; ++j)
		{
			Node* aux = this->backup_matrix->search_student(j, i);

			if (aux != nullptr)
			{
				total_students_amount++;
				if (!aux->get_student()->get_project_status())
				{
					non_approved_students_amount++;
				}
				else if (Util::approximation(aux->get_student()->get_mark_by_position(1) * 0.3 +
					aux->get_student()->get_mark_by_position(2) * 0.4 +
					aux->get_student()->get_mark_by_position(3) * 0.3) < 4)
				{
					non_approved_students_amount++;
				}
			}
		}
	}

	if(total_students_amount == 0)
	{
		return 0;
	}

	float average = Util::approximation(100 * (non_approved_students_amount / total_students_amount), 10);
	return average;
}

string* System::final_score_students_system_matrix()
{
	string* info_vector = new string[225];
	int elements_in_vector_meter = 0;

	for (int i = 1; i < 10; ++i)
	{
		for (int j = 1; j < 26; ++j)
		{
			Node* aux = this->system_matrix->search_student(j, i);
			if (aux != nullptr)
			{
				string student_info = "";

				float student_average = Util::approximation(
					aux->get_student()->get_mark_by_position(1) * 0.3 +
					aux->get_student()->get_mark_by_position(2) * 0.4 +
					aux->get_student()->get_mark_by_position(3) * 0.3);
				student_info = "[Alumno] "+ aux->get_student()->get_full_name() + " ";
				student_info += "[RUT] " + aux->get_student()->get_rut()+" ";
				student_info += "[Promedio final] " + to_string(student_average).substr(0, 3) + " ";
				if(!aux->get_student()->get_project_status())
				{
					student_info += "[Estado] Reprueba"; 
				}
				else
				{
					if(student_average > 4)
					{
						student_info += "[Estado] Aprueba";
					}
					else if(student_average > 3.3)
					{
						student_info += "[Estado] Debe Rendir Examen";
					}
					else
					{
						student_info += "[Estado] Reprueba"; 
					}
				}
				info_vector[elements_in_vector_meter] = student_info;
				elements_in_vector_meter++;
			}
		}
	}
	return info_vector;
}

string* System::final_score_students_backup_matrix()
{
	string* info_vector = new string[225];
	int elements_in_vector_meter = 0;

	for (int i = 1; i < 10; ++i)
	{
		for (int j = 1; j < 26; ++j)
		{
			Node* aux = this->backup_matrix->search_student(j, i);
			if (aux != nullptr)
			{
				string student_info = "";

				float student_average = Util::approximation(
					aux->get_student()->get_mark_by_position(1) * 0.3 +
					aux->get_student()->get_mark_by_position(2) * 0.4 +
					aux->get_student()->get_mark_by_position(3) * 0.3);
				student_info = "[Alumno] " + aux->get_student()->get_full_name() + " ";
				student_info += "[RUT] " + aux->get_student()->get_rut() + " ";
				student_info += "[Promedio final] " + to_string(student_average).substr(0, 3) + " ";
				if (!aux->get_student()->get_project_status())
				{
					student_info += "[Estado] Reprueba";
				}
				else
				{
					if (student_average > 4)
					{
						student_info += "[Estado] Aprueba";
					}
					else if (student_average > 3.3)
					{
						student_info += "[Estado] Debe Rendir Examen";
					}
					else
					{
						student_info += "[Estado] Reprueba";
					}
				}
				info_vector[elements_in_vector_meter] = student_info;
				elements_in_vector_meter++;
			}
		}
	}
	return info_vector;
}

void System::matrix_filter()
{
	for (int i = 1; i < 10; ++i)
	{
		for (int j = 1; j < 26; ++j)
		{
			Node* aux = this->deleted_matrix->search_student(j, i);

			if (aux != nullptr)
			{
				if(!aux->get_student()->get_project_status())
				{
					this->deleted_matrix->delete_student(j, i);
				}
			}
		}
	}
}

string** System::get_printed_system_matrix()
{
	string** students_matrix = new string * [25];
	for (int i = 0; i < 25; ++i)
	{
		students_matrix[i] = new string[9];
		for (int j = 0; j < 9; ++j)
		{
			students_matrix[i][j] = " ";
		}
	}

	for (int i = 1; i < 10; ++i)
	{
		for (int j = 1; j < 26; ++j)
		{
			Node* aux = this->system_matrix->search_student(j, i);

			if (aux != nullptr)
			{
				students_matrix[j - 1][i - 1] = "X";
			}
		}
	}
	return students_matrix;
}

string** System::get_printed_deleted_matrix()
{
	string** students_matrix = new string * [25];
	for (int i = 0; i < 25; ++i)
	{
		students_matrix[i] = new string[9];
		for (int j = 0; j < 9; ++j)
		{
			students_matrix[i][j] = " ";
		}
	}

	for (int i = 1; i < 10; ++i)
	{
		for (int j = 1; j < 26; ++j)
		{
			Node* aux = this->deleted_matrix->search_student(j, i);
			if (aux != nullptr)
			{
				students_matrix[j-1][i-1] = "X";
			}
		}
	}
	return students_matrix;
}

string* System::get_all_students_info()
{
	string* vector_info = new string[225];
	int elements_in_vector_meter = 0;

	for (int i = 1; i < 10; ++i)
	{
		for (int j = 1; j < 26; ++j)
		{
			Node* aux = this->system_matrix->search_student(j, i);

			if (aux != nullptr)
			{
				vector_info[elements_in_vector_meter] = aux->get_student()->get_full_name()+",";
				vector_info[elements_in_vector_meter] += aux->get_student()->get_rut()+",";
				vector_info[elements_in_vector_meter] += to_string(aux->get_student()->get_mark_by_position(1))
				.substr(0,3)+",";
				vector_info[elements_in_vector_meter] += to_string(aux->get_student()->get_mark_by_position(2))
				.substr(0, 3) +",";
				vector_info[elements_in_vector_meter] += to_string(aux->get_student()->get_mark_by_position(3))
				.substr(0, 3) +",";
				if(aux->get_student()->get_project_status())
				{
					vector_info[elements_in_vector_meter] += "Verdadero,";
				}
				else
				{
					vector_info[elements_in_vector_meter] += "Falso,";
				}
				vector_info[elements_in_vector_meter] += to_string(aux->get_student()->get_class_id()) + ",";
				vector_info[elements_in_vector_meter] += to_string(aux->get_student()->get_list_number());
				elements_in_vector_meter++;
			}
		}
	}

	return vector_info;
}