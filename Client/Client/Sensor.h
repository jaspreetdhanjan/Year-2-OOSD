#pragma once

#include "Random.h"
#include <math.h>

/*
 * 	Sensor.h
 *	AirViewer
 *
 *	Abstract class, used to return relevant and handle information related to the sensor.
 *	Created by Jaspreet Dhanjan on 09/01/2017
*/

namespace Sensors {
	class Sensor {
	public:
		// Called every 'tick', updates the data simulation.
		virtual void update() = 0;
	};
}