#include "Struct Patient.h"

void Patient::set_patient(std::string name_, std::string surname_, int age_, long long int ID)
{
	name = name_;
	surname = surname_;
	age = age_;
	ID_number = ID;

}


std::ostream & operator<<(std::ostream & out, Patient * person)
{
	out << person->name <<" "<< person->surname << std::endl << "AGE: " << person->age << std::endl << "ID number: " << person->ID_number << std::endl;
	return out;
}

