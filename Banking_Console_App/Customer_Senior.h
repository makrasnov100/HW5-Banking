#ifndef CUSTOMER_SENIOR_H
#define CUSTOMER_SENIOR_H

#include "Customer.h"

/**
Senior:Customer - Header/Implementation
Defines constant banking rates for a Senior Customer

@author: Kostiantyn Makrasnov
*/

class Customer_Senior : public Customer {
private:
	const double CHECKING_INTEREST_RATE = 0.0002;	//yearly
	const double SAVINGS_INTEREST_RATE = 0.012;		//yearly
	const double CHECK_FEE = 10.00;					//monthly
	const double OVERDRAFT_FEE = 35.00;				//per overdraft day

public:
	/// ACCESSOR(S)
	double getCheckIntRate() { return CHECKING_INTEREST_RATE; }
	double getSavingIntRate() { return SAVINGS_INTEREST_RATE; }
	double getCheckFee() { return CHECK_FEE; }
	double getOverdraftFee() { return OVERDRAFT_FEE; }
};

#endif