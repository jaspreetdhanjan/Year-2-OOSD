#pragma once

#include "Sensor.h"
#include "Time.h"

/*
* 	EngineSensor.h
*	AirViewer
*
*	Returns time since 1970 in millisecond, using 64-bit precision.
*	Created by Jaspreet Dhanjan on 09/01/2017
*/

namespace Sensors {
	class Clock : public Sensor {
	private:
		static Clock *instance;
		long long time;

	public:
		Clock();
		void update();
		long long getTime();

		static Clock *getInstance();
	};
}