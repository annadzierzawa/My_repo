#pragma once
#include <iostream>
#include <string>

struct date
{
	int day;
	int month;
	int year;

	void set_date(int day, int month, int year);    ///metoda, która ustawia date

};

struct illness
{
	std::string name_of_the_disease;
	date date_of_illnes;
	illness*next;
	illness*previous;
};


std::ostream & operator<<(std::ostream & i, date & k);        ///przeci¹¿am operator strumieniowy <<, po to by w prostrzy sposób wypisywaæ datê, podobn¹ funkcjê spe³nia³a by metoda printdate()
