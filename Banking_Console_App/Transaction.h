#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

using std::string;

/**
Transaction - Header
Object is a single record of an action on account

@author: Kostiantyn Makrasnov
*/

class Transaction {

private:
	//Transaction information
	string customer_number;
	string transaction_type;
	double amount;
	string fees;

public:
	/// CONSTRUCTOR(S)
	//Constructor requires all info to be supplied
	Transaction(int customer_number, string type, double amt, string fees);
	
	/// INFORMATION
	//Return the information about the transaction
	string processTran();
};

#endif