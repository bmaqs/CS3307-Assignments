#include "SignInOut.h"
#include "CustomerDatabase.h"
#include "Database.h"
#include <iostream>
#include <string>

using namespace std;

SignInOut::SignInOut() {}

void SignInOut::SignIn(int customerID, int businessID, CustomerDatabase customer)
{
	int total = customer.searchCustomer(customerID);
	if (total == 1)
	{
		this->pstmt = con->prepareStatement("INSERT INTO tbl_SignInOut(SIO_userID, SIO_businessID) VALUES ('" + to_string(customerID) + "','" + to_string(businessID) + "')");
		this->pstmt->executeUpdate();
	}
	else
	{
		cout << "User does not exist" << endl;
		cout << endl;
	}
}

void SignInOut::SignIn(int customerID, string firstName, string lastName, long int phoneNumber, string email, int businessID, CustomerDatabase customer)
{
	int total = customer.searchCustomer(customerID);
	if (total == 1)
	{
		this->pstmt = con->prepareStatement("INSERT INTO tbl_SignInOut(SIO_userID, SIO_firstname, SIO_lastName, SIO_phoneNumber, SIO_email, SIO_businessID) VALUES ('" + to_string(customerID) + "','" + firstName + "', '" + lastName + "', '" + to_string(phoneNumber) + "', '" + email + "',  '" + to_string(businessID) + "')");
		this->pstmt->executeUpdate();
	}
	else
	{
		cout << "User does not exist" << endl;
		cout << endl;
	}
}

void SignInOut::SignOut(int customerID, int businessID, CustomerDatabase customer)
{
	int total = customer.searchCustomer(customerID);
	if (total == 1)
	{
		this->pstmt = con->prepareStatement("UPDATE tbl_SignInOut SET SIO_timeOut = NOW() WHERE SIO_userID = '" + to_string(customerID) + "' AND SIO_businessID = " + to_string(businessID) + " AND SIO_timeOut IS NULL");
		this->pstmt->executeUpdate();
	}
	else
	{
		cout << "User does not exist" << endl;
		cout << endl;
	}
}

vector<string> SignInOut::findEmails(string inTime, string outTime, int businessID)
{
	vector<string> emailDB;
	this->stmt = con->createStatement();
	this->res = stmt->executeQuery("SELECT * FROM tbl_SignInOut WHERE \"" + inTime + "\" <= SIO_timeOut AND \"" + outTime + "\" >= SIO_timeIn" + " AND \"" + to_string(businessID) + "\" = SIO_businessID");
	while (this->res->next())
	{
		emailDB.push_back(res->getString("SIO_email"));
	}
	delete this->stmt;
	delete this->res;
	return emailDB;
}
