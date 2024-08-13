#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

// Rastgele özel anahtar üretme fonksiyonu
std::string generatePrivateKey(int length) {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    std::string privateKey;
    privateKey.reserve(length);

    for (int i = 0; i < length; ++i) {
        privateKey += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return privateKey;
}

int main() {
    // Rastgele özel anahtar üret
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::string privateKey = generatePrivateKey(64); // Özel anahtar uzunluğunu istediğiniz gibi ayarlayabilirsiniz

    // Özel anahtarı bir dosyaya yaz
    std::ofstream outputFile("cold_wallet_private_key.txt");
    if (outputFile.is_open()) {
        outputFile << privateKey;
        outputFile.close();
        std::cout << "Cold wallet özel anahtarınız başarıyla oluşturuldu ve 'cold_wallet_private_key.txt' dosyasına kaydedildi." << std::endl;
    }
    else {
        std::cerr << "Dosya oluşturulurken bir hata oluştu." << std::endl;
        return 1;
    }

    return 0;
}