#include "UserInterface.h"

#pragma region UTIL_METHODS

string UserInterface::input(string message)
{
	string answer;
	cout << message;
	getline(cin, answer);
	return answer;
}

#pragma endregion


void UserInterface::main_menu()
{
	string option = "X";
	PRINT("--------------- Bienvenid@ a la UceninPlatform ---------------\n")
	PRINT("        Aqui podras ver la informacion de tus alumn@s           ")

	 while(option != "E")
	 {
		 PRINT("\n\n<<<<<<<<<<<<<<<<<<<<<<< Elija una opcion >>>>>>>>>>>>>>>>>>>>>>>\n\n")
		 PRINT("[A] Cargar datos\n[B] Registrar nota\n[C] Generar estadisticos\n")
		 option = Util::to_upper_case(Util::strip(input
		 ("[D] Filtrar matriz\n[E] Salir del sistema\n\nSu eleccion: ")));
		 if (option == "A")
		 {
			 this->load_data();
		 }
		 else if (option == "B")
		 {
			 this->change_mark();
		 }
		 else if (option == "C")
		 {
			 this->get_statistics();
		 }
		 else if (option == "D")
		 {
			 this->matrix_filter();
		 }
		 else if (option == "E")
		 {
			 this->shutdown();
		 }
		 else
		 {
			 PRINT("\n\n             [!][!][!] Respuesta invalida [!][!][!]\n\n")
		 }
	 }
	
}

void UserInterface::load_data()
{
	if(this->system->matrix_exists())
	{
		PRINT("\n\n################################################################\n\n")
		PRINT("\n\n[!][!][!]   Los datos YA fueron cargados previamente   [!][!][!]\n\n")
		PRINT("\n\n################################################################\n\n\n")
		return;
	}
	this->system->initialization();
	this->read_students_file();
	PRINT("\n\n\n               [!][!][!] Por favor espera [!][!][!]\n\n")
	#pragma region TIMER
	PRINT("                               .")
	for (int i = 0; i < 3; ++i)
	{
		Util::timer(1);
		PRINT(".")
	}
	#pragma endregion
	PRINT("\n\n   [*][*][*] Los datos fueron cargados correctamente [*][*][*]\n")

	string class_code = input("\n\n Ingrese el codigo del curso: ");
	
	while (Util::strip(class_code).size() == 0)
	{
		PRINT("\n\n\n[!][!][!] Codigo incorrecto [!][!][!]\n\n")
		class_code = input("Intentelo nuevamente: ");
	}

	this->system->set_code(class_code);
}

void UserInterface::read_students_file()
{
	ifstream archive("estudiantes.txt");
	string line = "";
	while (getline(archive, line))
	{
		string name;
		string rut;
		string first_mark;
		string second_mark;
		string third_mark;
		string project_status;
		string class_id;
		string list_number;

		stringstream s(line);
		getline(s, name, ',');
		getline(s, rut, ',');
		getline(s, first_mark, ',');
		getline(s, second_mark, ',');
		getline(s, third_mark, ',');
		getline(s, project_status, ',');
		getline(s, class_id, ',');
		getline(s, list_number, ',');

		bool project_status_bool;
		project_status = Util::to_upper_case(Util::strip(project_status));

		if(project_status == "VERDADERO")
		{
			project_status_bool = true;
		}
		else
		{
			project_status_bool = false;
		}

		float* marks = new float[3];
		marks[0] = stof(first_mark);
		marks[1] = stof(second_mark);
		marks[2] = stof(third_mark);



		this->system->add_student(name,Util::strip(rut), marks, stoi(class_id),
			project_status_bool,stoi(list_number));
	}
	archive.close();
}

void UserInterface::change_mark()
{
	if(!load_data_verifier())
	{
		return;
	}

	PRINT("\n\n\n## Para cambiar una nota debe ingresar el RUT del estudiante ##\n")
	PRINT("## le recordamos que debe mantener el formato ~11.111.111-1~ ##\n")
	PRINT("##       En caso contrario sera invalidada su respuesta      ##\n\n")
	string rut = input("RUT: ");

	if(!Util::rut_validator(rut))
	{
		PRINT("\n\n\n          [!][!][!] Ingresaste un rut NO valido [!][!][!]\n\n\n")
		return;
	}

	string new_mark_str = input("\n\nIngrese la nueva calificacion obtenida: ");
	if(!Util::mark_verifier(new_mark_str))
	{
		PRINT("\n\n\n   [!][!][!] Ingresaste una calificacion NO valida [!][!][!]\n\n\n")
		return;
	}
	float new_mark = stof(new_mark_str);

	string position_mark_str = input("\n\nIndique que prueba reemplazara (1 / 2 / 3): ");

	if(!Util::mark_position_verifier(position_mark_str))
	{
		PRINT("\n\n\n[!][!][!] Codigo incorrecto [!][!][!]\n\n")
		return;
	}
	int position_mark = stoi(position_mark_str);

	if(this->system->enter_mark(new_mark, position_mark, rut))
	{
		PRINT("\n\n\n [*][*][*] Calificacion actualizada correctamente [*][*][*] \n\n\n")
		return;
	}
	PRINT("\n\n\n   [!][!][!] No fue posible cambiar la calificacion [!][!][!]\n\n\n")
}

void UserInterface::get_statistics()
{
	if (!load_data_verifier())
	{
		return;
	}
	statistics_menu();
}

