#include "stdafx.h"

#include "UDPConnection.h"

using namespace Net;

struct sockaddr_in socketAddress;
int socketConnection, socketConnectionLength;

const unsigned int BYTES_PER_MEGABYTE = 1000000;
const unsigned int MAX_TRANSMISSION = 5 * BYTES_PER_MEGABYTE; // Max 5mb limit per hour.

unsigned int currentDataUsage = 0; // Data usage and timer variables.
long long lastTime;
bool initClock = false;

void UDPConnection::createConnection() {
	socketConnectionLength = sizeof(socketAddress);
	WSADATA wsa;

	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
		printf("Failed startup. Error code: %d", WSAGetLastError());
		exit(EXIT_FAILURE);
	}

	if ((socketConnection = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == SOCKET_ERROR) {
		printf("socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP) failed! Error code: %d", WSAGetLastError());
		exit(EXIT_FAILURE);
	}

	memset((char *)&socketAddress, 0, sizeof(socketAddress));
	socketAddress.sin_family = AF_INET;
	socketAddress.sin_port = htons(PORT);
	socketAddress.sin_addr.S_un.S_addr = inet_addr(SERVER);
}

void UDPConnection::crypt(char *data, const unsigned int dataSize) {
	const char *key = "sdfgJJdRWSGSWGWx";
	int keyLen = 16;

	for (unsigned int i = 0; i < dataSize; i++) {
		data[i] ^= key[i % keyLen];
	}
}

void UDPConnection::sendData(char *data, const unsigned int dataSize) {
	if (!initClock) {
		initClock = true;
		lastTime = Time::getTime();
	}

	long long nowTime = Time::getTime();
	if ((nowTime - lastTime) > Time::MILLIS_PER_SECOND * 60 * 60) {
		lastTime = nowTime;
		currentDataUsage = 0;
	}
	
	// Check if the data limit has been reached.
	if (currentDataUsage > MAX_TRANSMISSION) {
		printf("MAX DATA LIMIT REACHED!");
		return;
	}
	currentDataUsage += dataSize;

	// Encrpyt the *serialised* data.
	crypt(data, dataSize);

	// Send the data.
	if (sendto(socketConnection, data, dataSize, 0, (struct sockaddr *) &socketAddress, socketConnectionLength) == SOCKET_ERROR) {
		printf("sendto() failed with error code: %d", WSAGetLastError());
		exit(EXIT_FAILURE);
	}
}

void UDPConnection::closeConnection() {
	closesocket(socketConnection);
	WSACleanup();
}