#pragma once

/*
*	Error.h
*	AirViewer
*
*   Defines error codes returned by classes in the lib.
*	Created by Jaspreet Dhanjan on 1/03/2017
*/

namespace Exception {
	enum Error : unsigned char {
		// Network errors
		NET_WINSOCK_INIT_FAIL	= 0x01,	// Error creating network
		NET_WINSOCK_SOCK_FAIL	= 0x02,	// Error with socket
		NET_WINSOCK_BIND_FAIL	= 0x03,	// Error binding
		NET_WINSOCK_INPU_FAIL	= 0x04,	// Error recieving packet
		NET_UNKNOWN_PACKET		= 0x05,	// Unknown packet type recieved

		// Other errors
		RES_MISSING_LOGIN		= 0x06,	// Did not find text file with the login data.
	};
}