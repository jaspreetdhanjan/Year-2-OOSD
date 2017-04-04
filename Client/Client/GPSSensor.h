#pragma once

#include "Sensor.h"
#include "GPSData.h"

/*
* 	GPSSensor.h
*	AirViewer
*
*	Accurately simulates the latitude, longitude and altitude of an aircraft using real data.
*	Created by Jaspreet Dhanjan on 09/01/2017
*/

namespace Sensors {
	class GPSSensor : public Sensor {
	private:
		static GPSSensor *instance;
		Sensors::Data::GPSData data;

	public:
		GPSSensor();
		void update();
		Sensors::Data::GPSData getData();

		static GPSSensor *getInstance();
	};
}