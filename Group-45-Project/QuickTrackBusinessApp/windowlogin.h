#ifndef WINDOWLOGIN_H
#define WINDOWLOGIN_H

#include <QDialog>
#include <QCloseEvent>

namespace Ui {
class WindowLogin;
}

/**
* @brief This class is the login window for the Business-End.
*
* @author Jem Parlakyigit (mparlaky)
*/
class WindowLogin : public QDialog
{
    Q_OBJECT

public:
    explicit WindowLogin(QWidget *parent = nullptr);
    ~WindowLogin();

private slots:

    void closeEvent (QCloseEvent *event);

    void on_loginButton_clicked();

signals:
    void fromLogin(const bool &msg);

private:
    Ui::WindowLogin *ui;
};

#endif // WINDOWLOGIN_H
