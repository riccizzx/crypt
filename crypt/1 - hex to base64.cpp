
// the challange is convert hex to base64

#include "config.hpp"

std::string base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

std::string char_to_binary(char c) {

	return std::bitset<4>(c).to_string();

}

int binary_hex(char seg) {

	return std::bitset<6>(seg).to_ulong();

}

std::string crypt::hex_to_base64(std::string input){

	printf("\nHex to Base64 Challenge\n");

	// firts get input and convert to binary
	std::string binary_outp = "";
	std::string result = "";

	printf("Hex input: %s", input.c_str());

	for (int i = 0; i < input.length(); i++) {

		binary_outp += char_to_binary(input[i]);

	}

	std::string result_binary = binary_outp.c_str();

	for (size_t i =0; i < binary_outp.length(); i += 6) {

		std::string segment = binary_outp.substr(i, 6);
		
		// while the segment is less than 6 bits, pad with 0s
		while (segment.length() < 6) {
			segment += "0";
		}

		// convert segment to decimal
		int decimal_value = std::bitset<6>(segment).to_ulong();
		
		// get base64 character
		char base64_char = base64_chars[decimal_value];
		result += base64_char;
		//printf("%c", base64_char);

	}

	//printf("Binary output: %s\n", binary_outp.c_str());

	printf("\nBase64 output: %s\n", result.c_str());

	return result.c_str();

}