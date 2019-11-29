#ifndef MODIFIERPROD_H
#define MODIFIERPROD_H

#include <QDialog>

#include "produitray.h"

namespace Ui {
class modifierprod;
}

class modifierprod : public QDialog
{
    Q_OBJECT

public:
    explicit modifierprod(QWidget *parent = nullptr);
    ~modifierprod();

private slots:
    void on_ok_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_dateEdit_userDateChanged(const QDate &date);

    void on_spinBox_valueChanged(const QString &arg1);

    void on_spinBox_2_valueChanged(const QString &arg1);

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_refedit_textChanged(const QString &arg1);

private:
    Ui::modifierprod *ui;
    produitray pr;
    QString type;
    QDate date1;
    int qt, solde;

};

#endif // MODIFIERPROD_H
