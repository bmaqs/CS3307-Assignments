#include "NotifyCustomers.h"
#include "Customer.h"
#include "CustomerDatabase.h"
#include <string>
#include <string.h>

using namespace std;

void email(string to, string subject, string message)
{ 
    FILE *pipe = popen((("mail -s \"") + subject + "\" \"" + to + "\"").c_str(), "w");
    if (pipe != NULL) {
        fwrite(message.c_str(), 1, strlen(message.c_str()), pipe);
        fwrite(".\n", 1, 2, pipe);
        pclose(pipe);
     }
     else {
         perror("Something went wrong (do you have your mail config set up correctly?)");
     }
}
void NotifyCustomers::sendEmail(vector<string> emails, string msg){
	for(auto iterator = emails.begin(); iterator != emails.end(); iterator++){
		//email(emails[i], "COVID-19 Potential exposure", msg);
		sendEmail(emails, "COVID-19 Potential Exposure", msg);
	}
}
void NotifyCustomers::sendEmail(vector<string> emails, string subject, string msg){
	int i = 0;
	for(auto iterator = emails.begin(); iterator != emails.end(); iterator++){
		email(emails[i], subject, msg);
		i++;
	}
}
