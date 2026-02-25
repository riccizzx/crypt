
#include "config.hpp"

// repeating-key XOR


int crypt::repeating_keyxor() {

	std::string key = "ICE";
	std::vector<int> asci_key;

	std::string text = "Burning 'em, if you ain't quick and nimble\nI go crazy when I hear a cymbal";
	// convert key to ascii
	for (char character : key) {
		asci_key.push_back((int)character);
	}
	
	for (int i = 0; i < text.size(); i++) {
		int ascii_value = (int)text[i];
		int key_value = asci_key[i % key.size()];
		int xor_value = ascii_value ^ key_value;
		printf("%02x", xor_value);
	}

	return 0;

}
