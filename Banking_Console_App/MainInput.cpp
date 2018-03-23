//Author: Kostiantyn Makrasnov
// Contains the methods which carry out high-level user commands - implemeentation
// Majority of code in this specific file is a refactored version of the provided Whitworth Faculty project

#include <iostream>
#include <string>
#include <stdexcept>
#include "MainInput.h"
#include "Bank.h"
#include "Account.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;



/// CONSTRUCTOR(S)
// Construct default input sequence
MainInput::MainInput() { 
	curOnline = true; 
};



/// TASK ORIENTED
/**
	Ask user what bank task to complete next and leads them to required prompts
	@param bank:	current bank object that contains the customer
*/
void MainInput::performTask(Bank &bank) {
	
	//Menu layout
	string	menu_string = "Please choose an action below:\n";
			menu_string += "0 - Add Account\n";
			menu_string += "1 - List Accounts\n";
			menu_string += "2 - Deposit Money\n";
			menu_string += "3 - Withdraw Money\n";
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
		initListAccounts(bank);
		break;
	case 2:
		initDeposit(bank);
		break;
	case 3:
		initWithdraw(bank);
		break;
	default:
		curOnline = false;
		cout << "Goodbye! Thank you for visiting." << endl;
	}
};

/**
	Add a certain type of acount to a customer
	@param bank:	current bank object that contains the customer
*/
void MainInput::initAddAccount(Bank &bank) {
	string name;
	cout << "Please enter your name: ";
	cin.ignore();
	getline(cin, name);

	int acct_type;
	string	menu_string = "Type of account: \n";
			menu_string += "   0 - Savings\n";
			menu_string += "   1 - Checking\n";
			menu_string += "Enter: ";
	acct_type = readInt(menu_string, 0, 1);

	string acct_type_str;
	if (acct_type == 0)
		acct_type_str = "savings";
	else
		acct_type_str = "checking";

	Account *acct = bank.addAccount(name, acct_type_str); // attempt to add an account
	if (acct == NULL) { // case for new user
		cout << "You appear to be a new user.  We will need more information.\n";
		// get all the required information for a new user
		cout << "Address: ";
		string address;
		cin.ignore();
		getline(cin, address);
		string telephone;
		cout << "Telephone Number: ";
		getline(cin, telephone);
		cout << "Age: ";
		int age;
		cin >> age;

		int cust_type;
		string	menu_string = "Type of customer: \n";
		menu_string += "   0 - Adult\n";
		menu_string += "   1 - Senior\n";
		menu_string += "   2 - Student\n";
		menu_string += "Enter: ";
		cust_type = readInt(menu_string, 0, 2);

		string cust_type_str;
		if (cust_type == 0)
			cust_type_str = "adult";
		else if (cust_type == 1)
			cust_type_str = "senior";
		else
			cust_type_str = "student";
		acct = bank.addAccount(name, address, telephone, age, cust_type_str, acct_type_str);
	}
	if (acct) {
		cout << "Your new account ID is " << acct->getAccount() << endl;
	}
	else {
		cout << "Sorry.  We failed to create an account for you\n";
	}
};

/**
	List all acounts under a specific customer
	@param bank:	current bank object that contains the customer
*/
void MainInput::initListAccounts(Bank &bank) {

};

/**
	Perform a deposit to an account
	@param bank:	current bank object that contains the customer
*/
void MainInput::initDeposit(Bank &bank) {

};

/**
	Perform a withdrawal from an account
	@param bank:	current bank object that contains the customer
*/
void MainInput::initWithdraw(Bank &bank) {

};



/// UTILITIES
/**
	Get an int from user between specified range w/ validation
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



/// PROMPTS
// Print simple welcoming text (included for later personalization options)
void MainInput::displayWelcome() {
	cout << "Welcome to Console Bank - a simple solution for basic banking inquries." << endl << endl;
};



/// ACCESSOR(S)/MUTATOR(S)
bool MainInput::getOnlineStatus() {
	return curOnline;
};