
#include "config.hpp"

/*
the challange is to decrypt a hex-encoded string that has been XOR'd against a single character.   

*/

int crypt::xor_cipher(std::string hex_encode){

	int best_score = -999999;
	std::string best_text;
	int best_key = 0;

	for (int k = 0; k <= 255; k++) {

		std::string plain_text;

		for (int i = 0; i < hex_encode.length(); i += 2) {

			// get 2 characters from the hex-encoded string
			std::string byte = hex_encode.substr(i, 2);

			// convert to integer
			int int_byte = std::stoi(byte, nullptr, 16);

			// xor the integer with the key
			unsigned char xor_result = int_byte xor k;

			// convert back to character and append to plain text
			char plain_char = static_cast<char>(xor_result);
			plain_text += plain_char;

		}
		
		int score = 0;

		for (char c : plain_text) {

			unsigned char uc = static_cast<unsigned char>(c);

			if (std::isalpha(uc)) score += 2;
			else if (uc == ' ') score += 3;
			else if (!std::isprint(uc)) score -= 5;
		
		}
		
		if (score > best_score) {
			best_score = score;
			best_text = plain_text;
			best_key = k;
		}
	
	}
	
	std::cout << "best key: " << best_key << "\n";
	std::cout << "best text: " << best_text << "\n";

	return 0;

}