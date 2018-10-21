#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>
#include "mainwindow.h"
#include "adddialog.h"

namespace Ui {
class AddDialog;
}

class AddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDialog(QWidget *parent = 0);
    ~AddDialog();

private slots:

    void on_pushButtonCancel_clicked();

    void on_pushButtonSave_clicked();

private:
    Ui::AddDialog *ui;
};

#endif // ADDDIALOG_H




