#include "admindialog.h"
#include "ui_admindialog.h"

AdminDialog::AdminDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminDialog)
{
    ui->setupUi(this);
}

AdminDialog::~AdminDialog()
{
    delete ui;
}

void AdminDialog::on_pushButtonLoadData_clicked()
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

void AdminDialog::on_pushButtonLogOut_clicked()
{
    MainWindow* main=new MainWindow();
    this->close();
    main->show();
}

void AdminDialog::on_pushButtonAddEmployee_clicked()
{
    AddDialog* addDialog =new AddDialog();
    this->close();
    addDialog->show();
}

void AdminDialog::on_pushButtonDeleteEmployee_clicked()
{
    DeleteDialog* deleteDialog =new DeleteDialog();
    this->close();
    deleteDialog->show();
}

void AdminDialog::on_pushButton_clicked()
{
    EditDialog* editDialog =new EditDialog();
    this->close();
    editDialog->show();
}
