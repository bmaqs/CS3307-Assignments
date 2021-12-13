#include "Customer.h"
#include "SignInOut.h"
#include "Business.h"
#include "CustomerDatabase.h"
#include "BusinessDatabase.h"
#include "Database.h"
#include "NotifyCustomers.h"
#include "Admin.h"
#include <stdio.h>
#include <iostream>

using namespace std;

/**
* @brief The first menu which is the log in screen
* 
* @returns An Int corresponding to the users selection
*/
int logInMenu() {
	string input = "z";

	cout << "Log in as: "<< endl;
	cout << "1. Business" << endl;
	cout << "2. Customer" << endl;
	cout << "3. Admin" << endl;
	cout << "-----------------" << endl;
	cout << endl;
	cout << "Press 'q' at any time to quit." << endl;
	cin.clear();
	getline(cin, input);
	
	while (input != "1" && input != "2" && input != "3" && input != "q") {

		cout << "Invalid input. Try again: ";
		cin.clear();
		getline(cin, input);
	}
	if (input == "q"){return -2;} //quit the program 
	
	return stoi(input);
}

/**
* @brief The menu that allows for customers to register
* 
* @param db A CustomerDatabase object representing the customer database
* @returns An Int corresponding to the customers ID
*/
int customerMenu(CustomerDatabase db){
	string input = "z";
	while (input != "0") {
		cout << "Please make a selection" << endl;
		cout << "0. Return to main menu" << endl;
		cout << "1. Register as a new customer" << endl;
		cout << endl;
		cin.clear();
		getline(cin, input);
	
		while (input != "1" && input != "0" && input !="q"){
			cout << "Invalid input. Try again: ";
			cin.clear();
			getline(cin, input);
		}
		if (input == "q"){return -2;}
	
		if (input == "1"){
			Customer customer;
			string fname;
			string lname;
			string email;
			string password;
			string phone;
			int id;

			cout << "Customer registration." << endl;
			cout << "Enter First Name" << endl;
			cin.clear();
			getline(cin, fname);
			customer.setFirstName(fname);
			cout << "Enter Last Name" << endl;
			cin.clear();
			getline(cin, lname);
			customer.setLastName(lname);
			cout << "Enter email" << endl;
			cin.clear();
			getline(cin, email);
			customer.setEmail(email);
			cout << "Enter password" << endl;
			cin.clear();
			getline(cin, password);
			customer.setPassword(password);
			cout << "Enter phone number" << endl;
			cin.clear();
			getline(cin, phone);
			customer.setPhoneNum(stol(phone));
			db.addCustomer(customer);
			customer = db.updateUniqueID(customer);
		
			id = customer.getUniqueID();
		
			if (id != 0) {
				cout << "You are successfully registered" << endl;
				cout << "**Please note your unique ID is: " << id << "***" << endl;
				cout << endl;
				cout << endl;
			} else {

				cout << "Registration failed" << endl;
			}
		
		}
	}
	return (stoi(input));
}

/**
* @brief The sign in menu
* 
* @param flag An int representing weather the user has an account or not
* @param F A string representing the users first name
* @param L A string representing the users last name
* @param P A string representing the users phone number
* @param E A string representing the users Email
* @param A An Int representing the customers ID
* @param db A CustomerDatabase object representing the customer database
* @param businessID An Int representing the Business
* @returns An Int corresponding to the users selection
*/
void signIn(int flag, string F, string L, string P, string E, int A, CustomerDatabase db, int businessID){
	SignInOut sio;
	Customer user;
	// Sign in
	if(flag == 1) {
		user = db.selectCustomer(A);
		sio.SignIn(A, user.getFirstName(), user.getLastName(), user.getPhoneNum(), user.getEmail(), businessID, db);
	}
	else{
		user.setFirstName(F);
		user.setLastName(L);
		user.setPhoneNum(stol(P));
		user.setEmail(E);
		db.addCustomer(user);
		user = db.updateUniqueID(user);
		sio.SignIn(user.getUniqueID(), F, L, stol(P), E, businessID, db);
	}
	return;
}

/**
* @brief The sign out menu
* 
* @param flag An int representing weather the user has an account or not
* @param F A string representing the users first name
* @param L A string representing the users last name
* @param P A string representing the users phone number
* @param E A string representing the users Email
* @param A An Int representing the customers ID
* @param db A CustomerDatabase object representing the customer database
* @param businessID An Int representing the Business
* @returns An Int corresponding to the users selection
*/
void signOut(int flag, string F, string L, string P, string E, int A, CustomerDatabase db, int businessID){
        SignInOut sio;
        Customer user;
	// Sign in
	if(flag == 1) { sio.SignOut(A, businessID, db); }
	else {
                user = db.selectCustomer(E);
                sio.SignOut(user.getUniqueID(), businessID, db); 
        }
	return;
}

