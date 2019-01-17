#pragma once
#include <iostream>
#include <string>

struct date
{
	int day;
	int month;
	int year;

	void set_date(int day, int month, int year);    ///metoda, kt�ra ustawia date

};

struct illness
{
	std::string name_of_the_disease;
	date date_of_illnes;
	illness*next;
	illness*previous;
};


std::ostream & operator<<(std::ostream & i, date & k);        ///przeci��am operator strumieniowy <<, po to by w prostrzy spos�b wypisywa� dat�, podobn� funkcj� spe�nia�a by metoda printdate()
