#ifndef BUSINESS
#define BUSINESS
#include "SignInOut.h"
#include<stdlib.h>
#include<string>

using namespace std;

/**
 * @brief This class includes functions related to creating Business objects
 * @author Abdulrahim Hamed (ahamed4)
 * @author Braikhna Yousafzai (byousafz)
 * @author Colin Stoddart (cstodda6)
 * @author Evangelos Makris (emakris2)
 * @author Jem Parlakyigit (mparlaky)
 */
class Business{
	private:
	string name, description, streetAddress, postalCode, city, province, email;
	int businessID, phoneNumber;
	vector<SignInOut> customers;
	
	public:
	/**
 	* @brief Empty Constructor for a new Business:: Business object
 	*/
	Business();
	
	/**
 	* @brief Construct a new Business:: Business object
 	* 
 	* @param name string - name of the business 
 	* @param email string - email for the business
 	*/
	Business(string name, string email);
		
	/**
	 * @brief setter for the busines name
	 * 
	 * @param name string - name of the business
	 */
	void setName(string name);
	
	/**
	* @brief setter for the unique ID of the business
	* 
	* @param businessID int - the unique business ID
	*/
	void setBusinessID(int businessID);
		
	/**
	* @brief setter for the business email
	* 
	* @param email string - the business email
	*/	
	void setEmail(string email);
		
	/**
	* @brief setter for the description of the business
	* 
	* @param description string - the description of the business
	*/
	void setDescription(string description);

	/**
	* @brief setter for the street address
	* 
	* @param address string - the street address of the business
	*/
	void setStreetAddress(string address);
		
	/**
	* @brief setter for the postal code of the business
	* 
	* @param postalCode string - the postal code of the business
	*/
	void setPostalCode(string postalCode);
		
	/**
	* @brief setter for the city the business is in 
	* 
	* @param city string - the city where the business is located
	*/
	void setCity(string city);
		
	/**
	* @brief setter for the province of the business
	* 
	* @param prov string - the province code the business is located in 
	*/
	void setProvince(string prov);
		
	/**
	* @brief setter for the business phone number
	* 
	* @param phone long int - the business phone number
	*/
	void setPhoneNumber(long int phone);
		
	/**
	* @brief getter for the business name
	* 
	* @return string - the name of the business
	*/
	string getName();
		
	/**
	* @brief getter for the unique business ID
	* 
	* @return int - the unique businessID
	*/
	int getBusinessID();
		
	/**
	* @brief getter for the business email
	* 
	* @return string - the business email
	*/
	string getEmail();
		
	/**
	* @brief getter for the business description
	* 
	* @return string - the description of the business
	*/
	string getDescription();
		
	/**
	* @brief getter for the business street address
	* 
	* @return string - the business street address
	*/
	string getStreetAddress();
		
	/**
	* @brief getter for the business postal code
	* 
	* @return string - the business' postal code
	*/
	string getPostalCode();

	/**
	* @brief getter for the city the business is located in 
	* 
	* @return string - the city where the business is located
	*/
	string getCity();

	/**
	* @brief getter for the province where the business is located
	* 
	* @return string - province code where business is located
	*/
	string getProvince();
		
	/**
	* @brief getter for the business phone number
	* 
	* @return long int - the business phone number
	*/
	long int getPhoneNumber();	
		
	/**
	* @brief a string representation of the Business object and its stored information
	* 
	* @param business Business - business object 
	*/
	void toString(Business business);
	
	/**
	* @brief creates an empty list of Customer objects
	* 
	* @return vector<Customer> - empty list of Customer objects
	*/
	vector<Customer> createCustomerList();
	
	/**
	 * @brief adds a Customer object to the list of Customer objects
	 * 
	 * @param customerList vector<Customer> - list of Customer objects
	 * @param newCustomer Customer - a new Customer object to be added to the list
	 * @return vector<Customer> - list of Customer objects with the new customer added
	 */
	vector<Customer> addCustomer(vector<Customer> customerList, Customer newCustomer);	
	};
	#endif
