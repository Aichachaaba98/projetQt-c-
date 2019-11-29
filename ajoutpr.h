#ifndef AJOUTPR_H
#define AJOUTPR_H

#include <QDialog>
#include "produitray.h"

namespace Ui {
class ajoutpr;
}

class ajoutpr : public QDialog
{
    Q_OBJECT

public:
    explicit ajoutpr(QWidget *parent = nullptr);
    ~ajoutpr();

private slots:
    void on_ok_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_dateEdit_userDateChanged(const QDate &date);

    void on_spinBox_valueChanged(const QString &arg1);

    void on_doubleSpinBox_valueChanged(const QString &arg1);

    void on_spinBox_2_valueChanged(const QString &arg1);

private:
    Ui::ajoutpr *ui;
    produitray pr;
};

#endif // AJOUTPR_H
