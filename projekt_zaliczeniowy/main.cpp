#include <iostream>
#include "database.h"
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
	char choice{};
	int attempts = 1;
	Database db;
	std::cout << "Menedzer hasel\n\n1.Zaloguj sie\n2.Zarejestruj sie\n";
	choice = _getch();
	switch (choice)
	{
	case '1':
		do {
			if (!db.logged && attempts > 1) std::cout << "\nNieprawidlowe dane\n";
			db.loginToAccount();
			attempts++;
		} while (db.logged != true);
		break;
	case '2':
		do {
			if (!db.registered && attempts > 1) std::cout << "\nLogin jest juz zajety\n";
			db.createAccount();
			attempts++;
		} while (db.registered != true);
		break;
	default:
		std::cout << "Nieprawidlowy znak\n";
		break;
	}

	if (db.logged  || db.registered) 
	{
		system("cls");
		while (true)
		{
			std::cout << "Menedzer hasel\n\n1.Dodaj haslo\n2.Usun haslo\n3.Wyswietl wszystki hasla\n4.Zamknij program\n";
			choice = _getch();
			switch (choice)
			{
			case '1':
				db.insertData();
				break;
			case '2':
				db.deleteData();
				break;
			case '3':
				db.selectData();
				break;
			case '4':
				exit(1);

			default:
				std::cout << "Nieprawidlowy znak\n";
				break;
			}
			_getch();
			system("cls");
			
		}
	}
	system("pause");
}
//todo sql incjector, system cls, walidacja XD