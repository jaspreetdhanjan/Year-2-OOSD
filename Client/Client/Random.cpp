#include "stdafx.h"

#include "Random.h"

int Random::nextInt(int min, int max) {
	return min + (rand() % (int)(max - min + 1));
}

int Random::nextInt(int max) {
	return (int)(rand() % (max + 1));
}

int Random::nextInt() {
	return rand();
}

double Random::nextDouble() {
	return ((double)rand() / (RAND_MAX)) + 1;
}