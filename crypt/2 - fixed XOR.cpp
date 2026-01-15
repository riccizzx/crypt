
#include "config.hpp"

// fixed XOR

int crypt::fixed_xor() {

	std::string buffer_1 = "1c0111001f010100061a024b53535009181c";
	std::string buffer_2 = "686974207468652062756c6c277320657965";

	for (int i =0; i<= buffer_1.length()-1; i+=2) {
		
		// get 2 characters from each buffer
		std::string byte_1 = buffer_1.substr(i, 2);
		std::string byte_2 = buffer_2.substr(i, 2);

		
		// convert to integer
		int int_1 = std::stoi(byte_1, nullptr, 16);
		int int_2 = std::stoi(byte_2, nullptr, 16);

		
		// xor the integers
		int xor_result = int_1 xor int_2;


		// convert back to hex
		printf("%02x", xor_result);
	
	}

	return 0;

}