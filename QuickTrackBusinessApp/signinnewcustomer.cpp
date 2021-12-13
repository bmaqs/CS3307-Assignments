#include "signinnewcustomer.h"
#include "ui_signinnewcustomer.h"

#include "CustomerDatabase.h"
#include "Database.h"
#include "SignInOut.h"
#include "Sync.h"
#include <stdio.h>
#include <QRegExpValidator>

using namespace std;

static CustomerDatabase customerDB2 ("sql9.freemysqlhosting.net", "sql9372596", "fNf8Kr8wZD");

SignInNewCustomer::SignInNewCustomer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignInNewCustomer)
{
    ui->setupUi(this);
    this->setWindowTitle("Sign In New Customer");
    this->setWindowModality(Qt::ApplicationModal);
    ui->phone->setInputMask("D99-D99-9999");

}


SignInNewCustomer::~SignInNewCustomer()
{
    delete ui;
}

void SignInNewCustomer::on_singInNewButton_clicked()
{
    QString phone=ui->phone->text().remove(QRegularExpression("[-]+"));

    QRegularExpression regex("^[0-9]{10}$");

    //CASE 0 INPUT ERROR
    if(!regex.match(phone).hasMatch()){

        QMessageBox::warning(this,"Failure","Please Input 10 Digit Phone Number with Area Code.");
        return;
    }

    QString firstName=ui->firstName->text();
    QString lastName=ui->lastName->text();
    QString email=ui->email->text();

    SignInOut sio;
    Customer user;

    user.setFirstName(firstName.toStdString());
    user.setLastName(lastName.toStdString());
    user.setPhoneNum(phone.toLongLong(nullptr,10));
    user.setEmail(email.toStdString());

    auto isNewCustomerAdded = customerDB2.addCustomer(user);

    if(isNewCustomerAdded){
        user = customerDB2.updateUniqueID(user);

        auto response = sio.SignIn(user.getUniqueID(), user.getFirstName(), user.getLastName(), user.getPhoneNum(), user.getEmail(), 1, customerDB2);

        //CASE 1 CUSTOMER SUCCESSFULLY ADDED TO DB AS A NEW CUSTOMER AND SIGNING IN
        if(response){
            connect(this,SIGNAL(fromNewCustomer(bool)),this->parent(),SLOT(receiveMessageFromChildren(bool)));
            emit fromNewCustomer(true);
            QMessageBox::information(this,"Success","New Customer Successfully Signed In.");

            foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
               le->clear();
            }

            return;

        //CASE 2 SQL Exception
        }else{

            QMessageBox::warning(this,"Failure","Connection Error.");
            return;
        }
    }

    //CASE 3 CUSTOMER COULDNOT BE ADDED
    QMessageBox::warning(this,"Failure","Customer should have visited this business before.\nPlease hit \"Sign In Existing Customer\"\nand type phone number. ");


}
