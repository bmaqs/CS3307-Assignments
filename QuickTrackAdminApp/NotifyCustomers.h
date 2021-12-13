#ifndef NOTIFYCUSTOMERS
#define NOTIFYCUSTOMERS
#include<stdlib.h>
#include<string>
#include <vector>

using namespace std;

/**
* @brief This class allows is responsible for sending email notifications to customers
* @author Abdulrahim Hamed (ahamed4)
* @author Braikhna Yousafzai (byousafz)
* @author Colin Stoddart (cstodda6)
* @author Evangelos Makris (emakris2)
* @author Jem Parlakyigit (mparlaky)
*/
class NotifyCustomers{	
	public:
	/**
	 * @brief Sends an email to a list of emails
	 * 
	 * @param emails A vector containing all the emails to send the message to
	 * @param subject the subject of the email
	 * @param msg The message to be sent to the emails
	 */
	static void sendEmail(vector<string> emails, string subject, string msg);

	/**
	 * @brief Sends an email to a list of emails
	 * 
	 * @param emails A vector containing all the emails to send the message to
	 * @param msg The message to be sent to the emails
 	*/
	static void sendEmail(vector<string> emails, string msg);
	};
	#endif