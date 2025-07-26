#include "loginwindow.h"
#include "mainwindow.h"
#include "ui_loginwindow.h"

#include <QFile>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QCoreApplication>
#include <QLineEdit>
#include <QPushButton>
#include <QDebug>

LoginWindow::LoginWindow(QWidget *parent)
    : QDialog(parent), ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    setFixedSize(480, 420);
    setWindowFlag(Qt::FramelessWindowHint);

    setStyleSheet(R"(
        QWidget {
            background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1,
                                              stop:0 #1e1e2f, stop:1 #0c0c1e);
            border-radius: 12px;
            font-family: 'Fira Code', 'JetBrains Mono', monospace;
            color: #e0e0e0;
        }

        QLineEdit {
            background-color: #111;
            border: 1px solid #444;
            border-radius: 6px;
            padding: 6px;
            color: #e0e0e0;
            font-size: 14px;
        }

        QLineEdit:focus {
            border: 1px solid #00eaff;
            background-color: #1a1a1a;
        }

        QPushButton {
            background-color: #151533;
            color: #00eaff;
            border: 1px solid #00eaff;
            border-radius: 6px;
            padding: 8px;
            font-weight: 500;
        }

        QPushButton:hover {
            background-color: #1f1f4a;
        }

        QPushButton:pressed {
            background-color: #0e0e2e;
        }

        QLabel#status {
            color: #ff4444;
            background-color: transparent;
            font-weight: 500;
            
        }
    )");
    ui->status->setFixedWidth(300);
    ui->status->setObjectName("status");
    ui->status->setText("");

    ui->name_entre->setPlaceholderText("Username");
    ui->pass_entre->setPlaceholderText("Password");
    ui->pass_entre->setEchoMode(QLineEdit::Password);

    connect(ui->cancel, &QPushButton::clicked, this, &LoginWindow::close_window);
    connect(ui->loginbutton, &QPushButton::clicked, this, &LoginWindow::Login);
    connect(ui->pass_entre, &QLineEdit::returnPressed, this, &LoginWindow::Login);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::close_window()
{
    this->close();
}

void LoginWindow::Login()
{
    QString username = ui->name_entre->text();
    QString password = ui->pass_entre->text();

    QSqlDatabase db;
    if (QSqlDatabase::contains("login_connection")) {
        db = QSqlDatabase::database("login_connection");
    } else {
        db = QSqlDatabase::addDatabase("QSQLITE", "login_connection");

        QString dbPath = QCoreApplication::applicationDirPath() + "/../databases/users.db";
        db.setDatabaseName(dbPath);

        if (!QFile::exists(dbPath)) {
            ui->status->setText("Database file not found.");
            return;
        }
    }

    if (!db.open()) {
        ui->status->setText("Failed to open database.");
        return;
    }

    QSqlQuery query(db);
    query.prepare("SELECT * FROM users WHERE username = :username AND password = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password); //always encrypte ur data

    if (query.exec()) {
        if (query.next()) {
            MainWindow *mainwindow = new MainWindow();
            mainwindow->show();
            this->close();
        } else {
            ui->status->setText("Invalid credentials ");
        }
    } else {
        ui->status->setText("Query failed.");
    }
}
