#pragma once

#define _USE_MATH_DEFINES

#include "Sensor.h"
#include "OrientationData.h"

/*
* 	OrientationSensor.h
*	AirViewer
*
*	Accurately simulates the roll, pitch and yaw of an aircraft using real data.
*	Created by Jaspreet Dhanjan on 09/01/2017
*/

namespace Sensors {
	class OrientationSensor : public Sensor {
	private:
		static OrientationSensor *instance;
		Sensors::Data::OrientationData data;
		OrientationSensor();
	public:
		void update();
		Sensors::Data::OrientationData getData();

		static OrientationSensor *getInstance();
	};
}