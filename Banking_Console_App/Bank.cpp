//Author: Kostiantyn Makrasnov
// Contains the bank's actions and variables - Implementation
// Majority of code in this specific file is a refactored version of the provided Whitworth Faculty project

#include <vector>
#include <string>
#include "Bank.h"

using std::vector;
using std::string;



/// CONSTRUCTOR(S)
/** 
Default constructor - starts counters at 1k
*/
Bank::Bank() : account_id(1000), customer_id(1000) {}



/// LOCATOR(S)
/**
	Return a vector of accounts owned by the specified name of the customer.
	@param name:	The customer name
	@return:		vector of account ids
*/
vector<int> Bank::findAccountsByName(string name)
{
	vector<int> user_accounts;

	// FIXME: Find all the accounts belonging to a customer name and add it to the vector of account numbers.

	return user_accounts;
}

/**
	Find a customer based on his/her name
	@param name:	The customer name
	@return:		customer object if found, NULL otherwise
*/
Customer* Bank::findCustomer(string name)
{
	// FIXME: Find and return the Customer object with the parameter name

	return NULL;
}



/// ACCOUNT ALTERATION
/**
	Create a new account under a customer object (irrespective of its specific type: adult, senior, or student)
	@param cust:			The customer object
	@param account_type:	The account type, i.e. "savings" or "checking"
	@return:				the newly created account object
*/
Account* Bank::createAccount(Customer *cust, string account_type)
{
	Account *acct = NULL;

	// FIXME: Factory method for creating a Account object (could be a Saving_Account or a Checking_Account).

	return acct;
}

/**
	Try adding account for a possibly existing user
	@param name:			The customer name
	@param account_type:	The account type, i.e. "checking" or "savings"
	@return:				the newly created account object if the customer exist, or NULL otherwise
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
	@param name:			Customer name
	@param address:			Customer address
	@param telephone:		Customer telephone number
	@param age:				Customer age
	@param cust_type:		Customer type, i.e. "adult", "senior" or "student"
	@param account_type:	Account type, i.e. "checking" or "savings"
	@return:				the newly created account object
*/
Account* Bank::addAccount(string name, string address, string telephone, int age,
	string cust_type, string account_type)
{
	Customer *cust;

	// FIXME: Depending on the customer type, we want to create an Adult, Senior, or Student object.

	customers.push_back(cust);
	return createAccount(cust, account_type);
}



/// ACCOUNT ACTIONS
/**
	Make a deposit in an account identified by the account id
	@param acct_number:	The account id
	@param amt:			The amount to deposit
*/
void Bank::makeDeposit(int acct_number, double amt)
{
	Account *acct = getAccount(acct_number);
	if (acct) {
		// FIXME: Deposit the amt in the account
	}
}

/**
	Make a withdrawal in an account identified by the account id
	@param acct_number:	The account id
	@param amt:			The amount to withdraw
*/
void Bank::makeWithdrawal(int acct_number, double amt)
{
	Account *acct = getAccount(acct_number);
	if (acct) {
		// FIXME: Withdraw the amt from the account
	}
}



/// ACCESSOR(S)/MUTATOR(S)
/**
	Get the list of account numbers associated with a user, identified by his/her name
	@param name:	The customer name
	@return:		vector of account ids
*/
vector<int> Bank::getAccounts(string name)
{
	return find_accounts_by_name(name);
}

/**
	Get the account object for an account identified by an account id
	@param acct_name:	The account id
	@return:			the account object if it exists, NULL otherwise
*/
Account * Bank::getAccount(int acct_number)
{
	for (size_t i = 0; i < accounts.size(); i++) {
		if (accounts[i]->get_account() == acct_number)
			return accounts[i];
	}
	return NULL;
}



