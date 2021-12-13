#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "signinexistingcustomer.h"
#include "signinnewcustomer.h"
#include "windowaboutquicktrack.h"

#include "CustomerDatabase.h"
#include "Database.h"
#include "SignInOut.h"
#include "Sync.h"
#include <stdio.h>
#include <QMessageBox>
#include <QString>
#include <string.h>
#include <string>
#include <QStyle>
#include <QDesktopWidget>


bool isRowSelected;
int indexSelectedRow;
int numSignedInCustomers;

static CustomerDatabase customerDB ("sql9.freemysqlhosting.net", "sql9372596", "fNf8Kr8wZD");

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setVisible(true);
    ui->tableWidget->verticalHeader()->setVisible(true);
    this->setWindowTitle("QuickTrack Contact Tracing");
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    this->setGeometry(
                    QStyle::alignedRect(
                        Qt::LeftToRight,
                        Qt::AlignCenter,
                        this->size(),
                        qApp->desktop()->availableGeometry()
                    )
                 );


    windowLogin = new WindowLogin(this);
    windowLogin ->show();

    signInExistingCustomer = new SignInExistingCustomer(this);
    signInNewCustomer = new SignInNewCustomer(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::UpdateTable()
{
    //    CustomerDatabase customerDB ("sql9.freemysqlhosting.net", "sql9372596", "fNf8Kr8wZD");
    vector<Customer> allSignedIN = customerDB.getSignedIn();
    numSignedInCustomers = allSignedIN.size();
    ui->tableWidget->setRowCount(numSignedInCustomers);
    for(int i=0; i < numSignedInCustomers; i++){

        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(allSignedIN[i].getUniqueID())));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::fromStdString(allSignedIN[i].getFirstName())));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::fromStdString(allSignedIN[i].getLastName())));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(QString::number(allSignedIN[i].getPhoneNum())));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::fromStdString(allSignedIN[i].getEmail())));
    }
}

void MainWindow::on_pushButton_clicked()
{

//    signInExistingCustomer = new SignInExistingCustomer(this);
    signInExistingCustomer->show();

}

void MainWindow::on_pushButton_2_clicked()
{

//    signInNewCustomer = new SignInNewCustomer(this);
    signInNewCustomer->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    if(numSignedInCustomers==0){
        // No Customers Signed In
        QMessageBox::warning(this,"Warning","No Customers Signed In");
    }

    else if(!isRowSelected){
        // No Customers Selected
        QMessageBox::warning(this,"Warning","Please Select a Customer.");

    }
    else{

        // Confirmation Dialog
        QMessageBox::StandardButton response = QMessageBox::question(this,"Confirmation","Sign out Customer?",QMessageBox::Yes |QMessageBox::No);

        // Now Sign Out
        if(response==QMessageBox::Yes){
            Customer customerSignOut;
            SignInOut sio;
//            string email = ui->tableWidget->item(indexSelectedRow,4)->text().toStdString();
            string phone = ui->tableWidget->item(indexSelectedRow,3)->text().toStdString();

            customerSignOut = customerDB.selectCustomerByPhone(phone);

            auto response = sio.SignOut(customerSignOut.getUniqueID(), 1, customerDB);

            if(response){
                UpdateTable();
                isRowSelected=false;
                QMessageBox::information(this,"Success","Customer Successfully Signed Out.");
            }
            else{

                QMessageBox::warning(this,"Failure","Customer could not Signed Out.");
            }

        }
    }

}

void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}


void MainWindow::on_actionAbout_triggered()
{
    windowAboutQuickTrack about;
    about.setModal(true);
    about.exec();
}

void MainWindow::on_tableWidget_clicked(const QModelIndex &index)
{
    QItemSelectionModel *select = ui->tableWidget->selectionModel();

    isRowSelected = select->hasSelection();
    indexSelectedRow = select->currentIndex().row();

}

void MainWindow::closeEvent (QCloseEvent *event){

    QApplication::quit();
}

void MainWindow::receiveMessageFromChildren(const bool &success)
{

    if(success){

        UpdateTable();
    }
}

