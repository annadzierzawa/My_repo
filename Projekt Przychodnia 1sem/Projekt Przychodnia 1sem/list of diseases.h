#pragma once
#include <iostream>
#include <string>
#include "Struct illness.h"


struct list_of_diseases
{
	illness* head;                   ///wska�nik na pocz�tek listy chor�b
	illness* tail;					///wska�nik na koniec listy chor�b

	void add_disease(std::string name_of_the_disease, int day, int month, int year);
	void print_list_of_diseases();
	std::string load_name_of_disease();
	void remove_last_disease();
	void clean_diseases();
};