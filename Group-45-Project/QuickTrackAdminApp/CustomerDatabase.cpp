#include <stdlib.h>
#include <iostream>
#include <driver.h>
#include <exception.h>
#include <resultset.h>
#include <statement.h>
#include <vector>
#include <prepared_statement.h>
#include "Customer.h"
#include "CustomerDatabase.h"
#include "Database.h"

using namespace sql;
using namespace std;

	CustomerDatabase::CustomerDatabase(string serverName, string userName, string password):Database(serverName, userName, password){}
	
	Customer CustomerDatabase::selectCustomer(string userEmail){
		Customer user;
		this->stmt= con->createStatement();
    		this->res = stmt->executeQuery("SELECT * FROM tbl_customers WHERE customer_email ='"+ userEmail +"'"); 
		while(this->res->next()){
			user.setUniqueID(res->getInt("customer_id"));
			user.setUserName(res->getString("customer_userName"));
			user.setPhoneNum(res->getInt("customer_phoneNum"));
			user.setEmail(res->getString("customer_email"));
			user.setFirstName(res->getString("customer_firstName"));
			user.setLastName(res->getString("customer_lastName"));
			user.setPassword(res->getString("customer_password"));
		}

		return user;
	}

	Customer CustomerDatabase::selectCustomer(int uniqueID){
		Customer user;
		this->stmt= con->createStatement();
    		this->res = stmt->executeQuery("SELECT * FROM tbl_customers WHERE customer_id='"+ to_string(uniqueID) +"'");
        
		while(this->res->next()){
			user.setUniqueID(res->getInt("customer_id"));
			user.setUserName(res->getString("customer_userName"));
			user.setPhoneNum(res->getInt("customer_phoneNum"));
			user.setEmail(res->getString("customer_email"));
			user.setFirstName(res->getString("customer_firstName"));
			user.setLastName(res->getString("customer_lastName"));
			user.setPassword(res->getString("customer_password"));
		}
		
		return user;
	}

	int CustomerDatabase::searchCustomer(string username){
		this->stmt = con->createStatement();
		this->res = stmt->executeQuery("SELECT * FROM tbl_customers WHERE customer_username ='" + username+"'");
		return this->res->rowsCount();
		delete this->stmt;
		delete this->res;
	}

	int CustomerDatabase::searchCustomer(int id){
		this->stmt = con->createStatement();
		this->res = stmt->executeQuery("SELECT * FROM tbl_customers WHERE customer_id =" + to_string(id) +"");
		return this->res->rowsCount();
		delete this->stmt;
		delete this->res;
	}
	
	vector<Customer> CustomerDatabase::selectCustomers(string userEmail[], int arrSize){
		vector<Customer> userdb;
		for(int i = 0; i < arrSize; i++) {
			Customer user = selectCustomer(userEmail[i]);
			userdb.push_back(user);
		}
		return userdb;
	}

	vector<Customer> CustomerDatabase::selectCustomers(vector<int> listUniqueID){
		vector<Customer> userdb;
		int i =0;
		for(auto iterator = userdb.begin(); iterator != userdb.end(); iterator++) {
			Customer user = selectCustomer(listUniqueID[i]);
			userdb.push_back(user);
			i++;
		}
		return userdb;
	}

	void CustomerDatabase::addCustomer(Customer user){
		string values;
		values = "'"+user.getUserName()+"','"+
		to_string(user.getPhoneNum())+"','"+
		user.getEmail()+"','"+
		user.getFirstName()+"','"+
		user.getLastName()+"'";
		this->pstmt = con->prepareStatement("INSERT INTO tbl_customers(customer_username,customer_phoneNum, customer_email, customer_firstName, customer_lastName) VALUES ("+values+")");
		this->pstmt->executeUpdate();
		delete this->pstmt;
		return;
	}
	
	Customer CustomerDatabase::updateUniqueID(Customer user){
		string values;
		values = "customer_firstName = '" + user.getFirstName() + "' AND "+
		"customer_lastName = '" + user.getLastName() + "' AND " +
		"customer_email = '" + user.getEmail() + "'";
		this->stmt = con->createStatement();
		this->res = stmt->executeQuery("SELECT customer_id FROM tbl_customers WHERE " + values);
		while (this->res->next()){
                       	user.setUniqueID(res->getInt("customer_id"));
		}
		return user;
	}

	vector<Customer> CustomerDatabase::getAll(){
		vector<Customer> userdb;
		Customer user;
		this->stmt= con->createStatement();
    		this->res = stmt->executeQuery("SELECT * FROM tbl_customers");
		while(this->res->next()){
			user.setUniqueID(res->getInt("customer_id"));
			user.setUserName(res->getString("customer_username"));
			user.setPhoneNum(res->getInt("customer_phoneNum"));
			user.setEmail(res->getString("customer_email"));
			user.setFirstName(res->getString("customer_firstName"));
			user.setLastName(res->getString("customer_lastName"));
			user.setPassword(res->getString("customer_password"));
			userdb.push_back(user);
		}
		return userdb;
	}
