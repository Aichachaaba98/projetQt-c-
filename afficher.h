#ifndef AFFICHER_H
#define AFFICHER_H
#include "rayon.h"
#include <QDialog>

namespace Ui {
class AFFICHER;
}

class AFFICHER : public QDialog
{
    Q_OBJECT

public:
    explicit AFFICHER(QWidget *parent = nullptr);
    ~AFFICHER();

private slots:
    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


    void on_pushButton_3_clicked();


    void on_comboBox_activated(const QString &arg1);

    void on_radioButton_4_clicked();

    void on_radioButton_4_released();

    void on_radioButton_5_clicked();

    void on_radioButton_6_clicked();

    void on_radioButton_7_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::AFFICHER *ui;
    Rayon tmprayon,tmp;
    QString collect;
};

#endif // AFFICHER_H
