#include "employeedialog.h"
#include "ui_employeedialog.h"

EmployeeDialog::EmployeeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmployeeDialog)
{
    ui->setupUi(this);
}

EmployeeDialog::~EmployeeDialog()
{
    delete ui;
}

void EmployeeDialog::on_pushButtonLogOut_clicked()
{
    MainWindow* main=new MainWindow();
    this->close();
    main->show();
}

void EmployeeDialog::on_pushButtonLoadData_clicked()
{
    MainWindow main;
    QSqlQueryModel* model = new QSqlQueryModel();
    if(!main.connOpen()){
        QMessageBox::critical(this,tr("Connection error"),tr("Failed to connect to database"));
        return;
    }
    QSqlQuery* query = new QSqlQuery(main.mydb);
    query->prepare("select name,surname,major from employees");
    query->exec();
    model->setQuery(*query);
    ui->tableView->setModel(model);
    main.connClose();
}
