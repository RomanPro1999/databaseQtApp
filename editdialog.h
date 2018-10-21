#ifndef EDITDIALOG_H
#define EDITDIALOG_H

#include <QDialog>
#include "mainwindow.h"
#include "adddialog.h"

namespace Ui {
class EditDialog;
}

class EditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditDialog(QWidget *parent = 0);
    ~EditDialog();

private slots:
    void on_pushButtonCancle_clicked();

    void on_pushButton_2_clicked();

    void on_lineEditLogin_editingFinished();

    void on_pushButton_clicked();


    void on_pushButtonFillData_clicked();

private:
    Ui::EditDialog *ui;
};

#endif // EDITDIALOG_H
