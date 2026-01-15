
#include "config.hpp"
#include "server.hpp"

net::server::server(int port) {

	if (WSAStartup(MAKEWORD(2, 2), &ws) !=0) {
	
		std::cerr << "error in start wsa api\n";
		exit(EXIT_FAILURE);
	
	}

	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == INVALID_SOCKET) {
	
		std::cerr << "error creating socket\n";
		WSACleanup();
		exit(EXIT_FAILURE);
	
	}


}

net::server::~server() {
	
	WSACleanup();

}

void net::server::run() {



}