/**
* @brief The menu for emailing exposed customers
* 
* @param y An int representing the year
* @param m An int representing the month
* @param d An int representing the day
*/
void emailExposure(int y, int m, int d){
	string subject = "COVID-19 Possible Exposure";
	string msg = "Greetings: You Have Potentially been exposed to COVID-19. Please follow local health regulations regarding testing, quarantining, and recovery. Thank You.";
	string date = to_string(y) + "-" + to_string(m) + "-" + to_string(d);
	string indate = date + " 00:00:00";
	string outdate = date + " 23:59:59";
	string change;
	SignInOut sio;
	vector<string> emailDB;

	// Subject Line
	cin.ignore();
	cout << "\nDefault Subject Line: \"" << subject << "\"\n\nWould you like to change the subject (y/n)? ";
	cin.clear();
	getline(cin, change);
	if(change == "y"){
		cout << "\n\nEnter New Subject Line: ";
		cin.clear();
		getline(cin, subject);
	}

	// Message
	cout << "\nDefault Message: \"" << msg << "\"\n\nWould you like to change the message (y/n)? ";
	cin.clear();
	getline(cin, change);
	if(change == "y"){
		cout << "\nEnter New Message: ";
		cin.clear();
		getline(cin, msg);
	}

	// Confirm
	cout << "\nHere is the Details about your Email Message: \nSubject: \"" << subject << "\"\nMessage: \"" << msg << "\"\nDate: " << date << "\n\nPlease Confirm This Email (y/n): ";
	cin.clear();
	getline(cin, change);
	if(change=="n") { cout << "Email Not Sent.\n\n"; return; }
	else{
		cout << "Please Wait..." << endl;
		msg = msg + "\n\nPotential exposure occured on the date: " + date + ".";
		emailDB = sio.findEmails(indate, outdate, 1);
    	NotifyCustomers::sendEmail(emailDB, subject, msg);
		cout << "Email Sent!\n" << endl;
	}
	return;
}

