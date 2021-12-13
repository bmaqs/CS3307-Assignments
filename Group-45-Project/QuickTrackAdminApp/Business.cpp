#include "Business.h"
#include "Customer.h"
#include <iostream>

using namespace std;

Business::Business(){
	this->name = "";
	this->businessID = 0;
	this->email = "";
	this->description = "";
	this->streetAddress = "";
	this->postalCode = "";
	this->city = "";
	this->province = "";
	this->phoneNumber = 0;
}

Business::Business(string name, string email){
	this->name = name;
	this->businessID = businessID;
	this->email = email;
	this->description = "";
	this->streetAddress = "";
	this->postalCode = "";
	this->city = "";
	this->province = "";
	this->phoneNumber = 0;
}
void Business::setName(string name){this->name = name;}

void Business::setBusinessID(int businessID){this->businessID = businessID;}

void Business::setEmail(string email){this->email = email;}

void Business::setDescription(string description){this->description = description;}

void Business::setStreetAddress(string address){this->streetAddress = address;}

void Business::setPostalCode(string postalCode){this->postalCode = postalCode;}

void Business::setCity(string city){this->city = city;}

void Business::setProvince(string prov){this->province = prov;}

void Business::setPhoneNumber(long int phone){this->phoneNumber = phone;}

string Business::getName(){return this->name;}

int Business::getBusinessID(){return this->businessID;}

string Business::getEmail(){return this->email;}

string Business::getDescription(){return this->description;}

string Business::getStreetAddress(){return this->streetAddress;}

string Business::getPostalCode(){return this->postalCode;}

string Business::getCity(){return this->city;}

string Business::getProvince(){return this->province;}

long int Business::getPhoneNumber(){return this->phoneNumber;}

void Business::toString(Business business){
	cout << business.getBusinessID() << "	" << business.getName() << "	" << business.getEmail() << "		" << business.getPhoneNumber() << "	" <<
	business.getDescription() << "	" << business.getStreetAddress() << "	" << business.getPostalCode() << "	" <<
	business.getCity() << "		" << business.getProvince() << "	" << endl;
}

vector<Customer> Business::createCustomerList(){
	vector<Customer> customerList;
	return customerList;
}

vector<Customer> Business::addCustomer(vector<Customer> customerList, Customer newCustomer){
	customerList.push_back(newCustomer);
	return customerList;
}
