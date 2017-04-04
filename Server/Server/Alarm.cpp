#include "stdafx.h"

#include "Alarm.h"

double lastAlarm;
const unsigned int secondsPerAlarm = 20 * 1000;

Alarm::Alarm() {
}

Alarm::~Alarm() {
}

void Alarm::notify(unsigned int client, Net::Packet &data) {
	double now = getTimeMillis();
	lastTimes[client] = now;
}

void Alarm::tick() {
	for (const auto &p : lastTimes) {
		// Gets time diff in seconds
		double now = getTimeMillis();
		double diff = (now - p.second) / 1000.0;

		bool alarmBuffer = (now - lastAlarm) > secondsPerAlarm;

		// Critical alarm
		if (diff >= CRITICAL_ALARM && alarmBuffer) {
			lastAlarm = now;
			UI::alert(L"Critical Alarm", L"No data has been recieved for over 25 minutes from Airplane: " + std::to_wstring(p.first));
			continue;
		}

		// Severe alarm
		if (diff >= SEVERE_ALARM && diff < CRITICAL_ALARM && alarmBuffer) {
			lastAlarm = now;
			UI::alert(L"Severe Alarm", L"No data has been recieved for over 15 minutes from Airplane: " + std::to_wstring(p.first));
			continue;
		}

		// Warning alarm
		if (diff >= WARNING_ALARM && diff < SEVERE_ALARM && alarmBuffer) {
			lastAlarm = now;
			UI::alert(L"Warning Alarm", L"No data has been recieved for over 5 minutes from Airplane: " + std::to_wstring(p.first));
			continue;
		}
	}
}

double Alarm::getTimeMillis() {
	return double(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count());
}