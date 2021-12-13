#include "Customer.h"
#include "SignInOut.h"
#include <stdio.h>
#include <iostream>
#include "CustomerDatabase.h"
#include "Database.h"
using namespace std;

int Input(int option){
	string input = "z";

	// Checking which case to run
	// Main menu input
	if(option == 1){
		cout << "\nSelection: ";
		cin.clear();
		getline(cin, input);
		while (input != "1" && input != "2" && input != "q") {
			cout << "Invalid input. Try again: ";
			cin.clear();
			getline(cin, input);
		}
		if(input == "q"){ return -2; }

		return stoi(input);
	}
	// Sign in input
	else if (option == 2){
		cout << "Does customer have an account (y/n)? " << endl;
		cin.clear();
		getline(cin, input);
		while (input != "y" && input != "n" && input != "q") {
			cout << "Invalid input. Try again with either 'y' or 'n': ";
			cin.clear();
			getline(cin, input);
		}
		if(input == "q"){ return -2; }

		if(input == "y")
			return 1;
		else
			return 2;
	}

	// sign out input
	else if(option == 3){
		cout << "Does customer have account number(y/n)? " << endl;
		cin.clear();
		getline(cin, input);
		while (input != "y" && input != "n" && input != "q") {
			cout << "Invalid input. Try again with either 'y' or 'n': ";
			cin.clear();
			getline(cin, input);
		}
		if(input == "q"){ return -2; }

		if(input == "y")
			return 1;
		else
			return 2;
	}
	// Quit input
	else if(option == 4){
		string quit = "";

		cout << "Would you like to quit QuickTrack (y/n)? ";
		cin.ignore();
		getline(cin, quit);
		while(quit != "y" && quit != "n"){
			cout << "Invalid Option. Please Try Again.\n\n";
			cout << "Would you like to quit QuickTrack? ";
			cin.clear();
			getline(cin, quit);
		}
		if(quit == "n")
			return 0;
		else
			return -1;
	}

	// default
	return -1;
}

// Main Menu
int menu() {
	cout << "\n\nMain Menu - Select one of the following options" << endl;
	cout << "1. Sign in a customer" << endl;
	cout << "2. Sign out a customer" << endl;
	return Input(1);
}

// Sign In Function
void signIn(int flag, string F, string L, string P, string E, int A, CustomerDatabase db){
	int businessID;
	SignInOut sio;
	Customer user;
	cout << "\nEnter 1 for the business ID please (testing using ID=1): ";
	cin.clear();
	cin >> businessID;
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

void signOut(int flag, string F, string L, string P, string E, int A, CustomerDatabase db){
	int businessID;
        SignInOut sio;
        Customer user;
	cout << "\nEnter 1 for the business ID please (testing using ID=1): ";
	cin.clear();
	cin >> businessID;
	// Sign in
	if(flag == 1) { sio.SignOut(A, businessID, db); }
	else {
                user = db.selectCustomer(E);
                sio.SignOut(user.getUniqueID(), businessID, db); 
        }
	return;
}

// Main Function of Code
int main(){
	Database test;
	cout << test.getConnectLocally()<<endl;
	cout <<"----------------------------------------"<<endl;
        CustomerDatabase customerDB ("sql9.freemysqlhosting.net", "sql9372596", "fNf8Kr8wZD");
        
	// Variables, using default business ID for test purposes
	int input = 0, AccNum;
	string quit = "n";
	string Fname = "", Lname = "", email = "", phone = "";
	
	// Intro
	cout << "\n\nWelcome to QuickTrack!" << endl;
	cout << "----------------------" << endl;

	// Main program
	while(quit != "y"){
		// Calling main menu
		input = menu();

		// Determining appropriate menu to send user too
		// Sign In menu
		if (input == 1) {
			cout << "\nSign-In\n-------" << endl;
			input = Input(2);
			if(input == 1){
				cout << "Enter account number: ";
				cout << "For testing purposes the following account numbers can be selected: 1054, 1052, 1047" << endl;
				cin.clear();
				cin >> AccNum;
				signIn(1, "null", "null", "null", "null", AccNum, customerDB);
			}
			// Makes new customer then calls sign in function
			else{
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
				signIn(2, Fname, Lname, phone, email, 0, customerDB);
			}

		}
		// Sign out menu
		else if (input == 2) {
			cout << "\nSign-Out\n--------" << endl;
			input = Input(3);
			if(input == 1){
				cout << "Enter account number: ";
				cout << "For testing purposes the following account numbers can be selected: 1054, 1052, 1047" << endl;
				cin >> AccNum;
				signOut(1, "null", "null", "null", "null", AccNum, customerDB);
			}
			// Ask for customer info adn the calls sign out function
			else{
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
				signOut(2, Fname, Lname, phone, email, 0, customerDB);
			}
		}
		// Return to main menu
		else if(input == -1){

		}
		// Quit on any input
		else if(input == -2){ break; }

		// Asking if the user wants to continue the program or close it
		input = Input(4);
		if(input == -1)
			quit = "y";
	}
	// Exit Message
	cout << "\n\nThank you for using QuickTrack!\nBye for now." << endl;
	
}
