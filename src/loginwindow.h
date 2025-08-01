#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class LoginWindow;
}
QT_END_NAMESPACE

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();


    
   private slots:
    void close_window();

    void Login();

private:
    Ui::LoginWindow *ui;
    
};

#endif // LOGINWINDOW_H
