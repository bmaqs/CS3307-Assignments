#ifndef SIGNINNEWCUSTOMER_H
#define SIGNINNEWCUSTOMER_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class SignInNewCustomer;
}

/**
* @brief This class is for signing in new customers to the system from a new window.
*
* @author Jem Parlakyigit (mparlaky)
*/
class SignInNewCustomer : public QDialog
{
    Q_OBJECT

public:
    explicit SignInNewCustomer(QWidget *parent = nullptr);
    ~SignInNewCustomer();

private slots:

    void on_singInNewButton_clicked();

signals:
    void fromNewCustomer(const bool &msg);

private:
    Ui::SignInNewCustomer *ui;
};

#endif // SIGNINNEWCUSTOMER_H
