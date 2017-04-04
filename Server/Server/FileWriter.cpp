#include "stdafx.h"

#include "FileWriter.h"

FileWriter::FileWriter() {
	std::string path = "output.txt";
	file.open(path);
}

FileWriter::~FileWriter() {
	file.close();
}

void FileWriter::notify(unsigned int client, Net::Packet &data) {
	long long second = (data.time / 1000) % 60;
	long long minute = (data.time / (1000 * 60)) % 60;
	long long hour = (data.time / (1000 * 60 * 60)) % 24;

	file << "----- Data recieved from Airplane: " << client << ", at time: " << hour << ":" << minute << ":" << second << " -----\n";

	if (!data.engineFailure) file << "Engines working" << "!\n";
	else file << "Engines not working!" << "!\n";

	file << "Travelling at loc(" << data.latitude << ", " << data.altitude << ", " << data.longitude << ")\n";
	file << "Travelling at axes(" << data.pitch << "°, " << data.yaw << "°, " << data.roll << "°)\n";
	file << "With speed: " << data.speed << "m/s\n";

	file << "----- End of transmission -----\n\n";
}