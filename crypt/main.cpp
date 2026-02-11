
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
			crypt::hex_to_base64();
			break;

		case '2':
			crypt::fixed_xor();
			break;

		case '3':
			crypt::xor_cipher();
			break;

		case '4':
			crypt::single_char_xor();
			break;
			
		default:
			std::cout << "invalid choice\n";
	
	}

}