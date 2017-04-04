#pragma once

#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <stdio.h>
#include <winsock2.h>
#include <vector>

#include "Packet.h"
#include "ClientData.h"
#include "Error.h"

#pragma comment(lib,"ws2_32.lib")

#define PORT 8888

/*
*	UDPConnection.h
*	AirViewer
*
*	Creates a one-way UDP connection with a client, only recieves data.
*	Sourced from: http://www.binarytides.com/udp-socket-programming-in-winsock
*	Created by Jaspreet Dhanjan on 09/01/2017.
*/
namespace Net {
	class UDPConnection {
	private:
		// Gets the index of the client, if the token has been stored, otherwise generate one.
		int getClientID(int token);

		// XOR Encrypt/ Decrypt tool.
		void crypt(char *data, const unsigned int dataSize);
	public:
		// Creates and initialises the UDP connection.
		void createConnection();

		// Recieves incoming packets.
		void receiveDatagrams(void(*onInit)(unsigned const int clientId), void(*onDataEvent)(Packet &dataPacket, unsigned const int clientId));

		// Destroys the connection.
		void closeConnection();

		// Stores all connected clients
		std::vector<ClientData> getClients();
	};
}