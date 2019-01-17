#pragma once
#include"Struct Patient.h"
#include <iostream>


struct list_of_patients
{
	Patient *head;                   ///wskaŸnik na pocz¹tek listy pacjentów
	Patient *tail;					///wskaŸnik na koniec listy pacjentów
	Patient* allocate_memory(std::string name, std::string surname, int age, long long int ID_number);
	void add_patient(Patient*added_patient);
	void print_list_of_patients();
	Patient* search_for_a_patient();
	void remove_patient();
	void clean_memory();
};