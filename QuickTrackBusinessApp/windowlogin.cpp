#include "windowlogin.h"
#include "ui_windowlogin.h"

#include <QMessageBox>

#include <QPixmap>

WindowLogin::WindowLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WindowLogin)
{
    ui->setupUi(this);
    this->setWindowTitle("QuickTrack Login");
    this->setWindowModality(Qt::ApplicationModal);

    QPixmap picture(":/img/images/Logo_beside_text.svg");
    auto w= ui->logo->width();
    auto h= ui->logo->height();
    ui->logo->setPixmap(picture.scaled(w,h,Qt::KeepAspectRatio));

}

WindowLogin::~WindowLogin()
{
    delete ui;
}

void WindowLogin::closeEvent (QCloseEvent *event){

    QApplication::quit();
    //    event->accept();
}

void WindowLogin::on_loginButton_clicked()
{
    QString userName= ui->userName->text();
    QString password=ui->password->text();


    if(userName == "" && password == ""){
        connect(this,SIGNAL(fromLogin(bool)),this->parent(),SLOT(receiveMessageFromChildren(bool)));
        emit fromLogin(true);
//        hide();
        delete this;

    }
    else{

        ui->password->clear();
        QMessageBox::warning(this,"Login Error","User Name or Password is Incorrect.\nPlease check your input.");

    }
}
