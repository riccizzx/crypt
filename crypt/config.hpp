
#ifndef		CRYPT_CONFIG_HPP
#define		CRYPT_CONFIG_HPP

#include <stdio.h>
#include <string>
#include <iostream>
#include <bitset>
#include <vector>
#include <fstream>

namespace crypt {
	
	int hex_to_base64();

	int fixed_xor();

	int xor_cipher();

	int single_char_xor();
}

#endif		// CRYPT_CONFIG_HPP