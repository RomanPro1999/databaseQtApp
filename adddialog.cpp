#include "adddialog.h"
#include "ui_adddialog.h"

AddDialog::AddDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDialog)
{
    ui->setupUi(this);

}

AddDialog::~AddDialog()
{
    delete ui;
}


void AddDialog::on_pushButtonCancel_clicked()
{
    MainWindow main;
    this->close();
    AdminDialog* adminDialog = new AdminDialog();
    adminDialog->show();
}
void AddDialog::on_pushButtonSave_clicked()
{
    MainWindow main;
    if(!main.connOpen()){
        QMessageBox::critical(this,tr("Connection error"),tr("Failed to connect to database"));
        return;
    }
    else{
        qDebug()<<"Connection true";
    }
    QString login, password,name,surname, maj;
    double salary;
    login=ui->lineEditLogin->text();
    password = ui->lineEditPassword->text();
    name = ui->lineEditName->text();
    surname = ui->lineEditSurname->text();
    maj= ui->lineEditMajor->text();
    salary = ui->lineEditSalary->text().toDouble();
    qDebug()<<login<<" "<<password<<" "<<name<<" "<<surname<<" "<<maj<<" "<<salary;
    if(login==""||password==""){
        QMessageBox::critical(this,tr("Wrong input"),tr("Login and password fields are required"));
        return;
    }

    QSqlQuery query;

    query.prepare("insert into employees(password,login,name,surname,salary,major) "
                  "values (:password, :login, :name, :surname, :salary, :major)");
    query.bindValue(":password",password);
    query.bindValue(":login",login);
    query.bindValue(":name",name);
    query.bindValue(":surname",surname);
    query.bindValue(":salary",salary);
    query.bindValue(":major",maj);
    if(query.exec()){
        QMessageBox::information(this,tr("Result"),tr("New employee added"));
    }
    else{
        QMessageBox::critical(this,tr("Error"),"Error adding a new employee");

    }
    main.connClose();
}
