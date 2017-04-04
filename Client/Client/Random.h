#pragma once

#include  <cstdlib>

/*
* 	Random.h
*	AirViewer
*
*	Random number generator utility class.
*	Created by Jaspreet Dhanjan on 26/02/2017
*/

class Random {
public:
	// Get a random number bounded between min and max (exclusive).
	static int nextInt(int min, int max);

	// Get a random number from 0 -> max (inclusive).
	static int nextInt(int max);

	// Get a random 32-bit value.
	static int nextInt();

	// Get a random 64-bit value between 0 - 1 (inclusive).
	static double nextDouble();
};