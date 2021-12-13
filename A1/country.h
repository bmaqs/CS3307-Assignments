/************
Braikhna Yousafzai
250933195
CS3307
Oct 4, 2020

Country class declarations
************/
#include <string>
using namespace std;

class Country{
	private:
		string countryName;
		string countryCode;
		int newCases;
		int newDeaths;
		int newRecovered;
		int totalCases;
		int totalDeaths;
		int totalRecovered;
	
	public:
		Country(string name, string code);
		~Country();
		void setCountryName(string name);
		void setCountryCode(string code);
		void setNewCases(int x);
		void setNewDeaths(int x);
		void setNewRecovered(int x);
		void setTotalCases(int x);
		void setTotalDeaths(int x);
		void setTotalRecovered(int x);
		string getName();
		string getCode();
		int getNewCases();
		int getNewDeaths();
		int getNewRecovered();
		int getTotalCases();
		int getTotalDeaths();
		int getTotalRecovered();
};
