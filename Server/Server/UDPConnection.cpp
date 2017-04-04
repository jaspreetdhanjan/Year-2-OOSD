#include "stdafx.h"

#include "UDPConnection.h"

using namespace Net;

SOCKET socketConnection;
struct sockaddr_in server, si_other;
int slen, recv_len;

const unsigned int packetSize = sizeof(Packet);
char buffer[packetSize]; // Temporary buffer used to store incoming data.

std::vector<ClientData> clients; // Connected clients.

void UDPConnection::createConnection() {
	WSADATA wsa;
	slen = sizeof(si_other);

	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
		printf("Error: %d", WSAGetLastError());
		throw Exception::NET_WINSOCK_INIT_FAIL;
	}

	if ((socketConnection = socket(AF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET) {
		printf("Error: %d", WSAGetLastError());
		throw Exception::NET_WINSOCK_SOCK_FAIL;
	}

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(PORT);

	if (bind(socketConnection, (struct sockaddr *)&server, sizeof(server)) == SOCKET_ERROR) {
		printf("Error: %d", WSAGetLastError());
		throw Exception::NET_WINSOCK_BIND_FAIL;
	}
}

void UDPConnection::receiveDatagrams(void (*onInit)(unsigned const int clientId), void (*onDataEvent)(Packet &dataPacket, unsigned const int clientId)) {
	if ((recv_len = recvfrom(socketConnection, buffer, packetSize, 0, (struct sockaddr *) &si_other, &slen)) == SOCKET_ERROR) {
		printf("Error: %d", WSAGetLastError());
		throw Exception::NET_WINSOCK_INPU_FAIL;
	}

	Packet newPacket(DATA_EVENT, 0);

	crypt(buffer, packetSize);
	newPacket.deserialize(buffer);

	const int token = newPacket.getToken();
	if (token == 0) {
		printf("Blocked packet -> %d ", token);
		return;
	}

	switch (newPacket.getPacketType()) {
		case INIT_CONNECTION: {
			unsigned const int id = getClientID(token);
			onInit(id);
			break;
		}
		case DATA_EVENT: {
			unsigned const int id = getClientID(token);
			onDataEvent(newPacket, id);
			break;
		}
		default: {
			throw Exception::NET_UNKNOWN_PACKET;
		}
	}
}

void UDPConnection::crypt(char *data, const unsigned int dataSize) {
	const char *key = "sdfgJJdRWSGSWGWx";
	int keyLen = 16;

	for (unsigned int i = 0; i < dataSize; i++) {
		data[i] ^= key[i % keyLen];
	}
}

int UDPConnection::getClientID(int token) {
	// Have we stored this client?
	for (unsigned int i = 0; i < clients.size(); i++) {
		if (clients[i].getToken() == token) return (i + 1);
	}

	// If we haven't, add it to the list and return the index.
	ClientData newClient(token, ntohs(si_other.sin_port));
	clients.push_back(newClient);
	return clients.size();
}

void UDPConnection::closeConnection() {
	closesocket(socketConnection);
	WSACleanup();
}

std::vector<ClientData> UDPConnection::getClients() {
	return clients;
}