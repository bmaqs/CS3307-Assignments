#ifndef SIGNINEXISTINGCUSTOMER_H
#define SIGNINEXISTINGCUSTOMER_H

#include <QDialog>

namespace Ui {
class SignInExistingCustomer;
}

/**
* @brief This class is for signing in existing customers to the system from a new window.
*
* @author Jem Parlakyigit (mparlaky)
*/
class SignInExistingCustomer : public QDialog
{
    Q_OBJECT

public:
    explicit SignInExistingCustomer(QWidget *parent = nullptr);
    ~SignInExistingCustomer();

private slots:

    void on_siginInButton_clicked();

signals:
    void fromExistingCustomer(const bool &msg);

private:
    Ui::SignInExistingCustomer *ui;
};

#endif // SIGNINEXISTINGCUSTOMER_H
