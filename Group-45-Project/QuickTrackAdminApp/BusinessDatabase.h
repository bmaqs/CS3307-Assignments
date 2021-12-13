#ifndef BUSINESSDATABASE_H
#define BUSINESSDATABASE_H
#include "Database.h"
#include "Business.h"
#include "Admin.h"
using namespace std;

/**
 * @brief The functions allow businesses to be registered and queried on the database
 * @author Abdulrahim Hamed (ahamed4)
 * @author Braikhna Yousafzai (byousafz)
 * @author Colin Stoddart (cstodda6)
 * @author Evangelos Makris (emakris2) 
 * @author Jem Parlakyigit (mparlaky)
 */
class BusinessDatabase:public Database{
	public:
	/**
	* @brief Construct a new Business Database:: Business Database object
	* 
	* Creates the database object
	* 
	* @param serverName string - database server name
	* @param userName string - database user's username
	* @param password string - database user's password
	*/
	BusinessDatabase(string serverName, string userName, string password);
	
	/**
	* @brief selects a business from the database based on business ID
	* 
	* @param businessID int - the unique business ID for the business
	* @return Business - returns a business object related to the unique business ID
	*/
	Business selectBusiness(int businessID);
	
	/**
	* @brief searches the business database based on the name of the business 
	* 
	* @param name string - the name of the business
	* @return int - returns the number of results matching the business name
	*/
	int searchBusiness(string name);
	
	/**
	* @brief gets a list of Business objects from a list of unique business IDs
	* 
	* @param businessIDList vector<int> - a list of unique business IDs
	* @return vector<Business> - a list of Business objects 
	*/
	vector<Business> selectBusinesses(vector<int> businessIDList);
	
	/**
	* @brief Adds a new business to the database
	* 
	* @param business Business - a new business to be added to the database
	* @return true Bool - business was added
	* @return false Bool - business was not added 
	*/
	bool addBusiness(Business business);
	
	/**
	* @brief updates the unique business ID for a Business object based on the assigned ID in the database
	* 
	* @param business Business - a business object 
	* @return Business - a business object with an updated business ID 
	*/
	Business updateBusinessID(Business business);
	
	/**
	* @brief This method determines if an admin usernamne exists for a given business ID
	* 
	* @param name string - the admin username
	* @param businessID int - the business ID
	* @return int - The number of times the username occurs for the given business ID in the database
	*/		
	int searchAdmin (string name, int businessID);

	/**
	* @brief This method adds an admin to the database
	* 
	* @param admin Admin - an admin to be added to the database
	* @return true Bool - the admin was successfully added
	* @return false Bool - the admin was not added
	*/
	bool addAdmin(Admin admin);

	/**
	* @brief This method checks an admin's log in information against the credentials stored in the database for that admin
	* 
	* @param admin Admin - an admin object with stored log in information
	* @return true Bool - Success. The log in information matches whats in the database 
	* @return false Bool - Failure. The log in information does not match whats in the database 
	*/
	bool checkAdminLogin(Admin admin);
	
	/**
	* @brief Retrieves all the businesses stored in the database 
	* 
	* @return vector<Business> - a list of Business objects containing all the businesses in the database 
	*/
	vector<Business> getAll();
	
	/**
	* @brief This method gets a list of the customer IDs for customers that have been in a business in the last 14 days
	* 
	* @param business Business - the business that is being queried
	* @return vector<int> - A list of customer IDs for customers that have been in the business in the last 14 days
	*/
	vector<int> getTwoWeekCustomers (Business business);
	
	/**
	* @brief This method returns a list of customer IDs for the customers currently in store for a given business
	* 
	* @param business Business - the business being queried
	* @return vector<int> - a list of customer IDs for customers currently in store 
	*/
	vector<int> getCustomersInStore (Business business);
	
	/** @brief this method updates the admin ID for an admin
	* 
	* @param admin Admin - the admin without an updated admin ID 
	* @return Admin - the admin with an updated admin ID 
	*/
	Admin updateAdminID(Admin admin);
};
#endif

