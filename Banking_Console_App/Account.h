#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include "Customer.h"
#include "Transaction.h"

using std::string;

/**
Account - Header
The Bank has Accounts and an Account belongs to a Customer.
Additionally, there are specialized types of accounts: Checking_Account and Savings_Account.
Checking_Account and Savings_Account have specialized ways of adding interest, and describing itself.

@author: Ed Walker & Kostiantyn Makrasnov
*/


class Account {

protected:
	Customer * customer;	// The customer who owns this account
	double balance;			// The available balance in this account
	int account_number;		// A unique number identifying this account
	std::vector<Transaction *> transactions;  // The record of transactions that have occured with this account

	/// INFORMATION (#)
	//Describe fees associated with the customer who owns this account
	string getFees();

	/// ACCOUNT SETTINGS
	//Add interest based on a specified interest rate to account
	void addInterest(double interest);

public:
	/// CONSTRUCTOR(S)
	//Single constructor requires a customer to create an account
	Account(Customer* cust, int id);

	/// INFORMATION (+)
	//Generic method describing the account information.
	virtual string toString();
	
	/// ACCOUNT ACTIONS
	//Deposits amount into account
	virtual void deposit(double amt);
	//Withdraws amount from account
	virtual void withdraw(double amt);
	//Add interest to an account (implemented by derived classes)
	virtual void addInterest() = 0;

	/// ACCESSOR(S)/MUTATOR(S)
	Customer* getCustomer();
	void setCustomer(Customer* cust);

	int getAccount();
	void setAccount(int account_number);

	double getBalance();
	void setBalance(double new_balance);
};

#endif