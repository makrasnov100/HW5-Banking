/**
*  Program Name: Banking Console App
*  Last modified: Spring 2018
*  Authors: Whitworth CS Department & Kostiantyn Makrasnov
*/

#include <iostream>
#include "MainInput.h"
#include "Bank.h"

/**
	Main.cpp
	Main driver of the program

	@author: Kostiantyn Makrasnov
*/


int main() {
	MainInput input = MainInput();
	Bank bank; //(revise - may store as a file instead of creating clean bank each time)

	//Welcome user to bank
	input.displayWelcome();
	
	//Perform naking tasks while the station remains online
	while (input.getOnlineStatus())
		input.performTask(bank);
	
	system("pause"); //(revise - remove as needed since only used to show exit message)

	return 0;
}
