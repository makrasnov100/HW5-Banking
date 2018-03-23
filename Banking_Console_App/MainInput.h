//Author: Kostiantyn Makrasnov
// Contains the methods which carry out high-level user commands - Header

#ifndef MAININPUT_H
#define MAININPUT_H

#include <string>

class MainInput {

private:
	bool curOnline;

public:
	//CONSTRUCTOR(S)
	// Construct default input sequence
	MainInput();

	//TASK ORIENTED
	// Asks user what bank task to complete next and leads them to other prompts
	void performTask(Bank &bank);
	// Add a certain type of acount to a customer
	void initAddAccount(Bank &bank);
	// Lists all acounts under a specific customer
	void initListAccounts(Bank &bank);
	// Performs a deposit to an account
	void initDeposit(Bank &bank);
	// Performs a withdrawal from an account
	void initWithdraw(Bank &bank);

	//PROMPTS
	// Prints simple welcoming text (included for later personalization options)
	void displayWelcome();

	//UTILITY
	// Gets an int from user between specified range w/ validation
	int readInt(std::string prompt, int low, int high);

	//ACCESSOR(S)/MUTATOR(S)
	bool getOnlineStatus();
};

#endif