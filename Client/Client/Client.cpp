#include "stdafx.h"

#include "Client.h"

Net::UDPConnection *udpConnection;

const unsigned int bufferSize = sizeof(Net::Packet);
char buffer[bufferSize];
Sensors::Sensor** sensors = new Sensors::Sensor*[5];
unsigned int clientToken;

void Client::init() {
	udpConnection->createConnection();

	srand(time(0));
	clientToken = Random::nextInt() + 1;

	sensors[0] = Sensors::Clock::getInstance();
	sensors[1] = Sensors::EngineSensor::getInstance();
	sensors[2] = Sensors::GPSSensor::getInstance();
	sensors[3] = Sensors::OrientationSensor::getInstance();
	sensors[4] = Sensors::SpeedSensor::getInstance();

	// Establish the connection.
	sendData(Net::Packet(Net::INIT_CONNECTION, clientToken));
}

void Client::sendData(Net::Packet &packet) {
	memset(buffer, 0, bufferSize);
	packet.serialize(buffer);
	udpConnection->sendData(buffer, bufferSize);
}

void Client::retrieveAndSet(Net::Packet &packet) {
	Sensors::Clock clock = *Sensors::Clock::getInstance();
	Sensors::EngineSensor engineSensor = *Sensors::EngineSensor::getInstance();
	Sensors::SpeedSensor speedSensor = *Sensors::SpeedSensor::getInstance();
	Sensors::Data::GPSData gpsData = Sensors::GPSSensor::getInstance()->getData();
	Sensors::Data::OrientationData oriData = Sensors::OrientationSensor::getInstance()->getData();

	long long time = clock.getTime();
	bool engineStatus = engineSensor.hasFailed();
	double speed = speedSensor.getSpeed();
	double latitude = gpsData.getLatitude();
	double longitude = gpsData.getLongitude();
	double altitude = gpsData.getAltitude();
	double pitch = oriData.getPitch();
	double roll = oriData.getRoll();
	double yaw = oriData.getYaw();

	packet.setData(time, engineStatus, latitude, longitude, altitude, pitch, roll, yaw, speed);
}

void Client::tick() {
	for (int i = 0; i < 5; i++) {
		sensors[i]->update();
	}

	std::cout << "Transmitting data to server..." << std::endl;

	Net::Packet packet(Net::DATA_EVENT, clientToken);
	retrieveAndSet(packet);
	sendData(packet);

	std::cout << "Transmission complete!" << std::endl << std::endl;
}

void Client::stop() {
	udpConnection->closeConnection();
}