#pragma once

#include <iostream>

#include "Packet.h"
#include "UDPConnection.h"

#include "Clock.h"
#include "EngineSensor.h"
#include "GPSSensor.h"
#include "OrientationSensor.h"
#include "SpeedSensor.h"

/*
* 	SpeedSensor.h
*	AirViewer
*
*	Data handler.
*	Created by Jaspreet Dhanjan on 19/01/2017
*/

class Client {
private:
	// Clears the buffer, add in the data and send.
	void sendData(Net::Packet &packet);

	//Retrieves data from sensors and sets to the packet.
	void retrieveAndSet(Net::Packet &packet);
public:
	// Initialises the client.
	void init();

	// Updates the client.
	void tick();

	// Stops the client.
	void stop();
};