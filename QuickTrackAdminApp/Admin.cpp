#include "Admin.h"
#include <vector>

using namespace std;

Admin::Admin(){
	this->adminID = 0;
	this->businessID = 0;
	this->adminUserName ="";
	this->adminPass = "";
}

Admin::Admin(int businessID, string username, string pass) {
	this->adminID = 0;
	this->businessID = businessID;
	this->adminUserName = username;
	this->adminPass = pass;
}
void Admin::setAdminID(int id){this->adminID = id;}

void Admin::setBusinessID(int id){this->businessID = id;}

void Admin::setAdminUserName(string user){this->adminUserName = user;}

void Admin::setAdminPass(string pass){this->adminPass = pass;}

int Admin::getAdminID(){return this->adminID;}

int Admin::getBusinessID(){return this->businessID;}

string Admin::getAdminUserName(){return this->adminUserName;}

string Admin::getAdminPass(){return this->adminPass;}
