#pragma once

#include "Sensor.h"

/*
* 	EngineSensor.h
*	AirViewer
*
*	Accurately simulates the status of an engine.
*	Created by Jaspreet Dhanjan on 09/01/2017
*/

namespace Sensors {
	class EngineSensor : public Sensor {
	private:
		static EngineSensor *instance;
		bool failure;

	public:
		EngineSensor();
		void update();
		bool hasFailed();

		static EngineSensor *getInstance();
	};
}