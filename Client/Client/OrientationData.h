#pragma once

/*
* 	OrientaionData.h
*	AirViewer
*
*	Handles the orientational data.
*	Created by Jaspreet Dhanjan on 09/01/2017
*/

namespace Sensors {
	namespace Data {
		struct OrientationData {
		private:
			double pitch, roll, yaw;

		public:
			double getPitch() { return pitch; }
			double getRoll() { return roll; }
			double getYaw() { return yaw; }

			void setPitch(double pitch) { this->pitch = pitch; }
			void setRoll(double roll) { this->roll = roll; }
			void setYaw(double yaw) { this->yaw = yaw; }
		};
	}
}