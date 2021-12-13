#ifndef SYNC
#define SYNC
#include<stdlib.h>
#include<string>
#include "Database.h"
#include <vector>
#include "tempUser.h"

using namespace std;
/**
* @brief This class is to sync between the offline and remote databases
* 
* @author Abdulrahim Hamed (ahamed4)
*/
class Sync{
	public:
	Database local;
	Database remote;
	vector<int> localUserID;
  		
  	/**
	* @brief Empty Constructor that creates a connection between the local and remote server
	*/
	Sync();
  	
	/**
	* @brief It create a list of entries from local database server
	* @returns list of entries from local database
	*/
	vector<tempUser> localSignInOut();
  	
	/**
	* @brief Exports data from local server and moves it to remote server. It also removes synced data from local server by using deleteLocalSignInOut(int id) method
	* @param TempUser A vector<tempuser> version of a list of temp user objects
	*/
	void exportSignInOut(vector<tempUser>);
  	
	/**
	* @brief Removes synced entries from local database
	*/
	void deleteLocalSignInOut(int id);
		
};
#endif