/**
* @brief The menu that allows admins to select a buisness
* 
* @param buisnessDB A BusinessDatabase object representing the buisness database
* @param customerDB A customerDatabase object representing the customer database
* @returns An Int corresponding to the users selection
*/
int businessMenu(BusinessDatabase businessDB, CustomerDatabase customerDB){

	string input = "z";
	string select = "z";
	string id;
	int busId=0;
	Business business;


	while (busId == 0){
		cout << "Please enter your Business ID" << endl;
		cout << endl;
		cout << "**Press 0 to return to previous menu**" << endl;
		cin.clear();
		getline(cin, id);
		if (id == "0"){
			return 0;
		} else if (id == "q") {
			return -2;
		}
		busId = stoi(id);
		business = businessDB.selectBusiness(busId);

		if (business.getBusinessID() == 0) {
			cout << "Business not found" << endl;
			cout << endl;
		} else {
			cout << "-------------------------------"<< endl;
			cout << "Welcome " << business.getName() << endl;
			cout << "--------------------------------"<< endl;
			busId = business.getBusinessID();
		}
	}
	while (busId != 0){
		cout << "Please make a selection: " << endl;
		cout << endl;

		cout << "1. Sign In a Customer " << endl;
		cout << "2. Sign Out a Customer " << endl;
		cout << "3. Notify Customers of Exposure Incidence" << endl;
		cout << "4. Get Customers In Store" << endl;
		cout << "0. Main menu" << endl;
		cout << endl;
			
		cin.clear();
		getline(cin, select);
		while (select != "1" && select != "2" && select != "3" && select != "4" && select != "0" && select != "q") {
			cout << "Invalid input. Please make a selection. " << endl;
			cin.clear();
			getline(cin, select);

		}
		if (select == "1") {
			//sign in
			string flag;
			int AccNum;
			string Fname, Lname, email, phone;
			cout << "Customer Sign In" << endl;
			cout << "-----------------" << endl;
			cout << "Does the customer have an account (y/n)?" << endl;
			cout << endl;
			cout << "Enter 0 for the previous menu" << endl;
			cout << endl;
			cin.clear();
			getline(cin, flag);
			while (flag != "y" && flag != "n" && flag != "q" && flag != "0"){
				cout << "Invalid input. Try again with either 'y' or 'n' : " << endl;
				cin.clear();
				getline(cin, flag);

			}
			if (flag == "y") {
				//sign in  with account
				cout << "Enter account number: ";
				cin >> AccNum;

				signIn(1, "null", "null", "null", "null", AccNum, customerDB, busId);
				cin.clear();
				cin.ignore();
			} else if (flag == "n") {
				//sign in without account
				cout << "\nSign-In Entry\n-------------\nEnter First Name: ";
				cin.clear();
				getline(cin, Fname);
				cout << "Enter Last Name: ";
				cin.clear();
				getline(cin, Lname);
				cout << "Enter Email: ";
				cin.clear();
				getline(cin, email);
				cout << "Enter Phone Number: ";
				cin.clear();
				getline(cin, phone);
				signIn(2, Fname, Lname, phone, email, 0, customerDB, busId);
			} else if (flag == "q") {
				return -2;
			}

		} else if (select == "2"){
			//sign out
			string flag;
			cout << "Does customer have account number(y/n)? " << endl;
			cout << endl;
			cout << "Press 0 to return to previous menu" << endl;
			cout << endl;
			cin.clear();
			getline(cin, flag);
			while (flag != "y" && flag != "n" && flag != "q") {
				cout << "Invalid input. Try again with either 'y' or 'n': ";
				cin.clear();
				getline(cin, flag);
			}
			if (flag == "y") {
				//sign out with account 
				int AccNum;
				cout << "Enter account number: ";
				cin >> AccNum;
				signOut(1, "null", "null", "null", "null", AccNum, customerDB, busId);
				cin.clear();
				cin.ignore();
			} else if (flag == "n") {
				//sign out w/o account
				string Fname, Lname, phone, email;
				cout << "\nSign-Out Entry\n--------------\nEnter First Name: ";
				cin.clear();
				getline(cin, Fname);
				cout << "Enter Last Name: ";
				cin.clear();
				getline(cin, Lname);
				cout << "Enter Email: ";
				cin.clear();
				getline(cin, email);
				cout << "Enter Phone Number: ";
				cin.clear();
				getline(cin, phone);
				signOut(2, Fname, Lname, phone, email, 0, customerDB, busId);
				
			} else if (flag == "q") {
				//quit the program
				return -2;
			}
		} else if (select == "3") {
			//notify customers
			int year, day, month, flag=1;
			cout << "\nNotify Customers About Exposure\n-------------------------------\nTo Quit This Menu, Enter 2000 01 01\n\nEnter A Date of Exposuer (YYYY MM DD): ";
			cin.clear();
			cin >> year >> month >> day;
			while(flag==1){
				if(year==2000 && day==01 && month==01){ flag = -1;}
				else if(2000 <= year && year <= 3000)
				{
					// Days 0-31
					if((month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12) && (day>0 && day<=31)){ flag = 0;}
					// Days 0-30
					else if((month==4 || month==6 || month==9 || month==11) && (day>0 && day<=30))
						{ flag = 0; }
					// Febuary
					else if(month==2)
					{ 
						if((year%400==0 || (year%100!=0 && year%4==0)) && (day>0 && day<=29)) { flag = 0; }
						else if(day>0 && day<=28) { flag = 0; }
						else { flag = 1;}
					}
					else{ flag = 1; }
				}
				else {flag = 1; }

				if(flag == 1){
					cout << "\n\nInvalid Date. Please Check Date and Format of Date.\nEnter A Date of Exposuer (YYYY MM DD): ";
					cin.clear();
					cin >> year >> month >> day;
				}
				else if(flag == 0){ emailExposure(year, month, day); }
				else {
					break;
				}
			}
		} else if (select == "4"){
			vector<int> customerIDs;
			int numCustomers = 0;
			customerIDs = businessDB.getCustomersInStore(business);
			numCustomers = customerIDs.size();

			cout << "There are currently " << numCustomers << " customers in your business" << endl;
			cout << endl;
		} else if (select == "q") {
			return -2;
		} else {
			return 0;
		}

	} //end while

	return 0;
}

