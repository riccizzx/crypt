
#ifndef		CRYPT_SERVER_HPP
#define		CRYPT_SERVER_HPP

#include "config.hpp"

// winsock server api

#include <WS2tcpip.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

namespace net {

	class server
		{
	
		private:
			WSADATA ws;
			SOCKET sock;
			sockaddr_in hint;
		
		public:
			server(int port);
			~server();

			void run();

	};

}

#endif