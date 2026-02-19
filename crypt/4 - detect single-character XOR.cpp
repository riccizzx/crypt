
#include "config.hpp"

int crypt::single_char_xor() {

    std::string linha;
	std::ifstream arquivo("4challange.txt");

    if (arquivo.is_open()) {

        while (getline(arquivo, linha)) {

			crypt::xor_cipher(linha);

        }
        arquivo.close();
    }
    else {
        std::cerr << "Erro ao abrir o arquivo!" << std::endl;
    }

	return 0;

}