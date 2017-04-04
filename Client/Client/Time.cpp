#include "stdafx.h"

#include "Time.h"

__int64 Time::getTime() {
	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}