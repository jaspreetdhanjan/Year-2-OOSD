#include "stdafx.h"

#include "EngineSensor.h"

using namespace Sensors;

EngineSensor *EngineSensor::instance;

EngineSensor::EngineSensor() {
}

void EngineSensor::update() {
	failure = false;
}

bool EngineSensor::hasFailed() {
	return failure;
}

EngineSensor *EngineSensor::getInstance() {
	if (!instance) {
		instance = new EngineSensor;
	}
	return instance;
}
