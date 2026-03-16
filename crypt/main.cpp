
#include "config.hpp"
#include "usage.hpp"


int main() {

	std::cout << "this program is a collection of solutions to the cryptopals challenges. The challenges are organized in 8 sets,";
	std::cout << "each set contains 8 challenges.";
	std::cout << "The challenges are designed to be solved in order, but you can skip around if you want.\n\n";

	usage();

	char choice;
	std::cin >> choice;

	switch (choice) {

		case '1':
#define str "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d"
			crypt::hex_to_base64(str);
			break;

		case '2':
			crypt::fixed_xor();
			break;

		case '3':
#define hex_encode "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736"
			crypt::xor_cipher(hex_encode);
			break;

		case '4':
			crypt::single_char_xor();
			break;
			
		case '5':
			crypt::repeating_keyxor();
			break;

		case '6':
			crypt::break_repeating_keyxor();
			break;

		case '7':
			crypt::ecb();
			break;

		case '8':
			crypt::detect_aes();
			break;

		default:
			std::cout << "invalid choice\n";

	}

	return 0;
}