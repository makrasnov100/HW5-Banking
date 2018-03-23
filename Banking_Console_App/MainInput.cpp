//Author: Kostiantyn Makrasnov
// Contains the methods which carry out high-level user commands - implemeentation
// Majority of code in this specific file is a refactored version of the provided Whitworth Faculty project

#include <iostream>
#include <string>
#include <stdexcept>
#include "MainInput.h"
#include "Bank.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

//CONSTRUCTOR(S)
// Construct default input sequence
MainInput::MainInput() { 
	curOnline = true; 
};



//TASK ORIENTED
/*
	Asks user what bank task to complete next and leads them to required prompts
	@param bank:	current bank object that contains the customer
*/
void MainInput::performTask(Bank &bank) {
	
	//Menu layout
	string	menu_string = "Please choose an action below:\n";
			menu_string += "0 - Add Account\n";
			menu_string += "1 - List Accounts\n";
			menu_string += "3 - Make withdrawal\n";
			menu_string += "4 - Quit\n";
			menu_string += "Enter: ";

	//Get the user's main menu selection
	int select = readInt(menu_string, 0, 4);

	//Perform seperate task based on selection
	switch (select) {
	case 0:
		initAddAccount(bank);
		break;
	case 1:
		List_Account(bank);
		break;
	case 2:
		Make_Deposit(bank);
		break;
	case 3:
		Make_Withdrawal(bank);
		break;
	default:
		cout << "Goodbye!  Thank you for visiting.\n";
		return 0;
	}
};

/*
	Add a certain type of acount to a customer
	@param bank:	current bank object that contains the customer
*/
void MainInput::initAddAccount(Bank &bank) {

};

/*
	Lists all acounts under a specific customer
	@param bank:	current bank object that contains the customer
*/
void MainInput::initListAccounts(Bank &bank) {

};

/*
	Performs a deposit to an account
	@param bank:	current bank object that contains the customer
*/
void MainInput::initDeposit(Bank &bank) {

};

/*
	Performs a withdrawal from an account
	@param bank:	current bank object that contains the customer
*/
void MainInput::initWithdraw(Bank &bank) {

};



//UTILITIES
/*
	Gets an int from user between specified range w/ validation
	@param prompt	prompt to user
	@param low		lowest accepted integer
	@param high		highest accepted integer
	@return			user's integer within accepted range
*/
int MainInput::readInt(string prompt, int low, int high) {
	// Invalid range check
	if (low >= high)
		throw std::invalid_argument("invalid range specified");

	// Integer input check
	cin.exceptions(std::ios_base::failbit);
	int num = 0;
	while (true) {
		try {
			while (true) {
				cout << prompt;
				cin >> num;
				if (num >= low && num <= high) {
					cout << endl;
					return num;
				}
			}
		}
		catch (std::ios_base::failure) {
			cout << "Bad numeric string -- try again\n";
			cin.clear();
			cin.ignore(std::numeric_limits<int>::max(), '\n');
		}
	}
}



//PROMPTS
// Prints simple welcoming text (included for later personalization options)
void MainInput::displayWelcome() {
	cout << "Welcome to Console Bank - a simple solution for basic banking inquries." << endl << endl;
};



//ACCESSOR(S)/MUTATOR(S)
bool MainInput::getOnlineStatus() {
	return curOnline;
};