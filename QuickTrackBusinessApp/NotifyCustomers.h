#ifndef NOTIFYCUSTOMERS
#define NOTIFYCUSTOMERS
#include<stdlib.h>
#include<string>

using namespace std;

class NotifyCustomers{
	private:
	int infectedID, inTime, outTime;
	string date, fileName;
	vector<string> emailList;
	
	public:
	void findUserInfo(int infectedID);
	vector<string> findEmails(int inTime, int outTime, string date);
	void sendEmail(string msg);
	};
	#endif