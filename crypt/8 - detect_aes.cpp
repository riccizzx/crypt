#include "config.hpp"
#include <sstream>
#include <unordered_map>

int crypt::detect_aes() {

	std::ifstream file("8challange.txt");

	if (!file.is_open()) {
		std::cout << "failed in open file 8";
		return 1;
	}

	std::string line;
	size_t line_no = 0;

	// Percorre cada linha (cada ciphertext hex) e verifica blocos repetidos de 16 bytes (ECB)
	while (getline(file, line)) {
		line_no++;
		// Ignorar linhas vazias
		if (line.empty()) continue;

		// Converte hex string para bytes
		std::vector<unsigned char> bytes;
		bytes.reserve(line.size() / 2);
		for (size_t i = 0; i + 1 < line.size(); i += 2) {
			std::string byteStr = line.substr(i, 2);
			std::istringstream iss(byteStr);
			unsigned int b = 0;
			iss >> std::hex >> b;
			bytes.push_back(static_cast<unsigned char>(b & 0xFF));
		}

		// Conta ocorrências de cada bloco de 16 bytes
		std::unordered_map<std::string, int> blockCounts;
		bool foundEcb = false;
		for (size_t i = 0; i + 15 < bytes.size(); i += 16) {
			std::string block(reinterpret_cast<const char*>(bytes.data() + i), 16);
			int& count = blockCounts[block];
			count++;
			if (count > 1) {
				foundEcb = true;
				break;
			}
		}

		// Se detectou ECB, imprime a linha e sai
		if (foundEcb) {
			std::cout << "ECB detected on line " << line_no << ":\n" << line << std::endl;
			file.close();
			return 0;
		}

	}
	file.close();

	std::cout << "No ECB detected\n";
	return 0;
}