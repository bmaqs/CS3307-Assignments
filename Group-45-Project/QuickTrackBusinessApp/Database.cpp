#include <stdlib.h>
#include <iostream>
#include <driver.h>
#include <exception.h>
#include <resultset.h>
#include <statement.h>
#include <prepared_statement.h>
#include "Database.h"

using namespace sql;
using namespace std;

Database::Database(){

    try {
      connectLocally = false;
        driver = get_driver_instance();
        con = driver->connect("sql9.freemysqlhosting.net", "sql9372596", "fNf8Kr8wZD");
        con->setSchema("sql9372596");
    } catch(sql::SQLException &e){
        //cout << "# ERR: " << e.what()<<endl;
        //cout << "MySQL error code: " << e.getErrorCode()<<endl;
        //cout << ", SQLState: " << e.getSQLState()<<endl;
        cout <<"cannot connect to remote server"<<endl;
        connectLocally = true;
    }

    if(connectLocally){
    try {
        driver = get_driver_instance();
        con = driver->connect("tcp://localhost:3306", "root", "");
        con->setSchema("quicktracker");
        cout << "connected locally"<<endl;
    } catch(sql::SQLException &e){
        //cout << "# ERR: " << e.what()<<endl;
        //cout << "MySQL error code: " << e.getErrorCode()<<endl;
        //cout << ", SQLState: " << e.getSQLState()<<endl;
        //connectLocally = true;
        cout << "Cannot connect to local server"<<endl;
    }

    }
}

Database::Database(string serverName, string userName, string password){

    try {
      connectLocally = false;
        driver = get_driver_instance();
        con = driver->connect(serverName, userName, password);
        con->setSchema("sql9372596");
    } catch(sql::SQLException &e){
        //cout << "# ERR: " << e.what()<<endl;
        //cout << "MySQL error code: " << e.getErrorCode()<<endl;
        //cout << ", SQLState: " << e.getSQLState()<<endl;
        cout <<"cannot connect to remote server"<<endl;
        connectLocally = true;
    }
    if(connectLocally){
    try {
        driver = get_driver_instance();
        con = driver->connect("tcp://localhost:3306", "root", "");
        con->setSchema("quicktracker");
        cout << "connected locally"<<endl;
    } catch(sql::SQLException &e){
        //cout << "# ERR: " << e.what()<<endl;
        //cout << "MySQL error code: " << e.getErrorCode()<<endl;
        //cout << ", SQLState: " << e.getSQLState()<<endl;
        //connectLocally = true;
        cout << "Cannot connect to local server"<<endl;
    }

    }
}
//the followng constructor is to connect to a database manually
//if sync is on, it will ignore looking for local server
//if sync is of, it will try to connect to a local database if remote is unavailable
Database::Database(int cond, string serverName, string userName, string password, string databaseName){
    if (cond == 1){
    try {
      connectLocally = false;
        driver = get_driver_instance();
        con = driver->connect(serverName, userName, password);
        con->setSchema(databaseName);
    } catch(sql::SQLException &e){
        cout <<"cannot connect to server"<<endl;
    }
    }else{
            try {
              connectLocally = false;
        driver = get_driver_instance();
        con = driver->connect(serverName, userName, password);
        con->setSchema("sql9372596");
    } catch(sql::SQLException &e){
        cout <<"cannot connect to remote server"<<endl;
        //connectLocally = true;
    }
      /*
    if(connectLocally){
    try {
        driver = get_driver_instance();
        con = driver->connect("tcp://localhost:3306", "root", "");
        con->setSchema("quicktracker");
        cout << "connected locally"<<endl;
    } catch(sql::SQLException &e){
        cout << "Cannot connect to local server"<<endl;
    }

    }*/

    }
}
