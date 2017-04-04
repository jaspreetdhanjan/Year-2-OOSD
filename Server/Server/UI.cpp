#include "stdafx.h"

#include "UI.h"

void UI::alert(std::wstring title, std::wstring msg) {
	Sound::SoundManager::playSound(Sound::ALERT_SOUND_1);
	MessageBox(NULL, msg.c_str(), title.c_str(), MB_OK | MB_SYSTEMMODAL);
}