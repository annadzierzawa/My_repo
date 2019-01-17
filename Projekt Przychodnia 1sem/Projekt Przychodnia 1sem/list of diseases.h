#pragma once
#include <iostream>
#include <string>
#include "Struct illness.h"


struct list_of_diseases
{
	illness* head;                   ///wskaŸnik na pocz¹tek listy chorób
	illness* tail;					///wskaŸnik na koniec listy chorób

	void add_disease(std::string name_of_the_disease, int day, int month, int year);
	void print_list_of_diseases();
	std::string load_name_of_disease();
	void remove_last_disease();
	void clean_diseases();
};