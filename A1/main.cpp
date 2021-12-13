/*****************
Braikhna Yousafzai
250933195
CS3307A
Oct 6, 2020

COVD-19 Tracking Program Main
*********************/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "country.h"

using namespace std;

int main() {

	vector<Country> countries;	//vector holds country records

	vector<vector<string>> data;	//vector holds individual rows from csv
	string line;
	ifstream file;
	
	file.open("summary.csv"); 	//opening csv file

	if (file.fail()) {		//file error
		cout << "File not found" << endl;
		exit(1);
	}
	
	getline(file, line);		//removing csv header
	
	while (getline(file, line)) {	//reading csv data
		vector<string> row;
		const char *start=line.c_str();
		bool inquotes = false;
		for (const char* p=start; *p; p++) {
			if (*p=='"') {
				inquotes = !inquotes;
			}
			else if (*p==',' && !inquotes) {
				row.push_back(string(start,p-start));
				start = p+1;
			}
		}
		row.push_back(string(start));		//putting data pts in row vector
		data.push_back(row);			//putting rows in data vector
	}

	//creating country objects and storing in data vector
	for (auto iterator = data.begin(); iterator != data.end(); iterator++) {
		vector<string> temp = *iterator;
		Country country(temp[0], temp[1]);
		country.setNewCases(stoi(temp[3]));
		country.setNewDeaths(stoi(temp[4]));
		country.setNewRecovered(stoi(temp[5]));
		country.setTotalCases(stoi(temp[8]));
		country.setTotalDeaths(stoi(temp[9]));
		country.setTotalRecovered(stoi(temp[10]));
		countries.push_back(country);
	}
	
	//user prompts
	cout << "Sort by: \n" << endl;
	cout << "New Cases" << endl;
	cout << "New Deaths" << endl;
	cout << "New Recovered" <<endl;
	cout << "Total Cases" << endl;
	cout << "Total Deaths" << endl;
	cout << "Total Recovered" << endl;
	cout << "\n";
	cout << "selection is case and whitespace sensitive" <<endl;
	cout << "\n";
	
	string input;
	getline(cin, input);		//get user input
	
	//checking for valid input
	while (input != "New Cases" && input != "New Deaths" && input != "New Recovered" && input != "Total Cases" && input != "Total Deaths" && input != "Total Recovered") {
		cin.clear();
		cout << "Invalid input. Try again: " << endl;
		getline(cin, input);
	}

	cout << "\n";

	//user prompt
	cout << "Show top 10 countries with: " << endl;
	cout << "Least" << endl;
	cout << "Most" << endl;
	cout << "\n";
	cout << "selection is case and whitespace sensitive" <<endl;
	cout << "\n";

	string order;
	getline(cin, order);	//sorting order user input
	
	//checking user input
	while (order != "Least" && order != "Most") {
		cin.clear();
		cout << "Try again: " <<endl;
		getline(cin, order);
	}
	
	int x;
	bool ascending = false;

	//sort new cases
	if (input == "New Cases"){
		x = 1;
		if (order == "Least"){
			sort(countries.begin(), countries.end(), [](Country& a, Country& b){ return a.getNewCases() < b.getNewCases(); });
			ascending = true;
		}
		else
			sort(countries.begin(), countries.end(), [](Country& a, Country& b){ return a.getNewCases() > b.getNewCases(); });
	}
	//sort new deaths
	else if (input == "New Deaths") {
		x = 2;
		if (order == "Least") {
			sort(countries.begin(), countries.end(), [](Country& a, Country& b){ return a.getNewDeaths() < b.getNewDeaths(); });
			ascending = true;
		}
		else
			sort(countries.begin(), countries.end(), [](Country& a, Country& b){ return a.getNewDeaths() > b.getNewDeaths(); });
	}
	//sort new recovered
	else if (input == "New Recovered") {
		x = 3;
		if (order == "Least") {
			sort(countries.begin(), countries.end(), [](Country& a, Country& b){ return a.getNewRecovered() < b.getNewRecovered(); });
			ascending = true;
		}
		else
			sort(countries.begin(), countries.end(), [](Country& a, Country& b){ return a.getNewRecovered() > b.getNewRecovered(); });
	}
	//sort total cases
	else if (input == "Total Cases") {
		x = 4;
		if (order == "Least") {
			sort(countries.begin(), countries.end(), [](Country& a, Country& b){ return a.getTotalCases() < b.getTotalCases(); });
			ascending = true;
		}
		else
			sort(countries.begin(), countries.end(), [](Country& a, Country& b){ return a.getTotalCases() > b.getTotalCases(); });
	}
	//sort total deaths
	else if (input == "Total Deaths") {
		x = 5;
		if(order == "Least") {
			sort(countries.begin(), countries.end(), [](Country& a, Country& b){ return a.getTotalDeaths() < b.getTotalDeaths(); });
			ascending = true;
		}
		else
			sort(countries.begin(), countries.end(), [](Country& a, Country& b){ return a.getTotalDeaths() > b.getTotalDeaths(); });
	}
	//sort total recovered
	else {
		x = 6;
		if (order == "Least") {
			sort(countries.begin(), countries.end(), [](Country& a, Country& b){ return a.getTotalRecovered() < b.getTotalRecovered(); });
			ascending = true;
		}
		else
			sort(countries.begin(), countries.end(), [](Country& a, Country& b){ return a.getTotalRecovered() > b.getTotalRecovered(); });
	}

	int maxWidth = 70;
	int largest;
	int numPrint;
	double scale;
	double percent;
	int values[10];
	string status;
	string seq;
	string marker = "cases";
	
	if (ascending)
		seq = "Top 10 countries with least: ";
	else
		seq = "Top 10 countries with most: ";
	
	//getting parameter values depending based on user selected param
	switch (x) {
		case 1:
			status = "New Confirmed Cases";
			if (ascending)
				largest = countries[9].getNewCases();
			else
				largest = countries[0].getNewCases();
			for (int i = 0; i < 10; i++) {
				cout << countries[i].getNewCases() << endl;
				values[i] = countries[i].getNewCases();
			}
			break;
		case 2:
			status = "New Deaths";
			marker = "deaths";
			if (ascending)
				largest = countries[9].getNewDeaths();
			else
				largest = countries[0].getNewDeaths();
			for (int i = 0; i < 10; i++) {
				values[i] = countries[i].getNewDeaths();
			}
			break;
		case 3:
			status = "New Recovered Cases";
			if (ascending)
				largest = countries[9].getNewRecovered();
			else
				largest = countries[0].getNewRecovered();
			for (int i = 0; i < 10; i++) {
				values[i] = countries[i].getNewRecovered();
			}
			break;
		case 4:
			status = "Total Confirmed Cases";
			if (ascending)
				largest = countries[9].getTotalCases();
			else
				largest = countries[0].getTotalCases();
			for (int i = 0; i < 10; i++) {
				values[i] = countries[i].getTotalCases();
			}
			break;
		case 5:
			status = "Total Deaths";
			marker = "deaths";
			if (ascending)
				largest = countries[9].getTotalDeaths();
			else
				largest = countries[0].getTotalDeaths();
			for (int i = 0; i < 10; i++) {
				values[i] = countries[i].getTotalDeaths();
			}
			break;
		case 6:
			status = "Total Recovered Cases";
			if (ascending)
				largest = countries[9].getTotalRecovered();
			else
				largest = countries[0].getTotalRecovered();
			for (int i = 0; i < 10; i++) {
				values[i] = countries[i].getTotalRecovered();
			}
			break;
	}

	//printing result graphically
	scale = ((double)largest)/((double) maxWidth);
	//handles the case where the largest number of cases/deaths is zero
	if (largest == 0) {
		for (int i = 0; i < 10; i++) {
			cout << countries[i].getCode() << "  |  " << endl;
			cout << "      |" << endl;
		}
	}
	else {
		for (int i = 0; i < 10; i++){
			percent = ((double) values[i]) / ((double) largest);
			numPrint = (int) (((double)maxWidth) * percent);
			cout << countries[i].getCode() << "  |  " << string(numPrint, '#') << endl;
			cout << "      |" << endl;
		}
	}
	cout << string(80, '-') << endl;
	cout << seq << status << "; Each # is approx. " << scale << " " << marker << endl;

	return 0;
}




