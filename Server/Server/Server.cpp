// Server.cpp : Defines the entry point for the console application.

#include "stdafx.h"

#include <ctime>

#include "Server.h"

Net::UDPConnection *udpConnection;

std::vector<class Observer*> observers;
FileWriter *fileWriter = new FileWriter();
Alarm *alarm = new Alarm();

void printToScreen(Net::Packet &dataPacket, unsigned const int clientId) {
	long long second = (dataPacket.time / 1000) % 60;
	long long minute = (dataPacket.time / (1000 * 60)) % 60;
	long long hour = (dataPacket.time / (1000 * 60 * 60)) % 24;

	std::cout << "----- Data recieved from Airplane: " << clientId << ", at time: " << hour << ":" << minute << ":" << second << " -----\n";

	if (!dataPacket.engineFailure) std::cout << "Engines working" << "!\n";
	else std::cout << "Engines not working!" << "!\n";

	std::cout << "Travelling at loc(" << dataPacket.latitude << ", " << dataPacket.altitude << ", " << dataPacket.longitude << ")\n";
	std::cout << "Travelling at axes(" << dataPacket.pitch << ", " << dataPacket.yaw << ", " << dataPacket.roll << ")\n";
	std::cout << "With speed: " << dataPacket.speed << "m/s\n";

	std::cout << "----- End of transmission -----\n\n";
}

void onPacketInit(unsigned const int clientId) {
	std::cout << "Established connection with Airplane: " << clientId << std::endl;
	Sound::SoundManager::playSound(Sound::ALERT_SOUND_1);
}

void onPacketData(Net::Packet &dataPacket, unsigned const int clientId) {
	printToScreen(dataPacket, clientId);

	for (unsigned int i = 0; i < observers.size(); i++) {
		observers[i]->notify(clientId, dataPacket);
	}
}

void Server::init() {
	try {
		udpConnection->createConnection();
	}
	catch (Exception::Error e) {
		std::cout << Exception::ErrorUtil::getError(e) << std::endl;
		exit(EXIT_FAILURE);
	}

	observers.push_back(fileWriter);
	observers.push_back(alarm);
}

void Server::tick() {
	alarm->tick();
}

void Server::incomingTrafficTick() {
	try {
		udpConnection->receiveDatagrams(&onPacketInit, &onPacketData);
	}
	catch (Exception::Error e) {
		std::cout << Exception::ErrorUtil::getError(e) << std::endl;
		exit(EXIT_FAILURE);
	}
}

void Server::stop() {
	try {
		// Destroy the UDP connection.
		udpConnection->closeConnection();
	}
	catch (Exception::Error e) {
		std::cout << Exception::ErrorUtil::getError(e) << std::endl;
		exit(EXIT_FAILURE);
	}

	delete udpConnection;

	// Delete the observers.
	delete fileWriter;
	delete alarm;
}