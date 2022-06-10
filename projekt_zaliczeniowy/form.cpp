#include "form.h"
#include "database.h"
#include <stdio.h>


bool isUser = false;

static int callback(void* NotUsed, int argc, char** argv, char** azColName)
{
	for (int i = 0; i < argc; i++) {
		if (atoi(argv[i]) == 1) isUser = true;
	}

	return 0;
}

bool Form::createAccount() {
	sqlite3* db;
	char* msgError;
	cout << "Podaj login: "; cin >> login;
	cout << "podaj haslo: "; cin >> password;
	string sql = "INSERT INTO USERS (login, haslo) VALUES ('" + login + "','" + password + "'); ";
	int exit = sqlite3_open(dir, &db);
	exit = sqlite3_exec(db, sql.c_str(), NULL, 0, &msgError);
	if (exit != SQLITE_OK)
	{
		registered = false;
		return false;
	}
	else
	{
		registered = true;
		return registered;
	}
}
bool Form::loginToAccount() {
	sqlite3* db;
	char* msgError;
	int count = 0;
	cout << "Podaj login: "; cin >> login;
	cout << "podaj haslo: "; cin >> password;
	string sql = "select count(*) from users where login = '"+login+"' and haslo = '"+password+"'";
	int exit = sqlite3_open(dir, &db);
	exit = sqlite3_exec(db, sql.c_str(), callback, 0, &msgError);
	if (isUser) {
		logged = true;
		return logged;
	}
	else return false;
}
