
#include "config.hpp"
#include "usage.hpp"


int main() {

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

		default:
			std::cout << "invalid choice\n";
	
	}

}