void UserInterface::statistics_menu()
{
	string option = "X";

	while (option != "D")
	{
		cout << "\n\n\n                             Curso [Programacion]\n";
		cout << "                            Codigo Curso [" << this->system->get_code() << "]\n\n";
		PRINT("------------------------- Seleccione una estadistica  -------------------------\n\n")
		PRINT("[A] Cantidad de estudiantes por cada paralelo que estan reprobando por taller\n")
		PRINT("[B] Porcentaje total de estudiantes que se encuentran sin aprobar el curso\n")
		PRINT("[C] Promedio final de Catedra para cada estudiante registrado\n")
		option = Util::to_upper_case(Util::strip(input(
			"[D] Volver al menu anterior\n\nSu eleccion: ")));

		if (option == "A")
		{
			this->project_disapproved_students();
		}
		else if (option == "B")
		{
			this->non_approved_students();
		}
		else if (option == "C")
		{
			this->final_score_students();
		}
		else if (option == "D")
		{
			this->back_to_main_menu();
		}
		else
		{
			PRINT("\n\n             [!][!][!] Respuesta invalida [!][!][!]")
		}
	}
}

bool UserInterface::load_data_verifier()
{
	if (!this->system->matrix_exists())
	{
		PRINT("\n\n################################################################\n\n")
		PRINT("\n\n[!][!][!]  Los datos NO han sido cargados previamente  [!][!][!]\n\n")
		PRINT("\n\n################################################################\n\n\n")
		return false;
	}
	return true;
}

void UserInterface::project_disapproved_students()
{
	PRINT("\n\n")
	int* vector_info = this->system->project_disapproved_students();
	for (int i = 0; i < 9; ++i)
	{
		cout << "\n[!][!][!] En el paralelo " << i + 1;
		cout << " hay " << vector_info[i] << " alumnos";
		cout << " reprobando por taller [!][!][!]\n";
	}

	delete[] vector_info;
}

void UserInterface::non_approved_students()
{
	cout << "\n\n\nEl porcentaje de estudiantes que no han aprobado el curso es del " <<
		this->system->non_approved_students_system_matrix() << "%\n\n";
	cout << "El porcentaje de estudiantes que INICIALMENTE no habian aprobado el curso era del " <<
		this->system->non_approved_students_backup_matrix() << "%\n\n\n";
}

void UserInterface::final_score_students()
{
	PRINT("\n\n")
	PRINT("       Informacion del curso ANTES de hacer cambios de notas\n\n")
	#pragma region TIMER
	PRINT("                               #")
	for (int i = 0; i < 3; ++i)
	{
		PRINT("#")
		Util::timer(1);
	}
	#pragma endregion
	PRINT("\n")
	string* vector_info = this->system->final_score_students_system_matrix();
	for (int i = 0; i < 224; ++i)
	{
		PRINTLN(vector_info[i])
		if(vector_info[i+1] == "")
		{
			break;
		}
	}
	PRINT("\n\n       Informacion del curso DESPUES de hacer cambios de notas\n\n")
	#pragma region TIMER
	PRINT("                               #")
	for (int i = 0; i < 3; ++i)
	{
		PRINT("#")
		Util::timer(1);
	}
	#pragma endregion
	PRINT("\n")
	vector_info = this->system->final_score_students_backup_matrix();
	for (int i = 0; i < 224; ++i)
	{
		PRINTLN(vector_info[i])
		if (vector_info[i + 1] == "")
		{
			break;
		}
	}

	delete[] vector_info;
}


void UserInterface::back_to_main_menu()
{
	PRINT("\n\n                    Volviendo al menu principal en\n\n")
	#pragma region TIMER
	for (int i = 4 - 1; i >= 1; --i)
	{
		cout << "                                   " << i << "\n";
		Util::timer(1);
	}
	#pragma endregion
	PRINT("\n")
}

void UserInterface::matrix_filter()
{
	if (!load_data_verifier())
	{
		return;
	}
	this->system->matrix_filter();
	this->print_matrix();
}

void UserInterface::print_matrix()
{
	string** students1 = this->system->get_printed_system_matrix();
	PRINT("\n\n")
		PRINT("    [1][2][3][4][5][6][7][8][9]")
	for (int i = 0; i < 25; ++i)
	{
		if (i < 9)
		{
			cout << "\n[ " << i + 1 << "] ";
		}
		else 
		{
			cout << "\n[" << i + 1 << "] ";
		}

		for (int j = 0; j < 9; ++j)
		{
			cout << students1[i][j] << "  ";
		}
	}

	#pragma region TIMER
	PRINT("\n\nEliminando los alumnos que NO aprobaron por Taller")
	for (int i = 0; i < 3; ++i)
	{
		Util::timer(1);
		PRINT(".");
	}
	#pragma endregion
	PRINT("\n\n")
	PRINT("    [1][2][3][4][5][6][7][8][9]")


	string** students2 = this->system->get_printed_deleted_matrix();

	for (int i = 0; i < 25; ++i)
	{
		if(i<9)
		{
			cout << "\n[ " << i + 1 << "] ";
		}
		else
		{
			cout << "\n[" << i + 1 << "] ";
		}
		
		for (int j = 0; j < 9; ++j)
		{
			cout << students2[i][j] << "  ";
		}
	}

	delete[] students2;
	delete[] students1;
}

void UserInterface::shutdown()
{
	if (this->system->matrix_exists())
	{
		this->save_data();
	}
	PRINT("\n\n\n######################################################################")
	PRINT("\n###################### GRACIAS POR PREFERIRNOS #######################")
	PRINT("\n######################################################################\n\n")
}

void UserInterface::save_data()
{
	ofstream output("estudiantes_editados.txt");
	string* vector_info = system->get_all_students_info();
	for (int i = 0; i < 224; ++i)
	{
		if (vector_info[i+1] == "")
		{
			output << vector_info[i];
			break;
		}
		output << vector_info[i] + "\n";
	}
	output.close();
	delete[] vector_info;
}

UserInterface::UserInterface()
{
	this->system = new System();
}

void UserInterface::initialization()
{
	this->main_menu();
}