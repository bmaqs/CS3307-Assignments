#include <stdlib.h>
#include <iostream>
#include <driver.h>
#include <exception.h>
#include <resultset.h>
#include <statement.h>
#include <vector>
#include <prepared_statement.h>
#include "Database.h"
#include "Business.h"
#include "BusinessDatabase.h"
#include "Admin.h"

using namespace sql;
using namespace std;

BusinessDatabase::BusinessDatabase(string serverName, string userName, string password) : Database(serverName, userName, password) {}

Business BusinessDatabase::selectBusiness(int businessID)
{
	Business business;
	this->stmt = con->createStatement();
	this->res = stmt->executeQuery("SELECT * FROM tbl_businesses WHERE business_id = '" + to_string(businessID) + "'");

	while (this->res->next())
	{
		business.setBusinessID(res->getInt("business_id"));
		business.setName(res->getString("business_name"));
		business.setDescription(res->getString("business_description"));
		business.setStreetAddress(res->getString("business_streetAddress"));
		business.setPostalCode(res->getString("business_postalCode"));
		business.setCity(res->getString("business_city"));
		business.setProvince(res->getString("business_province"));
		business.setPhoneNumber(res->getInt("business_phoneNumber"));
		business.setEmail(res->getString("business_email"));
	}

	return business;
}

int BusinessDatabase::searchBusiness(string name)
{
	this->stmt = con->createStatement();
	this->res = stmt->executeQuery("SELECT * FROM tbl_businesses WHERE business_name = '" + name + "'");
	return this->res->rowsCount();
}

vector<Business> BusinessDatabase::selectBusinesses(vector<int> businessIDList)
{
	vector<Business> businessList;
	int i = 0;
	for (auto iterator = businessIDList.begin(); iterator != businessIDList.end(); iterator++)
	{
		Business business = selectBusiness(businessIDList.at(i));
		businessList.push_back(business);
		i++;
	}
	return businessList;
}

bool BusinessDatabase::addBusiness(Business business)
{
	if (searchBusiness(business.getName()) != 0)
	{
		cout << "Business name already exists" << endl;
		return false;
	}
	else
	{
		string values;
		values = "'" + business.getName() + "','" +
				 business.getDescription() + "','" +
				 business.getStreetAddress() + "','" +
				 business.getPostalCode() + "','" +
				 business.getCity() + "','" +
				 business.getProvince() + "','" +
				 to_string(business.getPhoneNumber()) + "','" +
				 business.getEmail() + "'";

		this->pstmt = con->prepareStatement("INSERT INTO tbl_businesses(business_name, business_description, business_streetAddress, business_postalCode, business_city, business_province, business_phoneNumber, business_email) VALUES (" + values + ")");
		this->pstmt->executeUpdate();
		delete this->pstmt;
		return true;
	}
}

Business BusinessDatabase::updateBusinessID(Business business)
{
	string values;
	values = "business_name = '" + business.getName() + "' AND " +
			 "business_description = '" + business.getDescription() + "' AND " +
			 "business_streetAddress = '" + business.getStreetAddress() + "' AND " +
			 "business_postalCode = '" + business.getPostalCode() + "' AND " +
			 "business_city = '" + business.getCity() + "' AND " +
			 "business_province = '" + business.getProvince() + "' AND " +
			 "business_phoneNumber = " + to_string(business.getPhoneNumber()) + " AND " +
			 "business_email = '" + business.getEmail() + "'";

	this->stmt = con->createStatement();
	this->res = stmt->executeQuery("SELECT business_id FROM tbl_businesses WHERE " + values);
	while (this->res->next())
	{
		business.setBusinessID(res->getInt("business_id"));
	}
	return business;
}

int BusinessDatabase::searchAdmin(string name, int businessID)
{
	this->stmt = con->createStatement();
	this->res = stmt->executeQuery("SELECT * FROM tbl_StoreAdmin WHERE SA_businessID = " + to_string(businessID) + " AND SA_adminUserName = '" + name + "'");
	return this->res->rowsCount();
}

