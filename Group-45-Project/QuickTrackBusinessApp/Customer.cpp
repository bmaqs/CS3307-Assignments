#include "Customer.h"

using namespace std;

//null consturctor
Customer::Customer(){
	this->userName = "";
	this->password = "";
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->phoneNum = 0;
	this->uniqueID = 0;
}
//constructor without uniqueID
Customer::Customer(string user, string first, string last, string pass, string emailAddr,long long int phoneNumber){
	this->userName = user;
	this->password = pass;
	this->firstName = first;
	this->lastName = last;
	this->email = emailAddr;
	this->phoneNum = phoneNumber;

}
//getters
string Customer::getUserName(){ return this->userName;}
string Customer::getPassword(){return this->password;}
string Customer::getFirstName(){return this->firstName;}
string Customer::getLastName(){return this->lastName;}
string Customer::getEmail(){return this->email;}
long long int Customer::getPhoneNum(){return this->phoneNum;}
int Customer::getUniqueID(){return this->uniqueID;}
//setters
void Customer::setUserName(string uName){this->userName = uName;}
void Customer::setPassword(string pass){this->password = pass;}
void Customer::setFirstName(string fName){this->firstName = fName;}
void Customer::setLastName(string lName){this->lastName = lName;}
void Customer::setEmail(string emailAddr){this->email = emailAddr;}
void Customer::setPhoneNum(long long int phoneNumber){this->phoneNum = phoneNumber;}
void Customer::setUniqueID(int id){this->uniqueID = id;}
