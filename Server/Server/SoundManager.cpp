#include "stdafx.h"

#include "SoundManager.h"

void Sound::SoundManager::playSound(Sound sound, int times) {
	for (int i = 0; i < times; i++) {
		printf("%c", sound);
	}
}