#pragma once
#include "sqlite/sqlite3.h"
#include <iostream>
#include "Crypto.h"

using namespace std;

class Database
{
	const char* dir = "projekt.db";
	sqlite3* db;
	Crypto crypto;
	char* msgError;
	string login;
	string password;
public:
	bool logged;
	bool registered;
	void deleteData();
	void insertData();
	void selectData();
	void selectOne();
	void createAccount();
	void loginToAccount();

	Database();
	~Database();

};

