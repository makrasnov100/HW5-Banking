#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

using std::string;

/**
Customer - Header
The Bank has Customers.  Each Customer has a name, address, age, and telephone number.
Additionally, there are specialized types of Customers: Adult, Senior, and Student.
Each type of Customer has its own checking and savings interest rates,
as well as its own checking and overdraft fees.

@author: Ed Walker & Kostiantyn Makrasnov
*/

class Customer {

private:
	//Customer Information
	int customerID;
	string name;
	string address;
	int age;
	string telephoneNum;

public:
	/// CONSTRUCTOR(S)
	//Constructor requires new customers to have certain information
	Customer(int customerID, string name, string address, int age, string teleNum);

	/// ACCESSOR(S)/MUTATOR(S)
	void setCustID(int custID);
	void setName(string name);
	void setAddress(string address);
	void setAge(int age);
	void setTelNum(string telNum);

	int getCustID();
	string getName();
	string getAddress();
	int getAge();
	string getTelNum();

	/// VIRTUAL ACCESSOR(S)
	//Default values given in case generic customer requests info
	virtual double getCheckIntRate() { return 0; }
	virtual double getSavingIntRate() { return 0; }
	virtual double getCheckFee() { return 0; }
	virtual double getOverdraftFee() { return 0; }
};

#endif