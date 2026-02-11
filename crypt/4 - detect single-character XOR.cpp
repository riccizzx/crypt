
#include "config.hpp"

void ler_arquivo(const std::string& nomeArquivo) {
    
    std::ifstream arquivo(nomeArquivo);
    std::string linha;

    if (arquivo.is_open()) {
        std::cout << "--- Conteudo do Arquivo ---" << std::endl;
        while (std::getline(arquivo, linha)) {
            std::cout << linha << std::endl; // Exibe a linha lida
        }

        arquivo.close(); // Fecha o arquivo

    }

    else {

        std::cerr << "Erro ao abrir o arquivo para leitura!" << std::endl;
    
    }

}


int crypt::single_char_xor() {

	// open the file and read the contents into a string

	std::string arq = "4-challange.txt";

	ler_arquivo(arq);

	return 0;

}