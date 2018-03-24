#include <vector>
#include <string>
#include <iostream>
#include "Bank.h"
#include "Account_Checkings.h"
#include "Account_Savings.h"

using std::vector;
using std::string;
using std::cout;

/**
Bank - Implementation
The Bank has Accounts and Customers

@author: Ed Walker & Kostiantyn Makrasnov
*/


/// CONSTRUCTOR(S)
//	Default constructor - starts counters at 1k
Bank::Bank() : account_id(1000), customer_id(1000) {}



/// LOCATOR(S)
/**
	Return a vector of accounts owned by the specified name of the customer.
	@param name:	customer name
	@return:		vector of account ids
*/
vector<int> Bank::findAccountsByName(string name)
{
	vector<int> user_accounts;

	//Search through all of the bank accounts by name
	for (size_t i = 0; i < accounts.size(); i++)
		if (accounts[i]->getCustomer()->getName() == name)
			user_accounts.push_back(accounts[i]->getAccountID());

	return user_accounts;
}

/**
	Find a customer based on his/her name
	@param name:	customer name
	@return:		customer object if found, NULL otherwise
*/
Customer* Bank::findCustomer(string name)
{
	//Search through all of the bank customers by name
	for (size_t i = 0; i < customers.size(); i++)
		if (customers[i]->getName() == name)
			return customers[i];

	return NULL;
}



/// ACCOUNT ALTERATION
/**
	Create a new account under a customer object (irrespective of its specific type: adult, senior, or student)
	@param cust:			customer object
	@param account_type:	account type, i.e. "savings" or "checking"
	@return:				newly created account object
*/
Account* Bank::createAccount(Customer* cust, string account_type)
{
	Account *acct = NULL;

	if (account_type == "savings")
		acct = new Savings_Account(cust, account_id);
	else
		acct = new Checkings_Account(cust, account_id);

	//Add account to list & update next account id
	accounts.push_back(acct);
	account_id++; //(revise - may include function for better id generation)

	return acct;
}

/**
	Try adding account for a possibly existing user
	@param name:			customer name
	@param account_type:	account type, i.e. "checking" or "savings"
	@return:				newly created account object if the customer exist, or NULL otherwise
*/
Account* Bank::addAccount(string name, string account_type)
{
	Customer *cust = findCustomer(name);
	if (cust == NULL)
		return NULL;
	return createAccount(cust, account_type);
}

/**
	Add initial account to a new customer
	@param name:			customer name
	@param address:			customer address
	@param telephone:		customer telephone number
	@param age:				customer age
	@param cust_type:		customer type, i.e. "adult", "senior" or "student"
	@param account_type:	account type, i.e. "checking" or "savings"
	@return:				newly created account object
*/
Account* Bank::addAccount(string name, string address, string telephone, int age,
	string cust_type, string account_type)
{
	Customer *cust;

	if (cust_type == "adult")
	{
		cust = new Customer_Adult(customer_id, name, address, age, telephone);
		cout << "Created Adult Customer." << endl;
	}
	else if (cust_type == "senior") {
		cust = new Customer_Senior(customer_id, name, address, age, telephone);
		cout << "Created Senior Customer." << endl;
	}
	else
	{
		cust = new Customer_Student(customer_id, name, address, age, telephone);
		cout << "Created Student Customer." << endl;
	}


	//Update next id and add customer to the bank database
	customer_id++;
	customers.push_back(cust);

	return createAccount(cust, account_type);
}



/// ACCOUNT ACTIONS
/**
	Make a deposit in an account identified by the account id
	@param acct_number:	account id
	@param amt:			amount to deposit
*/
void Bank::makeDeposit(int acct_number, double amt)
{
	Account *acct = getAccount(acct_number);
	if (acct)
		acct->deposit(amt);
	else
		cout << "Deposit Failed! Please try again later...\n";
}

/**
	Make a withdrawal in an account identified by the account id
	@param acct_number:	account id
	@param amt:			amount to withdraw
*/
void Bank::makeWithdrawal(int acct_number, double amt)
{
	Account *acct = getAccount(acct_number);
	if (acct)
		acct->withdraw(amt);
	else
		cout << "Withdraw Failed! Please try again later...\n";
}



/// ACCESSOR(S)/MUTATOR(S)
/**
	Get the list of account numbers associated with a user, identified by his/her name
	@param name:	customer name
	@return:		vector of account ids
*/
vector<int> Bank::getAccounts(string name)
{
	return findAccountsByName(name);
}

/**
	Get the account object for an account identified by an account id
	@param acct_name:	account id
	@return:			account object if it exists, NULL otherwise
*/
Account * Bank::getAccount(int acct_number)
{
	for (size_t i = 0; i < accounts.size(); i++) {
		if (accounts[i]->getAccountID() == acct_number)
			return accounts[i];
	}
	return NULL;
}

/**
	Get the amount of accounts in bank
	@return:	amount of created accounts in bank
*/
int Bank::getAccountAmount()
{
	return accounts.size();
}



