#include <string>
#include "Customer.h"

using std::string;

/**
Customer - Implementation
The Bank has Customers.  Each Customer has a name, address, age, and telephone number.
Additionally, there are specialized types of Customers: Adult, Senior, and Student.
Each type of Customer has its own checking and savings interest rates,
as well as its own checking and overdraft fees.

@author: Kostiantyn Makrasnov
*/


/// CONSTRUCTOR(S)
Customer::Customer(int customerID, string name, string address, int age, string teleNum) :
	customerID(customerID), name(name), address(address), age(age), telephoneNum(teleNum) {}



/// ACCESSOR(S)/MUTATOR(S)
void Customer::setCustID(int custID) { customerID = custID; }
void Customer::setName(string name) { this->name = name; }
void Customer::setAddress(string address) { this->address = address; }
void Customer::setAge(int age) { this->age = age; }
void Customer::setTelNum(string telNum) { telephoneNum = telNum; }

int Customer::getCustID() { return customerID; }
string Customer::getName() { return name; }
string Customer::getAddress() { return address; }
int Customer::getAge() { return age; }
string Customer::getTelNum() { return telephoneNum; }