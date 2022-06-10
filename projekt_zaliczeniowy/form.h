#pragma once
#include "sqlite/sqlite3.h"

class Form
{
	const char* dir = "projekt.db";
protected:
	string login;
	string password;
public:
	bool logged;
	bool registered;
	bool createAccount();
	bool loginToAccount();
};

