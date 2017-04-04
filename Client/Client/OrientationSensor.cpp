#include "stdafx.h"

#include "OrientationSensor.h"

using namespace Sensors;

OrientationSensor *OrientationSensor::instance;

OrientationSensor::OrientationSensor() {
	// Note: roll, pitch and yaw in radians.

	double roll = Random::nextDouble() * M_PI;
	double yaw = Random::nextDouble() * M_PI;
	double pitch = Random::nextDouble() * M_PI;

	data.setRoll(roll);
	data.setYaw(pitch);
	data.setPitch(yaw);
}

void OrientationSensor::update() {
	double rollDiff = (Random::nextDouble() * 2.0 * M_PI);
	double yawDiff = (Random::nextDouble() * 2.0 * M_PI);
	double pitchDiff = (Random::nextDouble() * 2.0 * M_PI);

	if (Random::nextInt(100) == 0 && rollDiff != 0) {
		double dd = data.getRoll() + rollDiff;
		data.setRoll(dd);
	}
	else if (Random::nextInt(100) == 0 && yawDiff != 0) {
		double dd = data.getYaw() + yawDiff;
		data.setYaw(dd);
	}
	else if (Random::nextInt(100) == 0 && pitchDiff != 0) {
		double dd = data.getPitch() + pitchDiff;
		data.setPitch(dd);
	}
}

Data::OrientationData OrientationSensor::getData() {
	return data;
}

OrientationSensor *OrientationSensor::getInstance() {
	if (!instance) {
		instance = new OrientationSensor;
	}
	return instance;
}
