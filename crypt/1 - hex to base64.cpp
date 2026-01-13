
// the challange is convert hex to base64

#include "config.hpp"

std::string base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

std::string char_to_binary(char c) {

	return std::bitset<4>(c).to_string();

}

int binary_hex(char seg) {

	return std::bitset<6>(seg).to_ulong();

}

int hex_to_base64(){

	printf("\nHex to Base64 Challenge\n");

	// firts get input and convert to binary
	std::string str_input = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
	std::string binary_outp = "";
	std::string result = "";

	printf("Hex input: %s", str_input.c_str());

	for (int i = 0; i < str_input.length(); i++) {

		binary_outp += char_to_binary(str_input[i]);

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

	return 0;

}