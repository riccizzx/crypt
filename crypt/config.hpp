
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
	
	int hex_to_base64();

	int fixed_xor();

	int xor_cipher(std::string str);

	int single_char_xor();

	int repeating_keyxor();

	int break_repeating_keyxor();

}

#endif		// CRYPT_CONFIG_HPP