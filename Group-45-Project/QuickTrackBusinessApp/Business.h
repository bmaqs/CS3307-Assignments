#ifndef BUSINESS
#define BUSINESS
#include<stdlib.h>
#include<string>
#include<vector>
#include"SignInOut.h"

using namespace std;

class Business{
	string name, description, streetAddress, postalCode, city, province, email;
	int businessID, phoneNumber;
	vector<SignInOut> customers;
	public:

	Business(string name, int businessID, string email);
	void setDescription(string description);
	void setStreetAddress(string address);
	void setPostalCode(string postalCode);
	void setCity(string city);
	void setProvince(string prov);
	void setPhoneNumber(int phone);
	vector<SignInOut> createCustomerList();
	vector<SignInOut> addCustomer();
	};
	#endif
