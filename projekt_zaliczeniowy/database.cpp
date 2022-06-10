#include "database.h"
#include "sqlite/sqlite3.h"
#include <iostream>
#include <Windows.h>
static int callback(void* NotUsed, int argc, char** argv, char** azColName);
static int callback2(void* NotUsed, int argc, char** argv, char** azColName);
bool isUser = false;

void Database::deleteData() {
	string ID;
	std::cout << "Podaj ID hasla ktore chcesz usunac: "; std::cin >> ID;
	if(ID.length()==0) std::cout<<"Wpisz ID\n";
	string sql = "DELETE FROM PASSWORDS WHERE ID="+ID+"; ";
	int exit = sqlite3_open(dir, &db);
	exit = sqlite3_exec(db, sql.c_str(), callback, NULL, &msgError);
	if (exit != SQLITE_OK) {
		std::cerr << "Nie udalo sie usun¹æ.\n";
		sqlite3_free(msgError);
	}
	else
		std::cout << "Usunieto pomyslnie.\n";
}

void Database::insertData() {
	string password, website;
	std::cout << "Podaj strone do ktorej haslo chcesz zapisac: "; std::cin >> website;
	std::cout << "Podaj haslo: "; std::cin >> password;

	string sql("INSERT INTO PASSWORDS (login, haslo, strona) VALUES ('"+login+"','"+password+"','" + website + "'); ");

	int exit = sqlite3_open(dir, &db);
	exit = sqlite3_exec(db, sql.c_str(), NULL, 0, &msgError);
	if (exit != SQLITE_OK) {
		std::cerr << "Nie uda³o siê dodaæ.\n";
		sqlite3_free(msgError);
	}
	else
		std::cout << "Pomyslnie dodano\n";
}

void Database::selectData() {
	
	string sql = "SELECT * FROM PASSWORDS WHERE LOGIN = '"+login+"';";
	int exit = sqlite3_open(dir, &db);

	exit = sqlite3_exec(db, sql.c_str(), callback, NULL, &msgError);
	if (exit != SQLITE_OK) {
		std::cerr << "Nie uda³o siê wyswietlic danych\n";
		sqlite3_free(msgError);
	}
}
 
void Database::createAccount() {
	std::cout << "Podaj login: "; std::cin >> login;
	std::cout << "podaj haslo: "; std::cin >> password;
	system("cls");
	int exit = sqlite3_open(dir, &db);
	string sql = "INSERT INTO USERS (login, haslo) VALUES ('" + login + "','" + password + "'); ";
	
	exit = sqlite3_exec(db, sql.c_str(), NULL, 0, &msgError);
	if (exit != SQLITE_OK) registered = false;
	else registered = true;
}

void Database::loginToAccount() {
	int count = 0;

	std::cout << "Podaj login: "; std::cin >> login;
	std::cout << "podaj haslo: "; std::cin >> password;
	system("cls");
	string sql = "select count(*) from users where login = '" + login + "' and haslo = '" + password + "'";
	int exit = sqlite3_open(dir, &db);

	exit = sqlite3_exec(db, sql.c_str(), callback2, 0, &msgError);
	if (isUser) logged = true;
	else logged = false;
}

static int callback(void* NotUsed, int argc, char** argv, char** azColName)
{
	for (int i = 0; i < argc; i++) {
		std::cout <<azColName[i]<<": " << argv[i] << ", ";
	}

	std::cout << std::endl;

	return 0;
}

static int callback2(void* NotUsed, int argc, char** argv, char** azColName)
{
	for (int i = 0; i < argc; i++) {
		if (atoi(argv[i]) == 1) isUser = true;
	}

	return 0;
}
