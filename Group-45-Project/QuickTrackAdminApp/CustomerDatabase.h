#ifndef CUSTOMERDATABASE_H
#define CUSTOMERDATABASE_H
#include "Database.h"
#include "Customer.h"

using namespace std;

/**
 * @brief This is the class that constructs and operates directly with the customer database
 * 
 * @author Abdulrahim Hamed (ahamed4)
 * @author Braikhna Yousafzai (byousafz)
 * @author Colin Stoddart (cstodda6)
 * @author Evangelos Makris (emakris2)
 * @author Jem Parlakyigit (mparlaky)
 */
class CustomerDatabase:public Database{
	public:
		/**
		 * @brief Constructor for the Customer Database
		 * 
		 * @param serverName A string version of the server address(name)
		 * @param userName A string version of the server username
		 * @param password A string version of the server password
		 * @returns A Customer Database Object
		 */
		CustomerDatabase(string serverName, string userName, string password);
		
		/**
		 * @brief Selects a single customers based on email
		 * 
		 * @param userEmail A string version of the customers email
		 * @returns A customer object
		 */
		Customer selectCustomer (string userEmail);

		/**
		 * @brief Selects a single customers based on ID
		 * 
		 * @param uniqueID An Int version of the customers ID
		 * @returns A customer object
		 */
		Customer selectCustomer (int uniqueID);

		/**
		 * @brief Searches for the number of customers with that username
		 * 
		 * @param username A string version of the username
		 * @returns The Int corresponding to the number of customers with that ID
		 */
		int searchCustomer (string username);
		
		/**
		 * @brief Searches for the number of customers with that ID
		 * 
		 * @param ID An Int version of the ID
		 * @returns The Int corresponding to the number of customers with that ID, which should be 1
		 */
		int searchCustomer (int id);

		/**
		 * @brief Selects a list of customers based on emails
		 * 
		 * @param userEmail A string list of User Emails
		 * @param arrSize The Int size of the list
		 * @returns A vector<Customer> list of customer objects
		 */
		vector<Customer> selectCustomers(string userEmail[], int arrSize);
		
		/**
		 * @brief Selects a list of customers based on ID
		 * 
		 * @param listUniqueID A vector<int> list of customer IDs
		 * @returns A vector<Customer> list of customer objects
		 */
		vector<Customer> selectCustomers(vector<int> listUniqueID);
		
		/**
		 * @brief Adds a customer object
		 * 
		 * @param user A customer object to add
		 */
		void addCustomer(Customer user);
		
		/**
		 * @brief Updates a customers unique ID
		 * 
		 * @param user A customer object to update their ID
		 */
		Customer updateUniqueID (Customer user);
		
		/**
		 * @brief Gets a List of all customer objects
		 * 
		 * @returns vector<Customer> List of all the customers
		 */
		vector<Customer> getAll();
};
#endif

