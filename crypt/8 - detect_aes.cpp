
#include "config.hpp"

int crypt::detect_aes() {

	std::ifstream file("8challange.txt");

	if (!file.is_open()) {
		std::cout << "failed in open file 8";
	}

	std::string line;
	std::string base64;

	while (getline(file, line))
		base64 += line;

	file.close();

	resolution(base64); // it will crash

	return 0;
}