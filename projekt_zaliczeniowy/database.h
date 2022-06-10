#pragma once
#include "sqlite/sqlite3.h"
#include <iostream>
using namespace std;

class Database
{
	const char* dir = "projekt.db";
	sqlite3* db;
	char* msgError;
	string login;
	string password;
public:
	bool logged;
	bool registered;
	void createDB();
	void createTable();
	void deleteData();
	void insertData();
	void selectData();
	void createAccount();
	void loginToAccount();

};

