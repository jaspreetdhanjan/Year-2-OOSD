#pragma once

namespace Net {
	enum PacketType {
		INIT_CONNECTION, // Socket creation type, only used once.
		DATA_EVENT, // For sensory data.
	};

	/*
	* Packet.h
	* AirViewer
	*
	* Holds information related to the sensory data retrieved from the sensors.
	* Created by Jaspreet Dhanjan on 9/01/2017
	*/

	struct Packet {
	private:
		const PacketType packetType;
		const unsigned int token;

	public:
		long long time;
		bool engineFailure;
		double longitude, latitude, altitude;
		double pitch, roll, yaw;
		double speed;

		Packet(PacketType packetType, unsigned int clientToken);

		// Sets packet data with sensors information.
		void setData(long long time, bool engineFailure, double latitude, double longitude, double altitude, double pitch, double roll, double yaw, double speed);

		// Compresses data into char array.
		void serialize(char *data);

		// Replaces object with decompressed array.
		void deserialize(char *data);

		// Gets the type of the packet.
		const PacketType getPacketType();

		// Gets the unique token id of this client.
		const unsigned int getToken();
	};
}