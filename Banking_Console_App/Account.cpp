#include <string>
#include <vector>
#include <sstream>
#include "Account.h"
#include "Customer.h"
#include "Transaction.h"


using std::string;
using std::vector;
using std::stringstream;
using std::endl;

/**
Account - Implementation
The Bank has Accounts and an Account belongs to a Customer.
Additionally, there are specialized types of accounts: Checking_Account and Savings_Account.
Checking_Account and Savings_Account have specialized ways of adding interest, and describing itself.

@author: Ed Walker & Kostiantyn Makrasnov
*/


/// CONSTRUCTOR(S)
/**
	Constructor requires a customer to create an account
	Balance always starts with 0 when account is created.
*/
Account::Account(Customer* cust, int id) : customer(cust), account_number(id), balance(0) {}



/// INFORMATION
/**
	Describe fees associated with the customer who owns this account.
	The fee will depend on the specific type of customer.
	@return:	string showing checking and overdraft fees
*/
string Account::getFees()
{
	double overdraft, charge = 0.0;

	// Get the correct values of fees
	overdraft = customer->getOverdraftFee();
	charge = customer->getCheckFee();

	stringstream ss;
	ss << " | Annual Check Charge: " << charge << " USD | Possible Overdraft Fee: " << overdraft << " USD";
	return ss.str();
}

/**
	Generic method describing the account information.
	@return:	string describing generic information about the account
*/
string Account::toString() {
	stringstream ss;

	ss << "Generic Account - " << customer->getName() << endl;
	ss << "-|Account ID: " << account_number << endl;
	ss << "-|Balance: " << balance << endl;
	return ss.str();
}



/// ACCOUNT SETTINGS
/**
	Add interest based on a specified interest rate to account
	@param interest:	new interest rate
*/
void Account::addInterest(double interest) {
	double amt = balance * interest;
	balance = balance + amt;
	string fees = getFees();
	Transaction *tran = NULL;

	tran = new Transaction(customer->getCustID(), "Interest", amt, fees);
	transactions.push_back(tran);
}


/// ACCOUNT ACTIONS
/**
	Deposits amount into account
	@param amt:	deposit amount
*/
void Account::deposit(double amt) {
	balance += amt;
	string fees = getFees();
	Transaction *tran = NULL;

	tran = new Transaction(customer->getCustID(), "Deposit", amt, fees);
	transactions.push_back(tran);
}

/**
	Withdraws amount from account
	@param amt:	withdrawal amount
*/
void Account::withdraw(double amt) {
	balance -= amt;
	string fees = getFees();
	Transaction *tran = NULL;

	tran = new Transaction(customer->getCustID(), "Withdrawal", amt, fees);
	transactions.push_back(tran);
}



/// ACCESSOR(S)/MUTATOR(S)
Customer* Account::getCustomer() {
	return customer;
}

void Account::setCustomer(Customer* cust) {
	customer = cust;
}

int Account::getAccountID() {
	return account_number;
}

void Account::setAccountID(int account_number) {
	this->account_number = account_number;
}

double Account::getBalance() {
	return balance;
}

void Account::setBalance(double new_balance) {
	balance = new_balance;
}
