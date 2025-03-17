#include "vm.h"
#include "dispatcher.h"
#include <vector>
#include <iostream>
#include <string>
#include <openssl/aes.h>
#include <openssl/sha.h>
#include <openssl/rand.h>
#include <cstring>

//g++ -fno-rtti -std=c++17 main.cpp vm.cpp handler.cpp -o mainnotstripped -lssl -lcrypto
//strip mainnotstripped -o insobfuscation
#define N 9
std::string ciphertext = "743c9308cc60d9043a2387cda5722e2e83d5e45eb89329d7e3878e08858e334db8e61909183d97ed7f441109be1920e83540219ef6ae9d90585f017c05748fa6801c5188002cd217b381f8cc59c31157e8f35d26e33c3b00cebbc188560edba5";
   
// Valid
/*
int board[N][N] = {
        { 8, 7, 5, 1, 6, 2, 4, 9, 3 },
        { 3, 1, 4, 7, 9, 5, 2, 6, 8 },
        { 6, 9, 2, 8, 4, 3, 1, 5, 7 },
        { 5, 2, 6, 3, 1, 7, 8, 4, 9 },
        { 4, 3, 9, 5, 8, 6, 7, 1, 2 },
        { 1, 8, 7, 4, 2, 9, 5, 3, 6 },
        { 7, 6, 8, 9, 5, 1, 3, 2, 4 },
        { 2, 5, 3, 6, 7, 4, 9, 8, 1 },
        { 9, 4, 1, 2, 3, 8, 6, 7, 5 }
    };
*/
// empty
int board[N][N] = {
        { 0, 0, 0, 1, 0, 2, 0, 0, 0 },
        { 3, 0, 4, 0, 0, 5, 0, 6, 0 },
        { 0, 0, 2, 0, 0, 0, 0, 0, 7 },
        { 0, 0, 6, 3, 0, 0, 0, 4, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 8, 0, 0, 0, 9, 5, 0, 0 },
        { 7, 0, 0, 0, 0, 0, 3, 0, 0 },
        { 0, 5, 0, 6, 0, 0, 9, 0, 1 },
        { 0, 0, 0, 2, 0, 8, 0, 0, 0 }
    };

// solution: 67984317586429517435243917897123687549312869156824238941675

void sha256KeyDerivation(const std::string &inputKey, unsigned char derivedKey[32]) {
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, inputKey.c_str(), inputKey.size());
    SHA256_Final(derivedKey, &sha256);
}

std::string hexToBytes(const std::string &hex) {
    std::string bytes;
    for (size_t i = 0; i < hex.length(); i += 2) {
        unsigned char byte = static_cast<unsigned char>(std::stoi(hex.substr(i, 2), nullptr, 16));
        bytes.push_back(byte);
    }
    return bytes;
}

void aesDecrypt(const std::string &ciphertext, const unsigned char key[32], std::string &decryptedMessage) {
    AES_KEY aesKey;
    AES_set_decrypt_key(key, 256, &aesKey);

    // Extract IV from the beginning of ciphertext
    unsigned char iv[AES_BLOCK_SIZE];
    memcpy(iv, ciphertext.c_str(), AES_BLOCK_SIZE);

    // Extract encrypted data
    size_t encryptedSize = ciphertext.size() - AES_BLOCK_SIZE;
    const unsigned char *encryptedData = reinterpret_cast<const unsigned char *>(ciphertext.c_str() + AES_BLOCK_SIZE);

    // Allocate memory for decrypted data
    unsigned char *decrypted = new unsigned char[encryptedSize];

    // Decrypt in blocks
    AES_cbc_encrypt(encryptedData, decrypted, encryptedSize, &aesKey, iv, AES_DECRYPT);

    // Remove PKCS#7 padding
    size_t paddingLength = decrypted[encryptedSize - 1];
    decryptedMessage.assign(reinterpret_cast<char *>(decrypted), encryptedSize - paddingLength);

    delete[] decrypted;
}

void decode_and_print_flag(char input[61]){
    unsigned char derivedKey[32];
    sha256KeyDerivation(input, derivedKey);
    std::string decryptedMessage;
    aesDecrypt(hexToBytes(ciphertext), derivedKey, decryptedMessage);

    // Print results
    std::cout << decryptedMessage << std::endl;
}


int main() {
    char input[61];
    uint64_t cpu_registers[16] = {};
    printf("Enter the number: ");
    scanf("%59s", input);

    // Start of VM context 1 -> Fill grid with user input
    VM vmContext(0);
    vmContext.entrypoint(cpu_registers);
    uint64_t address = reinterpret_cast<uint64_t>(&board);
    uint64_t input_address = reinterpret_cast<uint64_t>(&input);
    vmContext.setRegister(14, address); // Setup parameter 1
    vmContext.setRegister(13, input_address); // Setup parameter 2
    Dispatcher::execute(&vmContext);
    vmContext.exitpoint(cpu_registers);

    
    // Start of VM context 2 -> Check if input is valid
    VM vmContext2(1);
    vmContext2.entrypoint(cpu_registers);
    address = reinterpret_cast<uint64_t>(&board);
    vmContext2.setRegister(14, address); // Setup parameter 1
    Dispatcher::execute(&vmContext2);
    vmContext2.exitpoint(cpu_registers);

    // If the grid is valid rax is 1 otherwise rax is 0
    if(cpu_registers[0] == 1){
      decode_and_print_flag(input);
    }

    return 0;
}