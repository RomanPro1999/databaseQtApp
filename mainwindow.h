#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSql>
#include <QDebug>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlRecord>
#include "admindialog.h"
#include "employeedialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase mydb;
    void connClose(){
        mydb.close();
    };
    bool connOpen(){
        mydb = QSqlDatabase::addDatabase("QMYSQL");
        mydb.setHostName("localhost");
        mydb.setDatabaseName("firm");
        mydb.setUserName("root");
        if(!mydb.open()){
            QMessageBox ::critical(this,tr("Connection error"),tr("Failed to connect to database"));
            return false;
        }
        else{
            qDebug()<<"Connected";
            return true;
        }
    };
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
