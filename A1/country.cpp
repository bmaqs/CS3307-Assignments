/*************
Braikhna Yousafzai
250933195
CS 3007A
Oct 4, 2020

Country class function definitions
****************/

#include "country.h"

/*********
*name: Country(string name, string code)
*parameters: string name, string code
*description: Constructor. Instantiates Country object
**********/
Country::Country(string name, string code)
{
	countryName = name;
	countryCode = code;
	newCases = 0;
	newDeaths = 0;
	newRecovered = 0;
	totalCases = 0;
	totalDeaths = 0;
	totalRecovered = 0;
}

/*********
*name: ~Country()
*parameters: 
*description: removes Country object from memory
**********/
Country::~Country()
{

}
 
/*********
*name: setCountryName(string name)
*parameters: string name
*description: sets countryName to name
**********/
void Country::setCountryName(string name)
{
	countryName = name;
}

/*********
*name: setCountryCode(string code)
*parameters: string code
*description: sets countryCode to code
**********/
void Country::setCountryCode(string code)
{
	countryCode= code;
}

/*********
*name: setNewCases(int x)
*parameters: int x
*description: sets number of newCases to x
**********/
void Country::setNewCases(int x)
{
	newCases = x;
}

/*********
*name: setNewDeaths(int x)
*parameters: int x
*description:sets number of newDeaths to x
**********/
void Country::setNewDeaths(int x)
{
	newDeaths = x;
}

/*********
*name: setNewRecovered(int x)
*parameters: int x
*description: sets number of newRecovered to x
**********/
void Country::setNewRecovered(int x)
{
	newRecovered = x;
}

/*********
*name: setTotalCases(int x)
*parameters: int x
*description: sets totalCases to x
**********/
void Country::setTotalCases(int x)
{
	totalCases = x;
}

/*********
*name: setTotalDeaths(int x)
*parameters:  int x 
*description: sets totalDeaths to x
**********/
void Country::setTotalDeaths(int x)
{
	totalCases = x;
}

/*********
*name: setTotalRecovered(int x)
*parameters: int x 
*description: sets totalRecovered to x
**********/
void Country::setTotalRecovered(int x)
{
	totalRecovered = x;
}

/*********
*name: getName()
*parameters:
*description: returns the countryName
*return: string countryName 
**********/
string  Country::getName()
{
	return countryName;
}

/*********
*name: getCode()
*parameters:
*description: returns the countryCode
*return: string countryCode 
**********/
string Country::getCode()
{
	return countryCode;
}

/*********
*name: getNewCases()
*parameters: 
*description: returns the number of newCases
*return: int newCases 
**********/
int Country::getNewCases()
{
	return newCases;
}

/*********
*name: getNewDeaths()
*parameters: 
*description: returns the number of newDeaths
*return: int newDeaths 
**********/
int Country::getNewDeaths()
{
	return newDeaths;
}

/*********
*name: getNewRecovered()
*parameters: 
*description: returns the number of newRecovered
*returns: int newRecovered 
**********/
int Country::getNewRecovered()
{
	return newRecovered;
}

/*********
*name: getTotalCases()
*parameters: 
*description: returns the number of totalCases
*return: int totalCases
**********/
int Country::getTotalCases()
{
	return totalCases;
}

/*********
*name: getTotalDeaths()
*parameters: 
*description: returns the number of totalDeaths
*return: int totalDeaths 
**********/
int Country::getTotalDeaths()
{
	return totalDeaths;
}

/*********
*name: getTotalRecovered
*parameters: 
*description: returns the number of totalRecovered
*return: int totalRecovered 
**********/
int Country::getTotalRecovered()
{
	return totalRecovered;
}

