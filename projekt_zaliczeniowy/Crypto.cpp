#include "AES.h"
#include "cryptlib.h"
#include "rijndael.h"
#include "modes.h"
#include "files.h"
#include "osrng.h"
#include "hex.h"

#include <string>
#include "Crypto.h"
#include "base64.h"

using namespace CryptoPP;

std::string Crypto::encrypt(std::string text)
{
    SecByteBlock key((const byte*)s1.data(), s1.size());
    SecByteBlock iv((const byte*)s2.data(), s2.size());

    AES::Encryption aesEncryption(key, s1.size());
    CBC_Mode_ExternalCipher::Encryption cbcEncryption(aesEncryption, iv);

    std::string encrypted; encrypted.reserve(text.size() + 16);
    StreamTransformationFilter stfEncryptor(cbcEncryption, new StringSink(encrypted));
    stfEncryptor.Put(reinterpret_cast<const unsigned char*>(text.c_str()), text.length());
    stfEncryptor.MessageEnd();

    std::string encoded = base64_encode(encrypted);
    return encoded;
}

std::string Crypto::decrypt(std::string text)
{
    SecByteBlock key((const byte*)s1.data(), s1.size());
    SecByteBlock iv((const byte*)s2.data(), s2.size());

    std::string decoded = base64_decode(text);
    std::string decrypted; decrypted.reserve(decoded.size());

    AES::Decryption aesDecryption(key, key.size());
    CBC_Mode_ExternalCipher::Decryption cbcDecryption(aesDecryption, iv);

    StreamTransformationFilter stfDecryptor(cbcDecryption, new StringSink(decrypted));
    stfDecryptor.Put(reinterpret_cast<const unsigned char*>(decoded.c_str()), decoded.size());
    stfDecryptor.MessageEnd();

    return decrypted;
}

std::string Crypto::base64_encode(std::string input)
{
    std::string result;
    CryptoPP::StringSource(input, true, new CryptoPP::Base64Encoder(new CryptoPP::StringSink(result)));
    return result;
}

std::string Crypto::base64_decode(std::string input)
{
    std::string result;
    CryptoPP::StringSource(input, true, new CryptoPP::Base64Decoder(new CryptoPP::StringSink(result)));
    return result;
}


Crypto::Crypto(){}

Crypto::~Crypto(){}
