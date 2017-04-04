#pragma once

#include <iostream>

#include "FileWriter.h"
#include "Alarm.h"
#include "UDPConnection.h"
#include "Observer.h"
#include "ErrorUtil.h"
#include "SoundManager.h"

/*
* 	Server.h
*	AirViewer
*
*	Data handler.
*	Created by Jaspreet Dhanjan on 19/01/2017
*/

class Server {
private:
public:
	// Initialises the server and observers.
	void init();

	// Updates the logic, NOT the networking. This is handled on a seperate thread.
	void tick();

	// Updates the network input stream.
	void incomingTrafficTick();

	// Stops application, destroys the observers.
	void stop();
};
