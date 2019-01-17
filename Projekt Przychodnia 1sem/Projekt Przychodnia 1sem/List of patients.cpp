#include "List of patients.h"
#include <iostream>
#include <string>


Patient* list_of_patients:: allocate_memory(std::string name, std::string surname, int age, long long int ID_number)
{
	Patient* added_patient = new Patient;
	//added_patient->name = name;
	//added_patient->surname = surname;
	//added_patient->age = age;
	//added_patient->ID_number = ID_number;   //to jest zast¹pione poni¿szym wywo³aniem funkcji set_patient();

	added_patient->set_patient(name, surname, age, ID_number);

	added_patient->illness_list.head = nullptr;               ///zerujê wskaŸnik na pocz¹tek i koniec listy chorób tego pacjenta poniewa¿ zostan¹ one dodane póŸniej
	added_patient->illness_list.tail = nullptr;
	return added_patient;
}

void list_of_patients::add_patient(Patient*added_patient)
{
	//komentuje to, poniewa¿ robiê dodatkow¹ funkcjê alkokuj¹c¹ pamiêæ dla pacjenta
	//Patient* added_patient = new Patient;
	//added_patient->name = name;
	//added_patient->surname = surname;
	//added_patient->age = age;
	//added_patient->ID_number = ID_number;   //to jest zast¹pione poni¿szym wywo³aniem funkcji set_patient();

	//added_patient->set_patient(name, surname, age, ID_number);     

	//added_patient->illness_list.head = nullptr;               ///zerujê wskaŸnik na pocz¹tek i koniec listy chorób tego pacjenta poniewa¿ zostan¹ one dodane póŸniej
	//added_patient->illness_list.tail = nullptr;


	Patient* temp = head;                           /// tworzê wskaŸnik tymczasowy i ustawiam go tak, by wskazywa³ na g³owê listy
	if (head == nullptr)                           ///sprawdzam, czy jest to pierwszy element listy pacjentów
	{
		head = added_patient;                      /// je¿eli lista by³a pusta to ten element jest teraz pierwszym elementem listy pacjentów
		tail = head;                              /// w tym przypadku pierwszy element jest te¿ elementem ostatnim
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
				tail->previous = added_patient;             //i to te¿
				added_patient->previous = nullptr;
				added_patient->next = tail;
				head = added_patient;
			}
		}
		else
		{
			while ((added_patient->surname >= temp->surname)&&temp->next!=nullptr)   /// porównuje alfabetycznie nazwiska pacjentów, po to by dodaæ nowego pacjenta w odpowiednie miejsce list
			{
				temp = temp->next;
			}

			if (temp == tail)                         ///sprawdzam czy dodajê Pacjenta na koniec listy
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
			else                         ///nie dodaje pacjenta na koniec ani na pocz¹tek listy, tylko do œrodka
			{
				added_patient->next = temp->next;
				temp->next->previous = added_patient;
				temp->next = added_patient;
				added_patient->previous = temp;
			}
		}
	}
	
	
}

void list_of_patients::print_list_of_patients()                    ///metoda ta drukuje liste pacjentów
{
	Patient* temp = head;                                          
	int i = 1;
	while (temp != tail)
	{
		std::cout << i << ") " << temp << std::endl;              ///drukuje pacjentów do przedostaniego pacjenta na liœcie
			i++;												/// u¿ywam przeci¹¿onego operatora << , dzieki czemu nie muszê wypisywaæ rêcznie ka¿dego pola struktury pacjent
		temp = temp->next;
	}
	if (temp == tail)
	{
		std::cout << i << ") " << temp << std::endl;             ///drukuje statniego pacjenta na liscie
																/// u¿ywam przeci¹¿onego operatora
	}

}

Patient* list_of_patients::search_for_a_patient()             ///metoda ta zwraca wskaŸnik na pacjenta 
{
	Patient* temp = head;
	int number_of_patient;
	std::cout << "Wprowadz numer pacjenta, ktorego chcesz znalezc: " << std::endl;
	print_list_of_patients();								                ///wywo³uje funkcjê, która drukuje wszystkich pacjentów
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
	Patient* tempprevious= removable->previous;               /// napierw szukamy pacjenta, którego chcemy usun¹æ
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