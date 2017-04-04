// EntryPoint.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <thread>
#include <iostream>
#include <string>
#include <conio.h>

#include "Server.h"
#include "LoginAuthenticator.h"

LoginAuthenticator *login;
Server *server;

bool running = false;

void tick() {
	while (running) {
		server->tick();
		Sleep(1000);
	}
}

void run() {
	server->init();

	// Updates the logic, with different context.
	std::thread logic(tick);

	// Updates the server
	while (running) {
		server->incomingTrafficTick();
		Sleep(1000);
	}

	server->stop();
}

const std::string getPasswordResponse() {
	std::string pass;

	char c = ' ';
	while (c != 13) {
		c = _getch();
		if (c != 13) {
			pass += c;
			std::cout << "*";
		}
	}
	return pass;
}

int main() {
	system("Title AirViewer: Server Application");
	system("Color 1A");

	try {
		login->init();
	}
	catch (Exception::Error e) {
		std::cout << Exception::ErrorUtil::getError(e) << std::endl;
		exit(EXIT_FAILURE);
	}

	std::cout << "************************************************" << std::endl;
	std::cout << "* Welcome to the AirViewer Server Application! *" << std::endl;
	std::cout << "************************************************" << std::endl << std::endl;

	std::string userResponse; 
	std::string passResponse;

	std::cout << "Please enter your username:" << std::endl; 
	std::cin >> userResponse; // Get the username from user.

	std::cout << "Please enter your password:" << std::endl;
	passResponse = getPasswordResponse(); // Get the password from user.

	if (login->authenticate(userResponse, passResponse)) { // Correct credentials.
		std::cout << "\nWelcome " << userResponse << ". Starting the application..." << std::endl;
		running = true;
	}
	else { // Incorrect credentials.
		std::cout << "\n\nSorry, incorrect username or password. Closing the applcation..." << std::endl;
		return 0;
	}

	run();
	return 0;
}