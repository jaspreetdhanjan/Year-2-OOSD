#pragma once

#include <iostream>

#include "Packet.h"

/* 
 *	Observer.h
 *	AirViewer
 *
 *	Follows the observer design pattern.
 *	Created by Jaspreet Dhanjan on 21/01/2017
 */

class Observer {
public:
	// Called whenever a new packet is recieved.
	virtual void notify(unsigned int client, Net::Packet &data) = 0;
};