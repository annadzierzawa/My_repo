#include "list of diseases.h"
#include "stdio.h"

std::string list_of_diseases::load_name_of_disease()
{
	std::string name_of_disease;
	//std::string name_of_disease1;
	//std::string name_of_disease2;
	std::cout << "Podaj nazwe choroby: ";
	std::getchar();
	//std::getline(std::cin, name_of_disease);

	std::getline(std::cin, name_of_disease);
	//name_of_disease = name_of_disease1 + name_of_disease2;
	
	for (int i = 0; i < name_of_disease.length(); i++)
	{
		if(name_of_disease[i] == ' ')
		{
			name_of_disease[i] = '_';
		}
	}
	if (name_of_disease[0] < 'A')                            ///zabezpieczenie sprawdzajace czy imie i nazwisko jest wpisane z du�ych liter
	{
		name_of_disease[0] = name_of_disease[0] + 32;
	}
	if (name_of_disease[0] > 'Z')
	{
		name_of_disease[0] = name_of_disease[0] - 32;
	}

	return name_of_disease;
}

void list_of_diseases::add_disease(std::string name_of_the_disease, int day, int month, int year)
{
	illness* added_disease = new illness;
	added_disease->date_of_illnes.set_date ( day,month,year);               /// do uzupe�nienia pola date_of_illness u�ywam wcze�niej napisanej metody set date, kt�ra jest zadeklarowana w strukturze illness



	added_disease->name_of_the_disease = name_of_the_disease;

	if (head == nullptr)              /// wykona si� gdy dodawana choroba jest pierwsz� chorob� danego pacjenta
	{
		head = added_disease;
		tail = head;
		added_disease->next = nullptr;
		added_disease->previous = nullptr;
	}
	else
	{
		if (head == tail)   ///je�eli lista zawiera ju� jeden element, a dodawana choroba b�dzie na drugiej pozycji tej listy
		{
			head->next = added_disease;
			added_disease->previous = head;
			tail = added_disease;
			added_disease->next = nullptr;
		}
		else
		{
			tail->next = added_disease;                       ///dodaje element na koniec listy
			added_disease->next = nullptr;
			added_disease->previous = tail;
			tail = added_disease;
		}
	}
}

void list_of_diseases:: print_list_of_diseases()
{
	illness* temp = head;
	
	std::cout << "List of diseases: " << std::endl;
	int i = 1;
	while (temp!=nullptr)
	{
		std::cout << i << ") ";
		std::cout << temp->name_of_the_disease <<"  date:  "<< temp->date_of_illnes << std::endl;           /// u�ywam przeci��onego operatora strumieniowego<< dlatego nie musz� po kolei wypisywac ka�dego pola daty
		temp = temp->next;
		i++;
	}
}

void list_of_diseases::remove_last_disease()
{
	if (tail == nullptr)
	{
		return;
	}
	else if (head == tail)
	{
		delete head;
		head = nullptr;
		tail = head;
	}
	else
	{
		illness* temp;
		temp = tail->previous;
		delete tail;
		tail = temp;
		temp->next = nullptr;
	}
}

void list_of_diseases::clean_diseases()         ///funkcja zwalniajaca pamiec listy chorob
{
	while (head != nullptr)
	{
		remove_last_disease();
	}
}