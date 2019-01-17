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
	void set_patient(std::string name, std::string surname, int age, long long int ID_number);     ///metoda, kt�ra uzupe�nia pola struktury pacjent 
};


std::ostream & operator<<(std::ostream & out, Patient * person);   ///przeci��am operator strumieniowy <<, po to by w prostrzy spos�b wypisywa� Pacjenta, podobn� funkcj� spe�nia�a by metoda printpatient()