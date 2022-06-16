#include <iostream>
#include "database.h"
#include <conio.h>
#include <stdlib.h>


bool confirmation() {
	std::cout << "------------------------------------------------------------\n";
	cout << "Czy napewno chcesz kontynuowac(y / n)?\n";
	std::cout << "------------------------------------------------------------\n";
	char choice;
	choice = _getch();
	switch (choice)
	{
	case 'y':
		return true;
		break;
	case 'Y':
		return true;
		break;
	default:
		return false;
		break;
	}
}


int main()
{

	char choice{};
	int attempts = 1;
	Database db;
	db.menuToDatabase();

	if (db.logged || db.registered)
	{
		system("cls");
		while (true)
		{
			std::cout << "-----------------------" << std::endl;
			std::cout << "MENADZER HASEL" << std::endl;
			std::cout << "-----------------------" << std::endl;
			std::cout << std::endl;
			std::cout << "Nacisnij 1-6 aby wykonac akcje" << std::endl;
			std::cout << "\n1.Dodaj haslo\n2.Usun haslo\n3.Zmien Haslo\n4.Wyswietl wszystkie hasla\n5.Wyswietl haslo po id lub nazwie\n6.Zamknij program\n";
		
			choice = _getch();

			switch (choice)
			{
			case '1':
				if (confirmation()) {
					db.insertData();
				}
				break;
			case '2':
				if (confirmation()) {
					db.deleteData();
				}
				break;
			case '3':
				if (confirmation()) {
					db.changePassword();
				}
				break;
			case '4':
				db.selectData();
				break;
			case '5':
				if (confirmation()) {
					db.selectOne();
				}
				break;
			case '6':if (confirmation()) {
				exit(1);
			}

			default:
				std::cout << "Nieprawidlowy znak\n";
				break;
			}
			std::cout << "------------------------------------------------------------" << std::endl;
			std::cout << "Nacisnij Enter aby kontynuowac" << std::endl;
			_getch();
			system("cls");


		}
	}
	system("pause");
}