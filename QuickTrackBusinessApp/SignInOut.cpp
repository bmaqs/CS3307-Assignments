#include "SignInOut.h"
#include "CustomerDatabase.h"
#include "Database.h"
#include <iostream>
#include <string>

using namespace std;

//null constructor
SignInOut::SignInOut(){}

//SignIn - uniqueID, businessID, customer
//requires only mandatory table attributes
//bool SignInOut::SignIn(int customerID, int businessID, CustomerDatabase customer){
//    //    int total = customer.searchCustomer(customerID);
//    //    if(total == 1){
//    try{
//        this->pstmt = con->prepareStatement("INSERT INTO tbl_SignInOut(SIO_userID, SIO_businessID) VALUES ('" + to_string(customerID) + "','" + to_string(businessID) + "')");
//        this->pstmt->executeUpdate();
//        return true;
//    }
//    //    else
//    catch(exception e)
//    {
//        return false;
//        cout << "User does not exist"<<endl;
//        cout << endl;
//    }
//}

//SignIn
//requires mandatory attributes and optional attributes
bool SignInOut::SignIn(int customerID, string firstName, string lastName, long long int phoneNumber, string email, int businessID, CustomerDatabase customer){
    try{
        this->pstmt = con->prepareStatement("INSERT INTO tbl_SignInOut(SIO_userID, SIO_firstname, SIO_lastName, SIO_phoneNumber, SIO_email, SIO_businessID) VALUES ('" + to_string(customerID) + "','" + firstName + "', '" + lastName + "', '" + to_string(phoneNumber) + "', '" + email + "',  '" + to_string(businessID) + "')");
        this->pstmt->executeUpdate();
        delete this->pstmt;
        return true;
    }
    catch(exception e) {
        return false;

    }
}            

//SignOut
//requires only mandatory tables attributes
bool SignInOut::SignOut(int customerID, int businessID, CustomerDatabase customer){    
    try {
        this->pstmt = con->prepareStatement("UPDATE tbl_SignInOut SET SIO_timeOut = NOW() WHERE SIO_userID = '" + to_string(customerID) + "' AND SIO_businessID = " + to_string(businessID) + " AND SIO_timeOut IS NULL");
        this->pstmt->executeUpdate();
        delete this->pstmt;
        return true;

    }
    catch (exception e) {
        return false;
    }

}


