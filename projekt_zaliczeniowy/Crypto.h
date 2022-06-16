#pragma once
#include "cryptlib.h"
#include "rijndael.h"
#include "modes.h"
#include "files.h"
#include "osrng.h"
#include "hex.h"
#include <string>

class Crypto
{
private:
	std::string s1 = "GF7zBC6Qtcmqlp6B";
	std::string s2 = "zgZW7wLwexFYe5Dq";

public:
	std::string encrypt(std::string text);
	std::string decrypt(std::string text);

	std::string base64_encode(std::string input);

	std::string base64_decode(std::string input);

	Crypto();
	~Crypto();
};

