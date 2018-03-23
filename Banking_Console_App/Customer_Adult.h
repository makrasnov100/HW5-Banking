#ifndef CUSTOMER_ADULT_H
#define CUSTOMER_ADULT_H

#include "Customer.h"

/**
Adult:Customer - Header/Implementation
Defines constant banking rates for an Adult Customer

@author: Kostiantyn Makrasnov
*/

class Customer_Adult : public Customer {
private:
	const double CHECKING_INTEREST_RATE = 0.00015;	//yearly
	const double SAVINGS_INTEREST_RATE = 0.004;		//yearly
	const double CHECK_FEE = 10.00;					//monthly
	const double OVERDRAFT_FEE = 45.00;				//per overdraft day

public:
	/// ACCESSOR(S)
	double getCheckIntRate() { return CHECKING_INTEREST_RATE; }
	double getSavingIntRate() { return SAVINGS_INTEREST_RATE; }
	double getCheckFee() { return CHECK_FEE; }
	double getOverdraftFee() { return OVERDRAFT_FEE; }
};

#endif