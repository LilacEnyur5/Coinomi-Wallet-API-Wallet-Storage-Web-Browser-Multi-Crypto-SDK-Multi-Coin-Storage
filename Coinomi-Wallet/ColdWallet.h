#ifndef COLD_WALLET_H
#define COLD_WALLET_H

#include <string>

class ColdWallet {
public:
    ColdWallet();
    std::string generatePrivateKey(int length);
    void savePrivateKeyToFile(const std::string& filename);

private:
    std::string privateKey;
};

#endif // COLD_WALLET_H