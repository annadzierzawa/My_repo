#include "Headers.h"



list_of_patients* load_data_base()
{
	list_of_patients* List = new list_of_patients;
	List->head = nullptr;
	List->tail = nullptr;

	std::fstream file;
	std::string name, surname;
	int age;
	long long int ID_number;
	char if_;              ///jest zmienna, która bêdzie u¿yta do sprawdzenia czy w danej linii s¹ wpisane choroby

	int day, month, year;
	std::string name_of_the_disease;
	char end=2;
	Patient*added_patient;

	file.open("Do_odczytu.txt", std::ios::in);
	file.seekg(0, std::ios::end);
	int length = file.tellg();
	file.seekg(0, std::ios::beg);
		if (file.good())         // alternatywna funkcja to is_open();
		{
			while (file.tellg()!=-1 && file.tellg() != length)                 ///-1 to kod koñca pliku
			{
				int k = file.tellg();
				file >> name;                              ///pobieram dane z pliku
				file >> surname;
				file >> age;
				file >> ID_number;

				added_patient=List->allocate_memory(name, surname, age, ID_number);        /// alokuje pamiêæ na nowego pacjenta

				List->add_patient(added_patient);    /// dodaje pacjenta do listy
				k = file.tellg();
				file.get(if_);
				file.get(if_);
				k = file.tellg();
				if (if_ == '@' && file.tellg() != -1)            ///sprawdzam, czy pacjent posiada jakieœ choroby     
				{
					while (true)                /// pêtla while wykonuje siê tak d³ugo a¿ nie dojdzie do koñca linii
					{
						file >> name_of_the_disease;
						file >> day;
						file >> month;
						file >> year;
						added_patient->illness_list.add_disease(name_of_the_disease, day, month, year);       /// dodaje chorobê do listy chorób dodawanego pacjenta
						file >> end;
						if (end == '@')
						{
							break;
						}
						else
						{
							file.seekg(-1, std::ios::cur);
						}
					}
				}
				else
				{
					file.seekg(-1, std::ios::cur);
				}
			}
			file.close();                     ///zamykam plik

		}
		else
		{
			std::cout << "Nie mozna otworzyc pliku z danymi pacjentow." << std::endl;
		}
		return List;
}

void finish(list_of_patients* List)
{
	std::fstream save;
	Patient* temp =List->head;
	illness* help;

	save.open("Do_odczytu.txt", std::ios::out);
	if (save.good())                              // mog³oby byæ if(save.is_open())
	{
		while (temp!=nullptr)
		{
			if (temp->next == nullptr)
			{
				save << temp->name;
				save << " ";
				save << temp->surname;
				save << " ";
				save << temp->age;
				save << " ";
				save << temp->ID_number;
			}
			else
			{
				save << temp->name;
				save << " ";
				save << temp->surname;
				save << " ";
				save << temp->age;
				save << " ";
				save << temp->ID_number;
				save << std::endl;
			}
			if (temp->illness_list.head != nullptr)
			{
				if (temp->next == nullptr)
				{
					save << std::endl;
				}
				help = temp->illness_list.head;
				save << "@ ";
				while (help !=nullptr)
				{
					
					save << help->name_of_the_disease;
					save << " ";
					save << help->date_of_illnes;
					save << " ";

						help = help->next;
						if (help == nullptr)
						{
							save << " @";
							if (temp->next != nullptr)
							{
								save << std::endl;
							}
						}
				}
			}
			temp = temp->next;
		}


	}
	else
	{
		std::cout << "Nie mozna otworzyc pliku od zapisu!";
	}

	save.close();
}
void run()
{   
	std::cout << "PROGRAM NAPISALA ANNA DZIERZAWA";
	Sleep(3000);              //dac 5000
	system("cls");

	std::cout << "WITAJ W BAZIE DANYCH PRZYCHODNI:" << std::endl;
	std::cout<< " "<<std::endl;
	std::cout << "LOADING ";
		for (int i = 0; i < 10; i++)
		{
			std::cout << ". ";
			Sleep(500);
		}
		system("cls");
		
		
	list_of_patients* List=load_data_base();

	int choice;
	bool variable = true;

	while (variable)
	{

		std::cout << "MENU:" << std::endl;
		std::cout << "1. Dodaj Pacjenta " << std::endl;
		std::cout << "2. Usun Pacjenta " << std::endl;
		std::cout << "3. Drukuj Liste Pacjentow " << std::endl;
		std::cout << "4. Dodaj chorobe Pacjentowi" << std::endl;
		std::cout << "5. Drukuj choroby Pacjenta " << std::endl;
		std::cout << "6. Usun ostatnia chorobe pacjenta " << std::endl;
		std::cout << "7. Wyjdz" << std::endl;
		std::cin >> choice;

		switch (choice)
		{
		case 1:             //dodaj pacjenta
		{
			std::string name, surname;
			int age;
			long long int ID_number;
			
			std::cout << "Podaj imie: ";
			std::cin >> name;
			std::cout << "Podaj nazwisko: ";
			std::cin >> surname;
			std::cout << "Podaj wiek: ";
			std::cin >> age;
			std::cout << "Podaj PESEL: ";
			std::cin >> ID_number;

			if (name[0]<'A')                            ///zabezpieczenie sprawdzajace czy imie i nazwisko jest wpisane z du¿ych liter
			{
			name[0] = name[0] + 32;
			}
			if (name[0] > 'Z')
			{
				name[0] = name[0] -32;
			}
			if (surname[0] < 'A')
			{
				surname[0] = surname[0] + 32;
			}
			if (surname[0] > 'Z')
			{
				surname[0] = surname[0] - 32;
			}




			Patient* added_patient= List->allocate_memory(name, surname, age, ID_number);
			List->add_patient(added_patient);
			break;
		}
		case 2:                 //usuñ pacjenta
		{
			List->remove_patient();
			break;
		}
		case 3:                 // Drukuj Listê Pacjentow
		{
			List->print_list_of_patients();
			break;
		}
		case 4:   // Dodaj chorobê Pacjentowi
		{
			Patient* temp= List->search_for_a_patient();
			std::string name_of_disease = temp->illness_list.load_name_of_disease();

			int day, month, year;
			std::cout << "Podaj date "<< std::endl;
			std::cout << "Podaj dzien: ";
			std::cin >> day;
			std::cout << "Podaj miesiac: ";
			std::cin >> month;
			std::cout << "Podaj rok: ";
			std::cin >> year;

			temp->illness_list.add_disease(name_of_disease, day, month, year);

			break;
		}
		case 5:						//Drukuj choroby Pacjenta
		{
			Patient* temp = List->search_for_a_patient();
			temp->illness_list.print_list_of_diseases();
			break;
		}
		case 6:                        //Usun ostatnia chorobe pacjenta
		{
			Patient* temp = List->search_for_a_patient();
			temp->illness_list.remove_last_disease();
			break;
		}
		case 7:
		{
			variable = false;
			break;
		}
		}
		
	}
	finish(List);
	List->clean_memory();
}