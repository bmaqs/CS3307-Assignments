#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "CustomerDatabase.h"

#include <QMainWindow>
#include <QCloseEvent>

#include "signinexistingcustomer.h"
#include "signinnewcustomer.h"
#include "windowlogin.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


/**
* @brief This class is the main window of the Business-End of the system.
*
* @author Jem Parlakyigit (mparlaky)
*/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void UpdateSignedInTable();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_actionAbout_triggered();

    void on_actionQuit_triggered();

    void on_tableWidget_clicked(const QModelIndex &index);

    void closeEvent (QCloseEvent *event);

    void receiveMessageFromChildren(const bool &msg);

signals:
    void sendMessage(const QString &msg);

private:
    Ui::MainWindow *ui;
    void UpdateTable();
    MainWindow *mainWindow;
    SignInExistingCustomer *signInExistingCustomer;
    SignInNewCustomer *signInNewCustomer;
    WindowLogin *windowLogin;

};
#endif // MAINWINDOW_H
