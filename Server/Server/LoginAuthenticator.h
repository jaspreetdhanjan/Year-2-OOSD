#pragma once

#include <map>
#include <fstream>
#include <sstream>

#include "Error.h"

/*
*	LoginAuthenticator.h
*	AirViewer
*
*	Retrieves login data from a text file and assembles accounts.
*   Checks to see if the given login data matches the DB accounts.
*	Created by Jaspreet Dhanjan on 11/03/2017
*/

class LoginAuthenticator {
public:
	// Creates account DB.
	void init();

	// Checks against the DB.
	bool authenticate(const std::string username, const std::string password);
};