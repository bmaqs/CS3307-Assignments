#include <stdlib.h>
#include <iostream>
#include <driver.h>
#include <exception.h>
#include <resultset.h>
#include <statement.h>
#include <prepared_statement.h>

using namespace sql;
using namespace std;

class Database : Database{
	private:
	Driver *driver;
	Connection *con;
	Statement *stmt;
	ResultSet *res;
	PreparedStatement *pstmt;
	public:
	Database(string serverName, string userName, string password){
		try {
			driver = get_driver_instance();
			con = driver->connect(serverName, userName, password);
			con->setSchema("sql9372596"); 

		}catch(sql::SQLException &e){
       cout << "# ERR: " << e.what()<<endl;
       cout << "MySQL error code: " << e.getErrorCode()<<endl;
       cout << ", SQLState: " << e.getSQLState()<<endl;
	}
}
	~Database(){
		delete stmt;
		delete con;
		}


void selectCustomers(){
	this->stmt= con->createStatement();
    this->res = stmt->executeQuery("SELECT * FROM tbl_customers");
        while(this->res->next()){
	cout << "id = " <<res->getInt("customer_id") <<res->getString("customer_id") <<endl;
	}
}

void selectBusiness(){
	this->stmt= con->createStatement();
    this->res = stmt->executeQuery("SELECT * FROM tbl_businesses");
    while(this->res->next()){
		cout << "id = " << res->getInt("business_id") << res->getString("business_name") <<endl;
	}
	}

void insertCustomer(){
	//this->stmt= con->createStatement();
    this->pstmt = con->prepareStatement("INSERT INTO tbl_customers(customer_username, customer_firstName) VALUES ('Test', 'Testings')");
	this->pstmt->executeUpdate();
	             
	}

};

/*int main(){
	Database* test = new Database("sql9.freemysqlhosting.net", "sql9372596", "fNf8Kr8wZD");
	test->selectBusiness();
	test->insertCustomer();
	return 0;
	}
*/

