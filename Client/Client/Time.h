#pragma once

#include <chrono>

/*
* 	Time.h
*	AirViewer
*
*	Time utility class.
*	Created by Jaspreet Dhanjan on 26/02/2017
*/

class Time {
public:
	static const int MILLIS_PER_SECOND = 1000;

	// Gets current time in millis (64-bit).
	static __int64 getTime();
};