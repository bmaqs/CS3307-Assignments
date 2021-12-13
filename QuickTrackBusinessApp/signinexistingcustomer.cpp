#include "signinexistingcustomer.h"
#include "ui_signinexistingcustomer.h"

#include "CustomerDatabase.h"
#include "Database.h"
#include "SignInOut.h"
#include "Sync.h"
#include <stdio.h>
#include <QMessageBox>
#include <QRegExpValidator>

static CustomerDatabase customerDB3 ("sql9.freemysqlhosting.net", "sql9372596", "fNf8Kr8wZD");

SignInExistingCustomer::SignInExistingCustomer(QWidget *parent) : QDialog(parent), ui(new Ui::SignInExistingCustomer)
{
    ui->setupUi(this);
    this->setWindowTitle("Sign In Existing Customer");
    this->setWindowModality(Qt::ApplicationModal);
    ui->customerCode->setInputMask("D99-D99-9999");

}

SignInExistingCustomer::~SignInExistingCustomer()
{
    delete ui;
}

void SignInExistingCustomer::on_siginInButton_clicked()
{
    QString phone =ui->customerCode->text().remove(QRegularExpression("[-]+"));

    //CASE 0 INPUT ERROR
    QRegularExpression regex("^[0-9]{10}$");

    if(!regex.match(phone).hasMatch()){

        QMessageBox::warning(this,"Failure","Please Input 10 Digit Phone Number with Area Code.");
        return;
    }

    Customer user;
    user = customerDB3.selectCustomerByPhone(phone.toStdString());

    //CASE 1 IF CUSTOMER DOES NOT EXIST
    if(customerDB3.searchCustomer(user.getUniqueID())!=1){

        QMessageBox::warning(this,"Failure","Customer has never signed in to this business.");
        return;
    }

    //CASE 2 IF CUSTOMER IS ALREADY INSIDE
    if(customerDB3.isCustomerInside(user.getUniqueID())){

        QMessageBox::warning(this,"Failure","Customer is already inside.\nCannot Sign In twice.\nTry Signing Out and Signin In again if you need to.");
        return;
    }

    SignInOut sio;
    auto response = sio.SignIn(user.getUniqueID(), user.getFirstName(), user.getLastName(), user.getPhoneNum(), user.getEmail(), 1, customerDB3);

    //CASE 3 SUCCESSFUL SIGN IN
    if(response){
        connect(this,SIGNAL(fromExistingCustomer(bool)),this->parent(),SLOT(receiveMessageFromChildren(bool)));
        emit fromExistingCustomer(true);
        QMessageBox::information(this,"Success","Existing Customer Successfully Signed In.");
        ui->customerCode->clear();

    //CASE 4 SQL Exception
    }else{

        QMessageBox::warning(this,"Failure","Connection Error!");
    }
}


