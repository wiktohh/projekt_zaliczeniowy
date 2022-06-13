#include "AES.h"
#include "cryptlib.h"
#include "rijndael.h"
#include "modes.h"
#include "files.h"
#include "osrng.h"
#include "hex.h"

#include <string>
#include "Crypto.h"

using namespace CryptoPP;

std::string Crypto::encrypt(std::string text)
{
    SecByteBlock key((const byte*)s1.data(), s1.size());
    SecByteBlock iv((const byte*)s2.data(), s1.size());

    std::string cipher;
    try
    {
        CBC_Mode< AES >::Encryption e;
        e.SetKeyWithIV(key, key.size(), iv);

        StringSource s(text, true,
            new StreamTransformationFilter(e,
                new StringSink(cipher)
            )
        );
    }
    catch (const Exception& e)
    {
        std::cerr << e.what() << std::endl;
        exit(1);
    }

    return cipher;
}

std::string Crypto::decrypt(std::string text)
{
    SecByteBlock key((const byte*)s1.data(), s1.size());
    SecByteBlock iv((const byte*)s2.data(), s1.size());

    std::string recovered;
    try
    {
        CBC_Mode< AES >::Decryption d;
        d.SetKeyWithIV(key, key.size(), iv);

        StringSource s(text, true,
            new StreamTransformationFilter(d,
                new StringSink(recovered)
            ) // StreamTransformationFilter
        ); // StringSource

    }
    catch (const Exception& e)
    {
        std::cerr << e.what() << std::endl;
        exit(1);
    }

    return recovered;
}


Crypto::Crypto(){}

Crypto::~Crypto(){}
