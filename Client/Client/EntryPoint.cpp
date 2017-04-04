// EntryPoint.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <string>

#include "Client.h"

unsigned const int transmissionRate = 30; // In seconds
unsigned const int transmissionRateInMillis = transmissionRate * 1000;

Client *client;
bool running = false;

void run() {
	client->init();

	while (running) {
		client->tick();
		Sleep(transmissionRateInMillis);
	}

	client->stop();
}

int main() {
	system("Title AirViewer: Client Application");
	system("Color 1A");

	std::cout << "************************************************" << std::endl;
	std::cout << "* Welcome to the AirViewer Client Application! *" << std::endl;
	std::cout << "************************************************" << std::endl << std::endl;

	std::cout << "Would you like to start? (Y/N)" << std::endl;

	bool givenResponse = false;
	while (!givenResponse) {
		std::string response; // Get the response from user.
		std::cin >> response;
		for (auto &c : response) { // Change all characters to upper-case.
			c = toupper(c);
		}

		if (response == "Y") { // If the user wants to start the app.
			std::cout << "Starting data transmission..." << std::endl;
			running = true;
			givenResponse = true;
		}
		else if (response == "N") { // If the user doesn't want to start the app.
			std::cout << "Closing the application..." << std::endl;
			givenResponse = true;
			return 0;
		}
		else { // Default.
			std::cout << "Sorry, I did not catch that. Try again." << std::endl;
		}
	}

	run(); // Begin the run loop.
	return 0;
}