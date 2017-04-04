#include "stdafx.h"

#include "Packet.h"

using namespace Net;

Packet::Packet(PacketType type, unsigned int clientToken) : packetType(type), token(clientToken) {
}

void Packet::setData(long long time, bool engineFailure, double latitude, double longitude, double altitude, double pitch, double roll, double yaw, double speed) {
	this->time = time;
	this->engineFailure = engineFailure;
	this->latitude = latitude;
	this->longitude = longitude;
	this->altitude = altitude;
	this->pitch = pitch;
	this->roll = roll;
	this->yaw = yaw;
	this->speed = speed;
}

void Packet::serialize(char *data) {
	memcpy(data, this, sizeof(Packet));
}

void Packet::deserialize(char *data) {
	memcpy(this, data, sizeof(Packet));
}

const PacketType Packet::getPacketType() {
	return packetType;
}

const unsigned int Packet::getToken() {
	return token;
}