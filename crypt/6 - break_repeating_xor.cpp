
#include "config.hpp"

int crypt::break_repeating_keyxor() {
	std::string linha;
	std::ifstream arquivo("6challange.txt");
	std::string cipher_text;

	if (arquivo.is_open()) {
		while (getline(arquivo, linha)) {
			cipher_text += linha;
		}
		std::cout << cipher_text << std::endl;
		arquivo.close();

	}
	else {
		std::cerr << "Erro ao abrir o arquivo!" << std::endl;
	}
	return 0;

}