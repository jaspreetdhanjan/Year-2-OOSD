#include "stdafx.h"

#include "LoginAuthenticator.h"

typedef std::map<std::string, std::string> UserInfo;
UserInfo userInfo;

void LoginAuthenticator::init() {
	std::fstream fileStream("login.json.txt");
	if (!fileStream.is_open()) {
		throw Exception::Error::RES_MISSING_LOGIN;
	}

	std::string line;
	while (std::getline(fileStream, line)) {
		std::istringstream is_line(line);

		std::string key;
		if (std::getline(is_line, key, ':')) {
			if (key[0] == '#') continue;

			std::string value;
			if (std::getline(is_line, value)) {
				userInfo[key] = value;
			}
		}
	}

	fileStream.clear();
	fileStream.close();
}

bool LoginAuthenticator::authenticate(const std::string username, const std::string password) {
	if (!userInfo.count(username)) return false;
	return userInfo[username] == password;
}