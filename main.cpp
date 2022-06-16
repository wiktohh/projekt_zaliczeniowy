#include <iostream>
#include "database.h"
#include <conio.h>
#include <stdlib.h>
void menu() {

}
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
			std::cout << "Menedzer hasel\n\n1.Dodaj haslo\n2.Usun haslo\n3.Zmien Haslo\n4.Wyswietl wszystkie hasla\n5.Wyswietl haslo po id lub nazwie\n6.Zamknij program\n";
			choice = _getch();
			std::cout << "------------------------------------------------------------" << std::endl;
			switch (choice)
			{
			case '1':
				db.insertData();
				break;
			case '2':
				db.deleteData();
				break;
			case '3':
				db.changePassword();
				break;
			case '4':
				db.selectData();
				break;
			case '5':
				db.selectOne();
				break;
			case '6':
				exit(1);

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
//todo sql incjector, system cls, walidacja XD
//mozliwosc zmiany hasel
//walidacja tworzenia by nie dalo sie zrobic dwoch użytkowników z tym samym haslem