#include "List of patients.h"
#include <iostream>
#include <string>


Patient* list_of_patients:: allocate_memory(std::string name, std::string surname, int age, long long int ID_number)
{
	Patient* added_patient = new Patient;
	//added_patient->name = name;
	//added_patient->surname = surname;
	//added_patient->age = age;
	//added_patient->ID_number = ID_number;   //to jest zast�pione poni�szym wywo�aniem funkcji set_patient();

	added_patient->set_patient(name, surname, age, ID_number);

	added_patient->illness_list.head = nullptr;               ///zeruj� wska�nik na pocz�tek i koniec listy chor�b tego pacjenta poniewa� zostan� one dodane p�niej
	added_patient->illness_list.tail = nullptr;
	return added_patient;
}

void list_of_patients::add_patient(Patient*added_patient)
{
	//komentuje to, poniewa� robi� dodatkow� funkcj� alkokuj�c� pami�� dla pacjenta
	//Patient* added_patient = new Patient;
	//added_patient->name = name;
	//added_patient->surname = surname;
	//added_patient->age = age;
	//added_patient->ID_number = ID_number;   //to jest zast�pione poni�szym wywo�aniem funkcji set_patient();

	//added_patient->set_patient(name, surname, age, ID_number);     

	//added_patient->illness_list.head = nullptr;               ///zeruj� wska�nik na pocz�tek i koniec listy chor�b tego pacjenta poniewa� zostan� one dodane p�niej
	//added_patient->illness_list.tail = nullptr;


	Patient* temp = head;                           /// tworz� wska�nik tymczasowy i ustawiam go tak, by wskazywa� na g�ow� listy
	if (head == nullptr)                           ///sprawdzam, czy jest to pierwszy element listy pacjent�w
	{
		head = added_patient;                      /// je�eli lista by�a pusta to ten element jest teraz pierwszym elementem listy pacjent�w
		tail = head;                              /// w tym przypadku pierwszy element jest te� elementem ostatnim
		added_patient-> previous = nullptr;
		added_patient-> next = nullptr;
	}
	else if (head->surname >= added_patient->surname)
	{
		added_patient->previous = nullptr;
		added_patient->next = head;
		head->previous = added_patient;
		head = added_patient;
	}
	else
	{
		if (head == tail)
		{
			if (added_patient->surname >= temp->surname)        //raczej dobrze
			{
				head->next = added_patient;
				added_patient->previous = head;
				added_patient->next = nullptr;
				tail = added_patient;
			}
			else
			{
				tail->previous = added_patient;             //i to te�
				added_patient->previous = nullptr;
				added_patient->next = tail;
				head = added_patient;
			}
		}
		else
		{
			while ((added_patient->surname >= temp->surname)&&temp->next!=nullptr)   /// por�wnuje alfabetycznie nazwiska pacjent�w, po to by doda� nowego pacjenta w odpowiednie miejsce list
			{
				temp = temp->next;
			}

			if (temp == tail)                         ///sprawdzam czy dodaj� Pacjenta na koniec listy
			{
				if (added_patient->surname >= temp->surname)
				{
					added_patient->next = nullptr;
					temp->next = added_patient;                    //chyba ok
					added_patient->previous = temp;
					tail = added_patient;
				}
				else
				{
					added_patient->previous = temp->previous;
					added_patient->next = temp;
					temp->previous->next = added_patient;
					temp->previous = added_patient;
					
				}
			}
			else                         ///nie dodaje pacjenta na koniec ani na pocz�tek listy, tylko do �rodka
			{
				added_patient->next = temp->next;
				temp->next->previous = added_patient;
				temp->next = added_patient;
				added_patient->previous = temp;
			}
		}
	}
	
	
}

void list_of_patients::print_list_of_patients()                    ///metoda ta drukuje liste pacjent�w
{
	Patient* temp = head;                                          
	int i = 1;
	while (temp != tail)
	{
		std::cout << i << ") " << temp << std::endl;              ///drukuje pacjent�w do przedostaniego pacjenta na li�cie
			i++;												/// u�ywam przeci��onego operatora << , dzieki czemu nie musz� wypisywa� r�cznie ka�dego pola struktury pacjent
		temp = temp->next;
	}
	if (temp == tail)
	{
		std::cout << i << ") " << temp << std::endl;             ///drukuje statniego pacjenta na liscie
																/// u�ywam przeci��onego operatora
	}

}

Patient* list_of_patients::search_for_a_patient()             ///metoda ta zwraca wska�nik na pacjenta 
{
	Patient* temp = head;
	int number_of_patient;
	std::cout << "Wprowadz numer pacjenta, ktorego chcesz znalezc: " << std::endl;
	print_list_of_patients();								                ///wywo�uje funkcj�, kt�ra drukuje wszystkich pacjent�w
	std::cin >> number_of_patient;

	for (int i=1; i< number_of_patient; i++)
	{
		if (temp->next == nullptr)
		{
			std::cout << "Wprowadz prawidlowy zakres danych!" << std::endl;
		}
		temp = temp->next;
	}

	return temp;
}

void list_of_patients::remove_patient()                       ///metoda to korzysta z metody search_for_a_patient()
{
	Patient* removable= search_for_a_patient();
	Patient* tempprevious= removable->previous;               /// napierw szukamy pacjenta, kt�rego chcemy usun��
	Patient* tempnext= removable->next;

	tempnext->previous = tempprevious;
	tempprevious->next = tempnext;

	delete removable;										/// usuwam pacjenta 
}

void list_of_patients::clean_memory()
{
	Patient* temp = tail;
	while (head != tail)
	{
		temp = tail;
		tail = tail->previous;
		temp->illness_list.clean_diseases();
		delete temp;	
	}
	delete head;
}