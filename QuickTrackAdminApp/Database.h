#ifndef DATABASE
#define DATABASE
#include <stdlib.h>
#include <iostream>
#include <driver.h>
#include <exception.h>
#include <resultset.h>
#include <statement.h>
#include <prepared_statement.h>

using namespace sql;
using namespace std;

/**
* @brief This class represents the database and connects to it
* 
* @author Abdulrahim Hamed (ahamed4)
* @author Braikhna Yousafzai (byousafz)
* @author Colin Stoddart (cstodda6)
* @author Evangelos Makris (emakris2)
* @author Jem Parlakyigit (mparlaky)
*/
class Database{
	public:
		Driver *driver;
		Connection *con;
		Statement *stmt;
		ResultSet *res;
		PreparedStatement *pstmt;
		bool connectLocally;
	public:
		
		/**
		* @brief Empty Database Constructor
		* 
		* @returns A database object
		* @see Database::Database(string serverName, string userName, string password);
		*/
		Database();
		
		/**
		* @brief Database Constructor
		* 
		* @param serverName A string version of the server address(name)
		* @param userName A string version of the server username
		* @param password A string version of the server password 
		* @returns A database object
		* @see Database::Database(string serverName, string userName, string password);
		*/
		Database(string serverName, string userName, string password);
		
		/**
		* @brief Database Constructor
		* 
		* @param cond A Int representing a certian condition related to the database connection
		* @param serverName A string version of the server address(name)
		* @param userName A string version of the server username
		* @param password A string version of the server password
		* @param databaseName A string version of the database you want to connect to
		* @returns A database object
		* @see Database::Database(string serverName, string userName, string password);
		*/
		Database(int cond, string serverName, string userName, string password, string databaseName);
		
		/**
		* @brief Checks for local connection
		* 
		* @returns A bool representing the status of the local connection
		* @see Database::Database(string serverName, string userName, string password);
		*/
		bool getConnectLocally();

};
#endif
