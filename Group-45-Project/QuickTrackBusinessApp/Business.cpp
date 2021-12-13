#include "Business.h"
#include "Customer.h"

using namespace std;

Business::Business(string name, int businessID, string email){
	//varialbe names are as follow
	//string name, description, streetAddress, postalCode, city, province, email;
	//int businessID, phoneNumber;
	//vector<SignInOut> customers;
	this->name = name;
	this->businessID = businessID;
	this->email = email;

}
void Business::setDescription(string description){this->description = description;}
void Business::setStreetAddress(string address){this->streetAddress = address;}
void Business::setPostalCode(string postalCode){this->postalCode = postalCode;}
void Business::setCity(string city){this->city = city;}
void Business::setProvince(string prov){this->province = prov;}
void Business::setPhoneNumber(int phone){this->phoneNumber = phone;}
vector<SignInOut> Business::createCustomerList(){
	vector<Customer> customerList;
	return customerList;
}
vector<SignInOut> Business::addCustomer(Customer newCustomer){
	customerList.push_back(newCustomer);
	return customerList;
}
