#ifndef ADMIN
#define ADMIN
#include<stdlib.h>
#include<string>
#include <vector>

using namespace std;

/**
 * @brief This class has functions related to building Admin obejcts
 * 
 * @author Abdulrahim Hamed (ahamed4)
 * @author Braikhna Yousafzai (byousafz)
 * @author Colin Stoddart (cstodda6)
 * @author Evangelos Makris (emakris2)
 * @author Jem Parlakyigit (mparlaky)
 *
 */
class Admin{
	private:
	int adminID;
	int businessID;
	string adminUserName;
	string adminPass;
	bool admin;

	public:
	/**
 	* @brief Null constructor for the Admin object
 	*/
	Admin();
	
	/**
	* @brief Construct a new Admin:: Admin object
	* 
	* @param businessID type int representing the unique businessID
 	* @param username type string representing administrator's username
 	* @param pass type string representing administrator's password
	*/
	Admin (int businessID, string username, string pass);
	
	/**
	* @brief setter for Admin ID 
	* 
	* @param id type int represents unique Admin ID
	*/
	void setAdminID(int id);
	
	/**
	* @brief setter for Business ID
	* 
	* @param id type int represents the admin's Business ID
	*/
	void setBusinessID(int id);
	
	/**
	* @brief setter for the admin's username
	* 
	* @param user type string represents the admins username
	*/
	void setAdminUserName(string user);
	
	/**
	* @brief setter for the admin's password
	* 
	* @param pass type string represents the admin's password
	*/
	void setAdminPass(string pass);
	
	/**
	* @brief getter for the admin's unique ID 
	* 
	* @return int - returns the admin's unique ID 
	*/
	int getAdminID();
	
	/**
	* @brief getter for the admin's business ID
	* 
	* @return int - returns the admin's business ID
	*/
	int getBusinessID();
	
	/**
	* @brief getter for the admin's username
	* 
	* @return string - returns the admin's username
	*/
	string getAdminUserName();
	
	/**
	* @brief getter for the admin's password
	* 
	* @return string - returns the admn's password
	*/
	string getAdminPass();
	
};
#endif
