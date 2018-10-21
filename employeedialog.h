#ifndef EMPLOYEEDIALOG_H
#define EMPLOYEEDIALOG_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class EmployeeDialog;
}

class EmployeeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EmployeeDialog(QWidget *parent = 0);
    ~EmployeeDialog();

private slots:
    void on_pushButtonLogOut_clicked();

    void on_pushButtonLoadData_clicked();

private:
    Ui::EmployeeDialog *ui;
};

#endif // EMPLOYEEDIALOG_H
