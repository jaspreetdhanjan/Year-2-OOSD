#pragma once

#include "Error.h"

/*
*	ErrorUtil.h
*	AirViewer
*
*   Error utility class.
*	Created by Jaspreet Dhanjan on 1/03/2017
*/

namespace Exception {
	class ErrorUtil {
	public:
		// Gets the meaning of error codes defined in Error.h.
		static const char *getError(Error e) {
			switch (e) {
			case NET_WINSOCK_INIT_FAIL:
				return "Failed Winsock creation";
			case NET_WINSOCK_SOCK_FAIL:
				return "Could not create socket";
			case NET_WINSOCK_BIND_FAIL:
				return "Binding the socket failed";
			case NET_WINSOCK_INPU_FAIL:
				return "Failure when recieving packets";
			case NET_UNKNOWN_PACKET:
				return "Unknown packet type recieved";
			case RES_MISSING_LOGIN:
				return "JSON file login.json is not found! Cannot start Server without this.";
			default:
				return "Undefined error";
			}

			return nullptr;
		}
	};
}