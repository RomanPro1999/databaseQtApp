#ifndef ADMINDIALOG_H
#define ADMINDIALOG_H

#include <QDialog>
#include "mainwindow.h"
#include <QSqlQueryModel>
#include "adddialog.h"
#include "deletedialog.h"
#include "editdialog.h"

namespace Ui {
class AdminDialog;
}

class AdminDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AdminDialog(QWidget *parent = 0);
    ~AdminDialog();

private slots:
    void on_pushButtonLoadData_clicked();

    void on_pushButtonLogOut_clicked();

    void on_pushButtonAddEmployee_clicked();

    void on_pushButtonDeleteEmployee_clicked();

    void on_pushButton_clicked();

private:
    Ui::AdminDialog *ui;
};

#endif // ADMINDIALOG_H
