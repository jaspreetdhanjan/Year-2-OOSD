#pragma once

/*
* 	GPSData.h
*	AirViewer
*	
*	Handles the 3 data coords (latitude, longitude and altitude) as a single struct.
*	Created by Jaspreet Dhanjan on 09/01/2017
*/

namespace Sensors {
	namespace Data {
		struct GPSData {
		private:
			double latitude, longitude, altitude;

		public:
			double getLatitude() { return latitude; }
			double getLongitude() { return longitude; }
			double getAltitude() { return altitude; }

			void setLatitude(double latitude) { this->latitude = latitude; }
			void setLongitude(double longitude) { this->longitude = longitude; }
			void setAltitude(double altitude) { this->altitude = altitude; }
		};
	}
}