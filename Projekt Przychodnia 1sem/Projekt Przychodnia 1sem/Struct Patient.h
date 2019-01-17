#pragma once
#include <iostream>
#include <string>
#include"list of diseases.h"

struct Patient
{
	std::string name;
	std::string surname;
	int age;
	long long int ID_number;
	Patient*next;
	Patient*previous;
	list_of_diseases illness_list;
	void set_patient(std::string name, std::string surname, int age, long long int ID_number);     ///metoda, która uzupe³nia pola struktury pacjent 
};


std::ostream & operator<<(std::ostream & out, Patient * person);   ///przeci¹¿am operator strumieniowy <<, po to by w prostrzy sposób wypisywaæ Pacjenta, podobn¹ funkcjê spe³nia³a by metoda printpatient()