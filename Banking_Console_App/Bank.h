//Author: Kostiantyn Makrasnov
// Contains the bank's actions and variables - Header

#ifndef BANK_H
#define BANK_H

#include <vector>
#include <string>
#include "Account.h"
#include "Customer.h"

using std::vector;
using std::string;

class Bank {

private:
	//Database of customers and accounts
	vector<Account *> accounts;
	vector<Customer *> customers;

	//Account and Customer counters
	int account_id;
	int customer_id;

	/// LOCATOR(S)
	//Return a vector of accounts owned by the specified name of the customer
	vector<int> findAccountsByName(string name);
	//Find a customer based on his/her name
	Customer * findCustomer(string name);

	/// ACCOUNT ALTERATION (-)
	//Create a new account under a customer object (irrespective of type: adult|senior|student)
	Account * createAccount(Customer *cust, string account_type);

public:
	/// CONSTRUCTOR(S)
	//Default constructor - starts counters at 1k
	Bank();

	/// ACCOUNT ALTERATION (+)
	//Try adding account for a possibly existing user
	Account* addAccount(string name, string account_type);
	//Add initial account to a new customer
	Account* addAccount(string name, string address, string telephone, 
						int age, string cust_type, string account_type);

	/// ACCOUNT ACTIONS
	//Make a deposit in an account identified by the account id
	void makeDeposit(int acct_number, double amt);
	//Make a withdrawal in an account identified by the account id
	void makeWithdrawal(int acct_number, double amt);

	/// ACCESSOR(S)/MUTATOR(S)
	//Get the list of account numbers associated with a user, identified by his / her name
	vector<int> getAccounts(string name);
	//Get the account object for an account identified by an account id
	Account * getAccount(int acct_number);
};

#endif