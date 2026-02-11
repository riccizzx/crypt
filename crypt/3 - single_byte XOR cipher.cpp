
#include "config.hpp"

/*
the challange is to decrypt a hex-encoded string that has been XOR'd against a single character.   

*/

int crypt::xor_cipher(){

	std::string hex_encode = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";

	std::string plain_text = "";
	// formula for single byte XOR cipher is:  cipher_text = plain_text XOR 

	char key = 'X';	// we can try all possible keys, but we know that the key is a single character, so we can just try all possible characters

	for (int i =0; i<hex_encode.length(); i+=2) {
		
		// get 2 characters from the hex-encoded string
		std::string byte = hex_encode.substr(i, 2);
		
		// convert to integer
		int int_byte = std::stoi(byte, nullptr, 16);
		
		// xor the integer with the key
		int xor_result = int_byte xor key;
		
		// convert back to character and append to plain text
		char plain_char = static_cast<char>(xor_result);
		plain_text += plain_char;
		
		
	}

	printf(plain_text.c_str());

	return 0;

}