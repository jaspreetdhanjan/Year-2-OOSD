#pragma once

#include "Sound.h"

/*
*	SoundManager.h
*	AirViewer
*
*   Plays the sound constants defined in Sound.h
*	Created by Jaspreet Dhanjan on 12/03/2017
*/

namespace Sound {
	class SoundManager {
	public:
		static void playSound(Sound sound, int times = 1);
	};
}