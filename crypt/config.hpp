
#ifndef		CRYPT_CONFIG_HPP
#define		CRYPT_CONFIG_HPP

#include <stdio.h>
#include <string>
#include <iostream>
#include <bitset>



namespace crypt {
	
	int hex_to_base64();

	int fixed_xor();

	int xor_cipher();

}

#endif		// CRYPT_CONFIG_HPP