/**
* @brief The admin menu to add new businesses
* 
* @param db A BusinessDatabase object representing the buisness database
* @returns An Int corresponding to the users selection
*/
int adminMenu(BusinessDatabase db){
	Admin admin;
	int busID = 0;
	string username;
	string password;
	int exists =0;
	bool isAdmin;
	int flag = 0;

	cout << "Please enter your username" << endl;
	cin.clear();
	getline(cin, username);
	
	if (username == "q"){
		return -2;
	}
	else {

		exists = db.searchAdmin(username, busID);
		while (exists == 0){
			cout<< "Username is invalid. Please re-enter your username" << endl;
			cout << "Press 0 to return to the main menu" << endl;

			cin.clear();
			getline(cin, username);
			if (username == "q"){
				return -2;
			}
			else if (username == "0"){
				return 0;
			}

		}

		cout << "Please enter your password" << endl;
		cin.clear();
		getline(cin, password);

		admin.setAdminUserName(username);
		admin.setBusinessID(busID);
		admin.setAdminPass(password);

		
		while (isAdmin == false){
			isAdmin = db.checkAdminLogin(admin);

			if (isAdmin == false) {
				cout << "Incorrect password. Please re-enter password or press 0 to return " << endl;
				cin.clear();
				getline(cin, password);
				if (password == "0"){
					break;
				} else {
					admin.setAdminPass(password);
					isAdmin = db.checkAdminLogin(admin);
				}
			} else {
				flag = 1;
				cout << "Welcome to QuickTrack admin" << endl;
				cout << "---------------------------" << endl;

			}
		}

		while (flag == 1){
			string select; 

			cout << "Please make a selection" << endl;
			cout << endl; 
			cout << "0. Quit to main menu" << endl;
			cout << "1. Add a business" << endl;

			cin.clear();
			cin.ignore();
			getline(cin, select);
			while (select != "1" && select != "0" && select != "q"){
				cout << "Invalid input. Please make a valid selection." << endl;
				cin.clear();
				getline(cin,select);

			}
			
			if (select == "0"){
				return 0;
			} else if (select == "q"){
				return -2;
			} else if (select == "1"){
				//add a business
				string name, email, description, street, postal, city, prov;
				long int phone;
				Business business;
				bool add;

				cout << "Add a new business" << endl;
				cout << "Please enter the name of the business" <<endl;
				cin.clear();
				getline(cin, name);
				business.setName(name);
				cout << "Please enter the business email" << endl;
				cin.clear();
				getline(cin, email);
				business.setEmail(email);
				cout << "Please enter the business description" << endl;
				cin.clear();
				getline(cin, description);
				business.setDescription(description);
				cout << "Please enter the stress address" << endl;
				cin.clear();
				getline(cin, street);
				business.setStreetAddress(street);
				cout << "Please enter the postal code" << endl;
				cin.clear();
				getline(cin, postal);
				business.setPostalCode(postal);
				cout << "Please enter the city" << endl;
				cin.clear();
				getline(cin, city);
				business.setCity(city);
				cout <<"Please enter the prov code" << endl;
				cin.clear();
				getline(cin, prov);
				business.setProvince(prov);
				cout<< "Please enter the phone number" << endl;
				cin.clear();
				cin >> phone;
				business.setPhoneNumber(phone);

				add = db.addBusiness(business);
				if (add == true){
					business = db.updateBusinessID(business);
					cout << endl;
					cout << endl;
					cout << "----------------------------------" << endl;
					cout << "Business successfully added." << endl;
					cout << "Business ID is " << business.getBusinessID() << endl;
					cout << endl;
				} else {
					cout << "Could not add business. Please try again." << endl;
				}
			}


		}
	}

	return 0;


}

/**
* @brief This is the main of the code and allows users to select from and display menus
* 
* @author Abdulrahim Hamed (ahamed4)
* @author Braikhna Yousafzai (byousafz)
* @author Colin Stoddart (cstodda6)
* @author Evangelos Makris (emakris2)
*/
int main(){

	CustomerDatabase customerDB ("sql9.freemysqlhosting.net", "sql9372596", "fNf8Kr8wZD");
	BusinessDatabase businessDB ("sql9.freemysqlhosting.net", "sql9372596", "fNf8Kr8wZD");
	string quit = "n";
	int input = 0;

	while (quit != "y") {
		
		input = logInMenu();
		
		if (input == 1) {
			//business
			input = businessMenu(businessDB, customerDB);
		} else if (input == 2) {
			input = customerMenu(customerDB);
			//customer

		} else if (input == 3) {
			input = adminMenu(businessDB);

		} else if (input == -2) {
			//user enters "q"
			quit = "y";
		} 
		else {
			//user wants to quit
			break;
		}
		input = 0;

	}

	//exit message:
	cout <<  "\n\nThank you for using QuickTrack!\nBye for now." << endl;






}
