#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cryptopp/sha.h>
#include <cryptopp/hex.h>
#include <cryptopp/files.h>

using namespace CryptoPP;

std::string calculateFileHash(const std::string& filePath)
{
    SHA256 hash;
    std::string digest;

    try {
        FileSource file(filePath.c_str(), true, new HashFilter(hash, new HexEncoder(new StringSink(digest))));
    } catch (const Exception& ex) {
        std::cerr << "Crypto++ exception: " << ex.what() << std::endl;
    }

    return digest;
}

int main()
{
    std::string filePath = "/home/stud/C++Projects/Education/KarginNikita/EXMPL.txt"; // Замените на путь к вашему файлу
    std::string hashResult = calculateFileHash(filePath);

    if (!hashResult.empty()) {
        std::cout << "SHA-256 Hash of file " << filePath << ": " << hashResult << std::endl;
    } else {
        std::cerr << "Failed to calculate hash." << std::endl;
        return 1;
    }

    return 0;
}
