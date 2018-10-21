#include "deletedialog.h"
#include "ui_deletedialog.h"

DeleteDialog::DeleteDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteDialog)
{
    ui->setupUi(this);
}

DeleteDialog::~DeleteDialog()
{
    delete ui;
}


void DeleteDialog::on_pushButtonCancel_clicked()
{
    this->close();
    AdminDialog* adminDialog = new AdminDialog();
    adminDialog->show();
}

void DeleteDialog::on_pushButtonLoad_clicked()
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


void DeleteDialog::on_pushButtonDelete_clicked()
{
    MainWindow main;
    if(!main.connOpen()){
        QMessageBox::critical(this,tr("Connection error"),tr("Failed to connect to database"));
        return;
    }
    QString loginToDelete = ui->lineEditLogin->text();
    QSqlQuery query;
    query.prepare("delete from employees where login=:login");
    query.bindValue(":login",loginToDelete);
    if(!query.exec()){
        QMessageBox::critical(this,tr("Error"),tr("Geting values error"));
    }
    else{
        QMessageBox::information(this,tr("Result"),tr("User deleted"));
    }
    main.connClose();
}

void DeleteDialog::on_lineEditLogin_editingFinished()
{
    MainWindow main;
    if(!main.connOpen()){
        QMessageBox::critical(this,tr("Connection error"),tr("Failed to connect to database"));
        return;
    }
    QString log= ui->lineEditLogin->text();
    QSqlQuery query;
    query.prepare("select name,surname from employees where login=:login");
    query.bindValue(":login",log);
    if(query.exec()){
        query.first();
        ui->lineEditName->setText(query.value(0).toString());
        ui->lineEditSurname->setText(query.value(1).toString());
    }
    else{
        ui->lineEditName->setText("There are no user with this login");
        ui->lineEditSurname->setText("There are no user with this login");
    }
    main.connClose();
}
