#ifndef SIGNINOUT
#define SIGNINOUT
#include<stdlib.h>
#include<string>
#include "IsCustomer.cpp"
#include "CustomerDatabase.h"
#include "Database.h"
using namespace std;

/**
* @brief This class extends the database class and allows for sign in and sign out of customers
* 
* @author Abdulrahim Hamed (ahamed4)
* @author Braikhna Yousafzai (byousafz)
* @author Colin Stoddart (cstodda6)
* @author Evangelos Makris (emakris2)
* @author Jem Parlakyigit (mparlaky)
*/
class SignInOut:public Database{
	private:
	
	public:
		/**
 		* @brief Empty Constructor for the sign in and out class
 		* 
 		* @return A SignInOut object
		 */
		SignInOut();

		/**
 		* @brief Signs in a customer to the database who has an account
 		* @param customerID An Int representaion of the customers ID
		* @param businessID An Int representaion of the buisness ID
		* @param customer The Customer Database to sign the customer into
		*/
		void SignIn(int customerID, int businessID, CustomerDatabase customer);
		
		/**
 		* @brief Signs in a customer to the database who does not have an account
 		* @param customerID An Int representaion of the customers ID
		* @param firstName A String representaion of the customers first name
		* @param lastName A String representaion of the customers last name
		* @param phoneNumber A Long Int representaion of the customers phone number
		* @param email A String representaion of the customers email
		* @param businessID An Int representaion of the buisness ID
		* @param customer The Customer Database to sign the customer into
		*/
		void SignIn(int customerID, string firstName, string lastName, long int phoneNumber, string email, int businessID, CustomerDatabase customer);
		
		/**
 		* @brief Signs out a customer from the database
 		* @param customerID An Int representaion of the customers ID
		* @param businessID An Int representaion of the buisness ID
		* @param customer The Customer Database to sign the customer into
		*/
		void SignOut(int customerID, int businessID, CustomerDatabase customer);
		
		/**
 		* @brief Finds emails that fall within a specified range of time
 		* 
 		* @param inTime The time to start checking from
 		* @param outTime The time to stop checking from
 		* @param businessID The business to check
 		* @return vector<string> List of emails that fall within that range of time
		 */
		vector<string> findEmails(string inTime, string outTime, int businessID);
};
#endif
