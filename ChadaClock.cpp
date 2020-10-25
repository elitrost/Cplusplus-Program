// ChadaClock.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#ifdef _WIN32      // If-else to decide if Windows or Linux is running. 
#include <Windows.h>      // Imported to use sleep()
#else
#include <unistd.h>
#endif

#include <iostream>
#include <stdlib.h>      // Imported to clear screen
#include <ctime>      // Imported for time
#include <iomanip>       // Imported to use setfill/setw
using namespace std;      // Imported to use cout and cin

void TwelveHourTime(int timeAdd) { // Function to display and update the 12 hour clock
	time_t now;
	struct tm ltm;
	time(&now);
	localtime_s(&ltm, &now);
	int hour;

	switch (timeAdd) {      // switch to add time to current time
	case 0:
		break;
	case 1:
		ltm.tm_hour = ltm.tm_hour + 1;
		break;
	case 2:
		ltm.tm_min = ltm.tm_min + 1;
		break;
	case 3:
		ltm.tm_sec = ltm.tm_sec + 1;
		break;
	}

	hour = ltm.tm_hour;

	if (hour > 12) {      // Loop to convert 24 hour clock into 12 hour clock
		hour = hour % 12;
	}

	cout << hour << ":" << ltm.tm_min << ":" << ltm.tm_sec << endl;

	return;
}

void TwentyFourHourTime(int timeAdd) {      // Funtion to display and update the 24 hour clock
	time_t now;
	struct tm ltm;
	time(&now);
	localtime_s(&ltm, &now);

	switch (timeAdd) {      // switch to add time to current time
	case 0:
		break;
	case 1:
		ltm.tm_hour = ltm.tm_hour + 1;
		break;
	case 2:
		ltm.tm_min = ltm.tm_min + 1;
		break;
	case 3:
		ltm.tm_sec = ltm.tm_sec + 1;
		break;
	}

	cout << ltm.tm_hour << ":" << ltm.tm_min << ":" << ltm.tm_sec << endl;

	return;
}

void DisplayClocks(int clockChoice) {      // Function to start with clear screen and display clocks
	system("CLS");
	Sleep(1000);

	cout << setfill('*') << setw(26) << "" << endl;      // Display for 12-Hour Clock
	cout << "*     12-Hour Clock      *" << endl;
	cout << "         ";
	TwelveHourTime(clockChoice);
	cout << setfill('*') << setw(26) << "" << endl << endl << endl;

	cout << setfill('*') << setw(26) << "" << endl;      // Display for 24-Hour Clock
	cout << "*     24-Hour Clock      *" << endl;
	cout << "         ";
	TwentyFourHourTime(clockChoice);
	cout << setfill('*') << setw(26) << "" << endl << endl << endl;

	return;
}

void DisplayMenu() {      // Function for display menu

	cout << setfill('*') << setw(26) << "" << endl;      // Used setfill to design header and footer for menu
	cout << setfill(' ') << setw(25) << left << "* 1 - Add One Hour" << "*" << endl;
	cout << setw(25) << left << "* 2 - Add One Minute" << "*" << endl;
	cout << setw(25) << left << "* 3 - Add One Second" << "*" << endl;
	cout << setw(25) << left << "* 4 - Exit Program" << "*" << endl;
	cout << setfill('*') << setw(26) << "" << endl;
}

int main() {

	int addTime = 0;      // Declared variables for main
	int userNum;
	char buttonPress;

	DisplayClocks(addTime);
	cin >> buttonPress;      // Accept the user input

	if ((buttonPress == 'n') || (buttonPress == 'N')) {      // Loop to choose to display menu or display clocks
		addTime = 3;
		DisplayClocks(addTime);
	}
	else {
		DisplayMenu();
		cin >> userNum;

		switch (userNum) {      // Switch for display menu input
			case 1:
				addTime = 1;
				DisplayClocks(addTime);
				break;
			case 2: 
				addTime = 2;
				DisplayClocks(addTime);
				break;
			case 3:
				addTime = 3;
				DisplayClocks(addTime);
				break;
			case 4:
				return 0;
				break;
			default:
				cout << "Not an option. Exiting menu.";
				Sleep(1000);
				system("CLS");
				break;
		}
	}

}
