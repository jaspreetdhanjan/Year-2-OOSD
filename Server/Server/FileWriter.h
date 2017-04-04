#pragma once

#include <string>
#include <fstream>

#include "Observer.h"

/* 
 *	FileWriter.h
 *	AirViewer
 *
 *	Writes all incoming data to a .txt file.
 *	Name of the txt file will reflect current date and time.
 *	Created by Jaspreet Dhanjan on 21/01/2017
 */

class FileWriter : public Observer {
private:
	// Destination of file
	std::ofstream file;
public:
	FileWriter();
	~FileWriter();

	// Adds a new line to the output file when called
	void notify(unsigned int client, Net::Packet &data);
};