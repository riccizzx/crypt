
#include "config.hpp"

#include <string>
#include <cstdint>

int bit_count(uint8_t x) {
	int c = 0;
	while (x) { c++; x &= (x - 1); }
	return c;
}

int distance(const std::string& a, const std::string& b) {
	size_t n = std::min(a.size(), b.size());
	int dist = 0;
	for (size_t i = 0; i < n; ++i) {
		uint8_t xa = static_cast<uint8_t>(a[i]);
		uint8_t xb = static_cast<uint8_t>(b[i]);
		dist += bit_count(xa ^ xb);
	}

	for (size_t i = n; i < a.size(); ++i) dist += bit_count(static_cast<uint8_t>(a[i]));
	for (size_t i = n; i < b.size(); ++i) dist += bit_count(static_cast<uint8_t>(b[i]));
	return dist;

}

int crypt::break_repeating_keyxor() {
	// read the file, i do this after

	char key = 10;
	int KEYSIZE = sizeof(key);

	std::string text_1 = "this is a test";
	std::string text_2 = "wokka wokka!!!";

	int distancia =  distance(text_1, text_2);

	// the distance is returning 37, so its right.

	/*
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
	*/

	return 0;

}