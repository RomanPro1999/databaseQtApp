#include "mainwindow.h"
#include "ui_mainwindow.h"


bool createConnection();

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString login,password;
    login= ui->lineEditLogin->text();
    password = ui->lineEditPassword->text();

    if(!connOpen()){
        QMessageBox::critical(this,tr("Connection error"),tr("Failed to connect to database"));
        return;
    }
   QSqlQuery query;
   query.prepare("select major from employees where password='"+password +"' and login='"+login +"';");
   if(query.exec()){

    int count=0;
    while(query.next()){
        count++;
    }
    if(count==1){
        query.first();
        qDebug()<<query.value(0).toString();
        this->hide();
        if(query.value(0).toString()=="administrator"){
            AdminDialog adminDialog;
            adminDialog.setModal(true);
            adminDialog.exec();
        }
        else{
            EmployeeDialog employeeDialog;
            employeeDialog.setModal(true);
            employeeDialog.exec();
        }
    }
   }
   connClose();
}
