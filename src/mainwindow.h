#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qglobal.h>
#include <qmainwindow.h>
#include <qobjectdefs.h>
#include <qwidget.h>

QT_BEGIN_NAMESPACE
namespace Ui {
    class QMainWindow;
}
QT_END_NAMESPACE

     class MainWindow : public QMainWindow
     {

        Q_OBJECT
    
    public:
    explicit MainWindow (QWidget *parent = nullptr );
    ~MainWindow();

    

    private:

    Ui::QMainWindow *ui;
    
};
#endif  //MAINWINDOW_Hz