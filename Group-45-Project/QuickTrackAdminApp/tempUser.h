#ifndef TEMPUSER_H
#define TEMPUSER_H
#include <stdlib.h>
#include <iostream>

using namespace std;
/**
* @brief This class acts as a temporary between the offline and online database
* 
* @author Abdulrahim Hamed (ahamed4)
*/
class tempUser{
	public:
	string timeIn;
	string timeOut;
	string userID;
	string firstName;
	string lastName;
	string email;
	string phoneNumber;
    string businessID;

	/**
	* @brief Empty Database Constructor
	* 
	* @returns A temp user
	*/
	tempUser();
	
};
#endif
