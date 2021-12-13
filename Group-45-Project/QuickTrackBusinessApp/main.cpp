#include "SignInOut.h"
#include "CustomerDatabase.h"
#include "mainwindow.h"
#include "windowlogin.h"
#include "Database.h"
#include <stdlib.h>
#include <iostream>
#include <QApplication>
#include "Customer.h"
#include <stdio.h>
#include <iostream>
#include "Database.h"
#include "Sync.h"
#include "tempUser.h"
#include <vector>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    a.setQuitOnLastWindowClosed(false);

    MainWindow business;
    business.show();

//    WindowLogin w;
//    w.show();

    return a.exec();

}
