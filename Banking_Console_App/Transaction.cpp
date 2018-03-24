#include <string>
#include <sstream>
#include "Transaction.h"

using std::string;
using std::stringstream;

/**
Transaction - Implementation
This object is a single record of an action on account

@author: Kostiantyn Makrasnov
*/


/// CONSTRUCTOR(S)
//Constructor requires all info to be supplied
Transaction::Transaction(int customer_number, string type, double amt, string fees)
{
	this->customer_number = customer_number;
	this->transaction_type = type;
	this->amount = amt;
	this->fees = fees;
}



/// INFORMATION
//Return the information about the transaction
string Transaction::processTran()
{
	std::stringstream ss;
	ss << "Transaction: " << transaction_type << " || Amount: " << amount << " USD" << fees;
	return ss.str();
}