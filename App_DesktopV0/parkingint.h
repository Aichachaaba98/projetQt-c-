#ifndef parkingint_H
#define parkingint_H
#include"abonne.h"
#include <QDialog>
#include "place.h"
namespace Ui {
class parkingint;
}

class parkingint : public QDialog
{
    Q_OBJECT

public:
    explicit parkingint(QDialog *parent = nullptr);
    ~parkingint();
private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pushButton_clicked();

    void on_pushButton_ajouter_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_modifier_clicked();

    void on_pushButton_3_clicked();


    void on_stat_clicked();


    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();


private:
    Ui::parkingint *ui;
    abonne tmpabonne;
    place tmpplace;

};

#endif // parkingint_H
