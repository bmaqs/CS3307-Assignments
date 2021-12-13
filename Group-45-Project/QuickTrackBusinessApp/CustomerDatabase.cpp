#include <stdlib.h>
#include <iostream>
#include <driver.h>
#include <exception.h>
#include <resultset.h>
#include <statement.h>
//#include <./lib/include/mysqlx/devapi/result.h>
#include <vector>
#include <prepared_statement.h>
#include "Customer.h"
#include "CustomerDatabase.h"
#include "Database.h"

using namespace sql;
using namespace std;

//constructor
CustomerDatabase::CustomerDatabase(string serverName, string userName, string password):Database(serverName, userName, password){}

//select single customer based on their email address
//returns a customer object with their user info
Customer CustomerDatabase::selectCustomer(string userEmail){
    Customer user;
    this->stmt= con->createStatement();
    this->res = stmt->executeQuery("SELECT * FROM tbl_customers WHERE customer_email ='"+ userEmail +"'");
    while(this->res->next()){
        user.setUniqueID(res->getInt("customer_id"));
        user.setUserName(res->getString("customer_userName"));
        user.setPhoneNum(res->getInt64("customer_phoneNum"));
        user.setEmail(res->getString("customer_email"));
        user.setFirstName(res->getString("customer_firstName"));
        user.setLastName(res->getString("customer_lastName"));
        user.setPassword(res->getString("customer_password"));
    }

    return user;
}

//select single customer bassed on their scanned id
//returns user information through Customer object
Customer CustomerDatabase::selectCustomer(int uniqueID){
    Customer user;
    this->stmt= con->createStatement();
    this->res = stmt->executeQuery("SELECT * FROM tbl_customers WHERE customer_id='"+ to_string(uniqueID) +"'");

    while(this->res->next()){
        user.setUniqueID(res->getInt("customer_id"));
        user.setUserName(res->getString("customer_userName"));
        user.setPhoneNum(res->getInt64("customer_phoneNum"));
        user.setEmail(res->getString("customer_email"));
        user.setFirstName(res->getString("customer_firstName"));
        user.setLastName(res->getString("customer_lastName"));
        user.setPassword(res->getString("customer_password"));
    }

    return user;
}

Customer CustomerDatabase::selectCustomerByPhone(string phoneNumber){
    Customer user;
    this->stmt= con->createStatement();
    this->res = stmt->executeQuery("SELECT * FROM tbl_customers WHERE customer_phoneNum='"+ phoneNumber +"'");

    while(this->res->next()){
        user.setUniqueID(res->getInt("customer_id"));
        user.setUserName(res->getString("customer_userName"));
        user.setPhoneNum(res->getInt64("customer_phoneNum"));
        user.setEmail(res->getString("customer_email"));
        user.setFirstName(res->getString("customer_firstName"));
        user.setLastName(res->getString("customer_lastName"));
        user.setPassword(res->getString("customer_password"));
    }

    return user;
}

//searchCustomer by username
//retun number of users with that username
int CustomerDatabase::searchCustomer(string username){
    this->stmt = con->createStatement();
    this->res = stmt->executeQuery("SELECT * FROM tbl_customers WHERE customer_username ='" + username+"'");
    return this->res->rowsCount();
    delete this->stmt;
    delete this->res;
}

//searchCustomer by uniqueID
//return number of users with this ID (should be one)
int CustomerDatabase::searchCustomer(int id){
    this->stmt = con->createStatement();
    this->res = stmt->executeQuery("SELECT * FROM tbl_customers WHERE customer_id =" + to_string(id) +"");
    return this->res->rowsCount();
    delete this->stmt;
    delete this->res;
}

bool CustomerDatabase::isCustomerInside(int id){
    this->stmt = con->createStatement();
    this->res = stmt->executeQuery("SELECT * FROM tbl_SignInOut WHERE SIO_userID =" + to_string(id) +" AND SIO_timeOut IS NULL");
    return this->res->rowsCount()==1;
    delete this->stmt;
    delete this->res;
}

//selectCustomers return a vector it takes in an array of userEmail it will return with their information
vector<Customer> CustomerDatabase::selectCustomers(string userEmail[], int arrSize){
    vector<Customer> userdb;
    for(int i = 0; i < arrSize; i++) {
        Customer user = selectCustomer(userEmail[i]);
        userdb.push_back(user);
    }
    return userdb;
}


//selectCustomers - find customers matching to an array of uniqueIDs
//return a vector of customer objects
vector<Customer> CustomerDatabase::selectCustomers(int uniqueID[], int arrSize){
    vector<Customer> userdb;
    for(int i = 0; i < arrSize; i++) {
        Customer user = selectCustomer(uniqueID[i]);
        userdb.push_back(user);
    }
    return userdb;
}

//addCustomer - add Customer obj to database
bool CustomerDatabase::addCustomer(Customer user){
    string values;
    values = "'"+user.getUserName()+"','"+
            to_string(user.getPhoneNum())+"','"+
            user.getEmail()+"','"+
            user.getFirstName()+"','"+
            user.getLastName()+"'";

    try {
        this->pstmt = con->prepareStatement("INSERT INTO tbl_customers(customer_username,customer_phoneNum, customer_email, customer_firstName, customer_lastName) VALUES ("+values+")");
        this->pstmt->executeUpdate();
        delete this->pstmt;
        return true;

    }  catch (exception e) {

        return false;
    }



}

//stores uniqueID generated by database to Customer object
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

//returns Customer object vector containing all customers in the database
vector<Customer> CustomerDatabase::getAll(){
    vector<Customer> userdb;
    Customer user;
    this->stmt= con->createStatement();
    this->res = stmt->executeQuery("SELECT * FROM tbl_customers");
    while(this->res->next()){
        user.setUniqueID(res->getInt("customer_id"));
        user.setUserName(res->getString("customer_username"));
        user.setPhoneNum(res->getInt64("customer_phoneNum"));
        user.setEmail(res->getString("customer_email"));
        user.setFirstName(res->getString("customer_firstName"));
        user.setLastName(res->getString("customer_lastName"));
        user.setPassword(res->getString("customer_password"));
        userdb.push_back(user);
    }
    return userdb;
}

vector<Customer> CustomerDatabase::getSignedIn(){
    vector<Customer> allSignedInCustomers;
    Customer user;
    this->stmt= con->createStatement();
    this->res = stmt->executeQuery("SELECT * FROM tbl_SignInOut WHERE SIO_timeOut IS NULL");
    while(this->res->next()){
        user.setUniqueID(res->getInt("SIO_userID"));
        user.setPhoneNum(res->getInt64("SIO_phoneNumber"));
        user.setEmail(res->getString("SIO_email"));
        user.setFirstName(res->getString("SIO_firstName"));
        user.setLastName(res->getString("SIO_lastName"));
        allSignedInCustomers.push_back(user);
    }
    return allSignedInCustomers;
}
