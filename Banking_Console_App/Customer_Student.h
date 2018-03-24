#ifndef CUSTOMER_STUNDENT_H
#define CUSTOMER_STUNDENT_H

#include "Customer.h"

/**
Student:Customer - Header/Implementation
Defines constant banking rates for a Student Customer

@author: Kostiantyn Makrasnov
*/

class Customer_Student : public Customer {
private:
	const double CHECKING_INTEREST_RATE = 0.0001;	//yearly
	const double SAVINGS_INTEREST_RATE = 0.003;		//yearly
	const double CHECK_FEE = 1.00;					//monthly
	const double OVERDRAFT_FEE = 25.00;				//per overdraft day

public:
	/// CONSTRUCTOR(S)
	Customer_Student(int customerID, string name, string address, int age, string teleNum) :
		Customer(customerID, name, address, age, teleNum) {}

	/// ACCESSOR(S)
	double getCheckIntRate() { return CHECKING_INTEREST_RATE; }
	double getSavingIntRate() { return SAVINGS_INTEREST_RATE; }
	double getCheckFee() { return CHECK_FEE; }
	double getOverdraftFee() { return OVERDRAFT_FEE; }
};

#endif