#pragma once

#include "Sensor.h"

/*
* 	SpeedSensor.h
*	AirViewer
*
*	Accurately simulates the speed of an aircraft using real data.
*	Created by Jaspreet Dhanjan on 09/01/2017
*/

namespace Sensors {
	class SpeedSensor : public Sensor {
	private:
		static SpeedSensor *instance;
		double speed;
		
	public:
		SpeedSensor();
		void update();
		double getSpeed();

		static SpeedSensor *getInstance();
	};
}