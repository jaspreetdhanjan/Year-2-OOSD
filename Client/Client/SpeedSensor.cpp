#include "stdafx.h"

#include "SpeedSensor.h"

using namespace Sensors;

SpeedSensor *SpeedSensor::instance;

double lastSpeed;
double time;

SpeedSensor::SpeedSensor() {
	lastSpeed = 400 + (rand() % 150) / 5.0;
	speed = lastSpeed;
}

void SpeedSensor::update() {
	time++;

	lastSpeed = speed;
	double acceleration = sin(time / 10.0) * 20.0;

	// Interpolate between new speed and last speed to smooth acceleration.
	double newSpeed = speed + acceleration;
	double interpolation = (newSpeed - lastSpeed) / acceleration;
	speed = newSpeed * interpolation;
}

double SpeedSensor::getSpeed() {
	return speed;
}

SpeedSensor *SpeedSensor::getInstance() {
	if (!instance) {
		instance = new SpeedSensor;
	}
	return instance;
}