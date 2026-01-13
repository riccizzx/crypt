
#include "config.hpp"

int main() {

	std::cout << "select a challange to run: \n";
	std::cout << "between 1 and 8\n";
	char choice;

	std::cin >> choice;

	switch (choice) {
	
		case '1':
			hex_to_base64();
			break;
		case '2':
			fixed_xor();
			break;

		default:
			std::cout << "invalid choice\n";
	
	}

}