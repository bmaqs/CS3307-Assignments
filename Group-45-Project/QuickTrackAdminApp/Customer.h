#ifndef CUSTOMER
#define CUSTOMER
#include<stdlib.h>
#include<iostream>
#include<string>

using namespace std;

/**
 * @brief This class creates Customer objects which contain information related to customers
 * @author Abdulrahim Hamed (ahamed4)
 * @author Braikhna Yousafzai (byousafz)
 * @author Colin Stoddart (cstodda6)
 * @author Evangelos Makris (emakris2)
 * @author Jem Parlakyigit (mparlaky)
 */
class Customer{
	private:
		string userName, password, firstName, lastName, email;
		long int phoneNum;
		int uniqueID;
	public:
	/**
	* @brief Null Constructor for a new Customer object
	* 
	*/
	Customer();
	
	/**
	* @brief Construct a new Customer:: Customer object
	* 
	* @param user string - customer username
	* @param first string - customer first name
	* @param last string - customer last name
	* @param pass string - customer password 
	* @param emailAddr string - customer emal 
	* @param phoneNumber long int - customer phone number
	*/
	Customer(string user, string first, string last,string pass, string emailAddr, long int phoneNumber);
	
	/**
	* @brief Setter for customer username
	* 
	* @param uName string - customer username
	*/
	string getUserName();
	
	/**
	* @brief setter for customer password
	* 
	* @param pass string - customer password
	*/
	string getPassword();
	
	/**
	* @brief setter for customer first name
	* 
	* @param fName string - customer first name
	*/
	string getFirstName();
	
	/**
	* @brief setter for customer last name
	* 
	* @param lName string - customer last name
	*/
	string getLastName();
	
	/**
	* @brief setter for customer email
	* 
	* @param emailAddr string - customer email
	*/
	string getEmail();
	
	/**
	* @brief setter for customer phone number 
	* 
	* @param phoneNumber long int - the customer's phone number
	*/
	long int getPhoneNum();
	
	/**
	* @brief setter for customer's unique ID 
	* 
	* @param id int - the customer's unique ID 
	*/
	int getUniqueID();
	
	/**
	* @brief getter for the customer's username
	* 
	* @return string - the customer username
	*/
	void setUserName(string uName);
	
	/**
	* @brief getter for the customer's password
	* 
	* @return string - the customer's password
	*/
	void setPassword(string pass);
	
	/**
	* @brief getter for the customer's first name
	* 
	* @return string - the customer's first name
	*/
	void setFirstName(string fName);
	
	/**
	* @brief getter for the customer's last name
	* 
	* @return string - the customer's last name
	*/
	void setLastName(string lName);
	
	/**
	* @brief getter for the customer's email
	* 
	* @return string - the customer email
	*/
	void setEmail(string emailAdr);
	
	/**
	* @brief getter for the customer's phone number
	* 
	* @return long int - the customer phone number
	*/
	void setPhoneNum(long int phoneNumber);
	
	/**
	* @brief getter for the customer's unique ID 
	* 
	* @return int - the customer's unique ID 
	*/
	void setUniqueID(int id);
};
#endif
