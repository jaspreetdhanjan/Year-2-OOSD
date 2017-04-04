#include "stdafx.h"

#include <iostream>

#include "GPSSensor.h"
#include "SpeedSensor.h"

using namespace Sensors;

GPSSensor *GPSSensor::instance;

const unsigned int MAX_LAT = 90;
const unsigned int MAX_LON = 180;
const unsigned int METRES_PER_DEG = 111000;

double distMoved;
double speed, lastTickedSpeed;

GPSSensor::GPSSensor() {
	double lat = Random::nextInt(MAX_LAT) + MAX_LAT / 2;
	double lon = Random::nextInt(MAX_LON) + MAX_LON / 2;
	double alt = Random::nextInt(200) + 9000;

	data.setLatitude(lat);
	data.setLongitude(lon);
	data.setAltitude(alt);
}

// Implementation of GPS simulation sourced from: http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.510.7499&rep=rep1&type=pdf

void GPSSensor::update() {
	SpeedSensor *ss = SpeedSensor::getInstance();
	lastTickedSpeed = speed;
	speed = ss->getSpeed();

	distMoved += speed;

	double newLat = data.getLatitude();
	double newLon = data.getLongitude();
	double newAlt = data.getAltitude();

	double accel = speed - lastTickedSpeed;
	if (distMoved/METRES_PER_DEG<50.0) {
		double d0 = sin(speed);
		double d1 = cos(speed);

		newLat += d0;
		newLon += d1;
	}
	newAlt += accel;

	data.setLatitude(newLat);
	data.setLongitude(newLon);
	data.setAltitude(newAlt);
}

Data::GPSData GPSSensor::getData() {
	return data;
}

GPSSensor *GPSSensor::getInstance() {
	if (!instance) {
		instance = new GPSSensor;
	}
	return instance;
}
