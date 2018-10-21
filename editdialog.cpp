#include "editdialog.h"
#include "ui_editdialog.h"

EditDialog::EditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditDialog)
{
    ui->setupUi(this);
}

EditDialog::~EditDialog()
{
    delete ui;
}


void EditDialog::on_pushButtonCancle_clicked()
{
    this->close();
    AdminDialog* adminDialog = new AdminDialog();
    adminDialog->show();
}

void EditDialog::on_pushButton_2_clicked()
{
    MainWindow main;
    QSqlQueryModel* model = new QSqlQueryModel();
    if(!main.connOpen()){
        QMessageBox::critical(this,tr("Connection error"),tr("Failed to connect to database"));
        return;
    }
    QSqlQuery* query = new QSqlQuery(main.mydb);
    query->prepare("select * from employees");
    query->exec();
    model->setQuery(*query);
    ui->tableView->setModel(model);
    main.connClose();
}


void EditDialog::on_pushButton_clicked()
{
    MainWindow main;
    if(!main.connOpen()){
        QMessageBox::critical(this,tr("Connection error"),tr("Failed to connect to database"));
        return;
    }
    if(ui->lineEditSalary->text()=="There are no user with this login"){
        QMessageBox::critical(this,tr("IO error"),tr("There are no user with this login"));
        return;
    }
    QString login,password,name,surname,maj;
    double salary = ui->lineEditSalary->text().toDouble();
    int id=ui->lineEditId->text().toInt();
    login=ui->lineEditLogin->text();
    password = ui->lineEditPassword->text();
    name = ui->lineEditName->text();
    surname = ui->lineEditSurname->text();
    maj = ui->lineEditMajor->text();

    qDebug()<<id<<" "<<login<<" "<<password<<" "<<" "<<name<<" "<<surname<<" "<<salary<<" "<<maj;
    QSqlQuery query;
    query.prepare("update employees "
                  "set password=:password, login=:login,"
                  "name=:name, surname=:surname,"
                  "salary=:salary, major=:major where id=:id");
    query.bindValue(":password",password);
    query.bindValue(":login",login);
    query.bindValue(":name",name);
    query.bindValue(":surname",surname);
    query.bindValue(":salary",salary);
    query.bindValue(":major",maj);
    query.bindValue(":id",id);
    if(!query.exec()){
        QMessageBox::critical(this,tr("Error"),tr("Updating error"));
    }
    else{
        QMessageBox::information(this,tr("Result"),tr("Employee data is updated"));
    }
    main.connClose();
}



void EditDialog::on_pushButtonFillData_clicked()
{
    MainWindow main;
    if(!main.connOpen()){
        QMessageBox::critical(this,tr("Connection error"),tr("Failed to connect to database"));
        return;
    }
    QString log= ui->lineEditLogin->text();
    QSqlQuery query;
    query.prepare("select * from employees where login=:login");
    query.bindValue(":login",log);
    if(query.exec()){
        query.first();
        ui->lineEditId->setText(query.value(0).toString());
        ui->lineEditPassword->setText(query.value(1).toString());
        ui->lineEditSalary->setText(query.value(5).toString());
        ui->lineEditMajor->setText(query.value(6).toString());
        ui->lineEditName->setText(query.value(3).toString());
        ui->lineEditSurname->setText(query.value(4).toString());
    }
    else{
        ui->lineEditName->setText("There are no user with this login");
        ui->lineEditSurname->setText("There are no user with this login");
        ui->lineEditPassword->setText("There are no user with this login");
        ui->lineEditSalary->setText("There are no user with this login");
        ui->lineEditMajor->setText("There are no user with this login");
    }
    main.connClose();
}
