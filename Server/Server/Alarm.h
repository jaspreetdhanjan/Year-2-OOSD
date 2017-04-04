#pragma once

#include <map>
#include <chrono>
#include <string>

#include "Observer.h"
#include "UI.h"

/* 
*	Alarm.h
*	AirViewer
*
*	Checks the frequency of packets recieved by each client. 
*	If a client has not sent packets in a specified amount of time, an alarm of varying degrees will be executed on the console.
*	Created by Jaspreet Dhanjan on 21/01/2017
*/

class Alarm : public Observer {
private:
	// The alarm params (in seconds)
	const int SECONDS_PER_MINUTE	= 60;
	const int WARNING_ALARM			= 5  * SECONDS_PER_MINUTE;
	const int SEVERE_ALARM			= 15 * SECONDS_PER_MINUTE;
	const int CRITICAL_ALARM		= 25 * SECONDS_PER_MINUTE;

	// Storage of clients last transmission.
	std::map<unsigned int, double> lastTimes;

	// Gets the latest time to millisecond precision.
	double getTimeMillis();

public:
	Alarm();
	~Alarm();
	
	// Updates the last contact times of each client.
	void notify(unsigned int client, Net::Packet &data);

	// Updates the last sent times of the packets.
	void tick();
};