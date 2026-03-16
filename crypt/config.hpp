
#ifndef		CRYPT_CONFIG_HPP
#define		CRYPT_CONFIG_HPP

#include <stdio.h>
#include <string>
#include <iostream>
#include <bitset>
#include <vector>
#include <fstream>
#include <map>

namespace crypt {
	
	std::string hex_to_base64(std::string input);

	int fixed_xor();

	int xor_cipher(std::string str);

	int single_char_xor();

	int repeating_keyxor();

	int break_repeating_keyxor();

	int ecb();
	int resolution(std::string base_64); // for the challange 7/8

	int detect_aes();
}

#endif		// CRYPT_CONFIG_HPP