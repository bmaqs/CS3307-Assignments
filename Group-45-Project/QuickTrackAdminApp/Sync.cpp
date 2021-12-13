#include <stdlib.h>
#include <iostream>
#include <driver.h>
#include <exception.h>
#include <resultset.h>
#include <statement.h>
#include "database.h"
#include "tempUser.cpp"
#include "Sync.h"
#include <vector>
#include <prepared_statement.h>
using namespace sql;
using namespace std;

/*
struct tempUser{
	string timeIn;
	string timeOut;
	string userID;
	string firstName;
	string lastName;
	string email;
	string phoneNumber;
}
*/


Sync::Sync(){
	//cout << "Hello world" << endl;
	this->remote = Database(1, "sql9.freemysqlhosting.net", "sql9372596", "fNf8Kr8wZD", "sql9372596");
	this->local = Database(1, "tcp://localhost:3306", "root", "", "quicktracker");
		
}
//collect data from local database
//push all those data into the stack for late use
vector<tempUser> Sync::localSignInOut(){
		tempUser user;
		vector<tempUser> users;
		this->local.stmt= local.con->createStatement();
    	this->local.res = local.stmt->executeQuery("SELECT * FROM tbl_SignInOut"); 
		while(local.res->next()){
			this->localUserID.push_back(stoi(local.res->getString("SIO_id")));
			user.timeIn=local.res->getString("SIO_timeIn");
			user.timeOut=local.res->getString("SIO_timeOut");
			user.userID=local.res->getString("SIO_userID");
			user.firstName=local.res->getString("SIO_firstName");
			user.lastName=local.res->getString("SIO_lastName");
			user.email=local.res->getString("SIO_email");
			user.phoneNumber=local.res->getString("SIO_phoneNumber");
			user.businessID=local.res->getString("SIO_businessID");
			users.push_back(user);
			
		}
		return users;
}

//will export data from local database to remote database
//it will then remove any log from local database
void Sync::exportSignInOut(vector<tempUser> customers){

		for(tempUser customer:customers){
		remote.pstmt = remote.con->prepareStatement("INSERT INTO tbl_SignInOut(SIO_timeIn, SIO_timeOut, SIO_userID, SIO_firstname, SIO_lastName, SIO_email, SIO_phoneNumber, SIO_businessID) VALUES ('"+customer.timeIn+"','"+customer.timeOut+"','"+customer.userID+"','"+customer.firstName+"','"+customer.lastName+"','"+customer.email+"','"+customer.phoneNumber+"','"+customer.businessID+"')");
		remote.pstmt->executeUpdate();
		}
		
		for(int i:this->localUserID){
			deleteLocalSignInOut(i);
		}
	
}

//will delete rows from local database based on SIO_id
void Sync::deleteLocalSignInOut(int id){
	local.pstmt = local.con->prepareStatement("DELETE FROM tbl_SignInOut WHERE SIO_id='"+to_string(id)+"'");
		local.pstmt->executeUpdate();
}



