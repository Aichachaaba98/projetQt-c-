#ifndef AFFICHAGEPR_H
#define AFFICHAGEPR_H

#include <QDialog>
#include "produitray.h"


namespace Ui {
class affichagepr;
}

class affichagepr : public QDialog
{
    Q_OBJECT

public:
    explicit affichagepr(QWidget *parent = nullptr);
    ~affichagepr();

private slots:
    void on_radioButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_radioButton_4_toggled(bool checked);

    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_5_clicked();

    void on_radioButton_5_clicked();

    void on_radioButton_6_clicked();

    void on_radioButton_7_clicked();

private:
    Ui::affichagepr *ui;
    produitray pr;
};

#endif // AFFICHAGEPR_H
