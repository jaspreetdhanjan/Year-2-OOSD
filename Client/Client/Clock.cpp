#include "stdafx.h"

#include "Clock.h"

using namespace Sensors;

Clock *Clock::instance;

Clock::Clock() {
}

void Clock::update() {
	time = Time::getTime();
}

long long Clock::getTime() {
	return time;
}

Clock *Clock::getInstance() {
	if (!instance) {
		instance = new Clock;
	}
	return instance;
}