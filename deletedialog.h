#ifndef DELETEDIALOG_H
#define DELETEDIALOG_H

#include <QDialog>
#include "mainwindow.h"
#include "adddialog.h"

namespace Ui {
class DeleteDialog;
}

class DeleteDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteDialog(QWidget *parent = 0);
    ~DeleteDialog();

private slots:
    void on_pushButtonCancel_clicked();

    void on_pushButtonLoad_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_pushButtonDelete_clicked();

    void on_lineEditLogin_editingFinished();

private:
    Ui::DeleteDialog *ui;
};

#endif // DELETEDIALOG_H