bool BusinessDatabase::addAdmin(Admin admin)
{
	if (searchAdmin(admin.getAdminUserName(), admin.getBusinessID()) != 0)
	{
		cout << "Admin username already exsits" << endl;
		return false;
	}
	else
	{

		string values;
		values = "'" + to_string(admin.getBusinessID()) + "','" +
				 admin.getAdminUserName() + "','" +
				 admin.getAdminPass() + "'";

		this->pstmt = con->prepareStatement("INSERT INTO tbl_StoreAdmin(SA_businessID, SA_adminUserName, SA_adminPassword) VALUES (" + values + ")");
		this->pstmt->executeUpdate();
		delete this->pstmt;
		return true;
	}
}

Admin BusinessDatabase::updateAdminID(Admin admin)
{
	string values;
	values = "SA_businessID = " + to_string(admin.getBusinessID()) + " AND " +
			 "SA_adminUserName = '" + admin.getAdminUserName() + "' AND " +
			 "SA_adminPassword = '" + admin.getAdminPass() + "'";

	this->stmt = con->createStatement();
	this->res = stmt->executeQuery("SELECT SA_id FROM tbl_StoreAdmin WHERE " + values);
	while (this->res->next())
	{
		admin.setAdminID(res->getInt("SA_id"));
	}
	return admin;
}

bool BusinessDatabase::checkAdminLogin(Admin admin)
{
	string values;
	string password;
	if (admin.getAdminUserName() != "")
	{
		values = "SA_businessID = " + to_string(admin.getBusinessID()) + " AND " +
				 "SA_adminUserName = '" + admin.getAdminUserName() + "'";
	}
	else if (admin.getAdminID() != 0)
	{
		values = "SA_businessID = " + to_string(admin.getBusinessID()) + "AND " +
				 "SA_id = " + to_string(admin.getAdminID());
	}
	this->stmt = con->createStatement();
	this->res = stmt->executeQuery("SELECT SA_adminPassword FROM tbl_StoreAdmin WHERE " + values);
	while (this->res->next())
	{
		password = res->getString("SA_adminPassword");
	}
	if (password == admin.getAdminPass())
	{
		return true;
	}
	else
	{
		return false;
	}
}

vector<Business> BusinessDatabase::getAll()
{
	vector<Business> businessList;
	Business business;
	this->stmt = con->createStatement();
	this->res = stmt->executeQuery("SELECT * FROM tbl_businesses");
	while (this->res->next())
	{
		business.setBusinessID(res->getInt("business_id"));
		business.setName(res->getString("business_name"));
		business.setDescription(res->getString("business_description"));
		business.setStreetAddress(res->getString("business_streetAddress"));
		business.setPostalCode(res->getString("business_postalCode"));
		business.setCity(res->getString("business_city"));
		business.setProvince(res->getString("business_province"));
		business.setPhoneNumber(res->getInt("business_phoneNumber"));
		business.setEmail(res->getString("business_email"));
		businessList.push_back(business);
	}
	return businessList;
}

vector<int> BusinessDatabase::getTwoWeekCustomers(Business business)
{
	vector<int> listCustomerID;
	int customerID;
	this->stmt = con->createStatement();
	this->res = stmt->executeQuery("SELECT SIO_userID FROM tbl_SignInOut WHERE date(SIO_timeOut) > DATE_SUB(NOW(), INTERVAL 14 DAY) AND SIO_businessID = " + to_string(business.getBusinessID()));
	while (this->res->next())
	{
		customerID = res->getInt("SIO_userID");
		listCustomerID.push_back(customerID);
	}

	return listCustomerID;
}

vector<int> BusinessDatabase::getCustomersInStore(Business business)
{
	vector<int> listCustomerID;
	int customerID;
	this->stmt = con->createStatement();
	this->res = stmt->executeQuery("SELECT SIO_userID FROM tbl_SignInOut WHERE SIO_timeOut IS NULL AND SIO_businessID = " + to_string(business.getBusinessID()));
	while (this->res->next())
	{
		customerID = res->getInt("SIO_userID");
		listCustomerID.push_back(customerID);
	}

	return listCustomerID;
}
