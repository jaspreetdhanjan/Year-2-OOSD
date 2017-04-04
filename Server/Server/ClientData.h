#pragma once

#include <winsock2.h>

/*
*	ClientData.h
*	AirViewer
*
*   A data structure to hold individual clients.
*	Created by Jaspreet Dhanjan on 17/01/2017
*/

namespace Net {
	struct ClientData {
	private:
		const int token;
		const u_short cd_port;

	public:
		ClientData(int clientToken, u_short port) : token(clientToken), cd_port(port) {
		}

		// Token, generated client side.
		int getToken() const {
			return token;
		}

		// Port addr.
		u_short getPort() const {
			return cd_port;
		}
	};
}