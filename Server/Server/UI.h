#pragma once

#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <string>

#include "SoundManager.h"

/*
*	UI.h
*	AirViewer
*
*	A basic User Interface utility class with sound alerts.
*	Created by Jaspreet Dhanjan on 21/03/2017
*/

class UI {
public:
	static void alert(std::wstring title, std::wstring msg);
};