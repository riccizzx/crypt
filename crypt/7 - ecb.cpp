
#include "config.hpp"

#include <openssl/evp.h>
#include <openssl/aes.h>

std::vector<unsigned char> base64_decode(const std::string& input)
{
    std::vector<unsigned char> buffer(input.size());

    int len = EVP_DecodeBlock(buffer.data(),
        (const unsigned char*)input.c_str(),
        input.size());

    buffer.resize(len);
    return buffer;
}

int crypt::resolution(std::string base_64)
{
    // base64 decode
    std::vector<unsigned char> ciphertext = base64_decode(base_64);

    unsigned char key[] = "YELLOW SUBMARINE";

    std::vector<unsigned char> plaintext(ciphertext.size());

    AES_KEY aes_key;
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    EVP_DecryptInit_ex(ctx, EVP_aes_128_ecb(), nullptr, key, nullptr);

    int out_len1 = 0;
    int out_len2 = 0;

    EVP_DecryptUpdate(ctx, plaintext.data(), &out_len1, ciphertext.data(), (int)ciphertext.size());
    EVP_DecryptFinal_ex(ctx, plaintext.data() + out_len1, &out_len2);

    EVP_CIPHER_CTX_free(ctx);

    std::cout << std::string(plaintext.begin(), plaintext.end());

    return 0;
}

int crypt::ecb()
{
    std::ifstream file("7challange.txt");

    if (!file) {
        std::cout << "error opening file\n";
        return 1;
    }

    std::string line;
    std::string base64;

    while (getline(file, line))
        base64 += line;

    file.close();

    // base64 decode
    resolution(base64);

    return 0;

}