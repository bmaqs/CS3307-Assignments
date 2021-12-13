#include <stdlib.h>
#include <iostream>
#include <driver.h>
#include <exception.h>
#include <resultset.h>
#include <statement.h>
#include <vector>
#include "Database.h"

#include <prepared_statement.h>
#include "Customer.h"
using namespace sql;
using namespace std;

/**
* @brief This class checks if the customer is a customer in the database
* 
* @param msg The message to be sent to the emails
* @author Abdulrahim Hamed (ahamed4)
* @author Braikhna Yousafzai (byousafz)
* @author Colin Stoddart (cstodda6)
* @author Evangelos Makris (emakris2)
* @author Jem Parlakyigit (mparlaky)
*/

class IsCustomer:public Database {
	public:
	/**
	* @brief Creates a connection to the database
	* 
	* @see Database::Database(string serverName, string userName, string password);
	*/
	IsCustomer():Database("sql9.freemysqlhosting.net", "sql9372596", "fNf8Kr8wZD"){}


/**
* @brief Searches for the number of customers with that username
* 
* @param username A string version of the username
* @returns The Int corresponding to the number of customers with that ID
*/
int searchCustomer(string username){
	this->stmt = con->createStatement();
	this->res = stmt->executeQuery("SELECT * FROM tbl_customers WHERE customer_userName ='" + username+"'");
	return this->res->rowsCount();
	delete this->stmt;
	delete this->res;
}

/**
* @brief Searches for the number of customers with that ID
* 
* @param id An Int version of the ID
* @returns The Int corresponding to the number of customers with that ID, which should be 1
*/
int searchCustomer(int id){
	this->stmt = con->createStatement();
	this->res = stmt->executeQuery("SELECT * FROM tbl_customers WHERE customer_id ='" + to_string(id) +"'");
	return this->res->rowsCount();
	delete this->stmt;
	delete this->res;
}

~IsCustomer(){
	delete this->stmt;
	delete this->res;
}
};

