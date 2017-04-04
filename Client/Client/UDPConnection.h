#pragma once

#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <stdio.h>
#include <winsock2.h>

#include "Time.h"

#pragma comment(lib,"ws2_32.lib")

#define SERVER "127.0.0.1"
#define BUFLEN 512
#define PORT 8888

/*
* UDPConnection.h
* AirViewer
*
* Creates a one-way UDP connection with a client, only send data.
* Sourced from: http://www.binarytides.com/udp-socket-programming-in-winsock
* Created by Jaspreet Dhanjan on 09/01/2017.
*/

namespace Net {
	class UDPConnection {
	private:
		// XOR Encrypt/ Decrypt tool.
		void crypt(char *data, const unsigned int dataSize);

	public:
		// Creates and initialises the UDP connection.
		void createConnection();

		// Recieves incoming packets.
		void sendData(char *data, const unsigned int dataSize);

		// Destroys the connection.
		void closeConnection();
	};
}