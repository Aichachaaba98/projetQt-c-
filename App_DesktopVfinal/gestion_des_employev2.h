#ifndef GESTION_DES_EMPLOYE_H
#define GESTION_DES_EMPLOYE_H

#include <QDialog>
#include "employev2.h"
#include"paie.h"
namespace Ui {
class gestion_des_employe;
}

class gestion_des_employe : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_des_employe(QWidget *parent = nullptr);
    ~gestion_des_employe();

private slots:
    void on_ajouter_clicked();

    void on_supprimer_clicked();



    void on_pushButton_clicked();

    void on_comboBox_activated(const QString &arg1);



    void on_modifier_employe_clicked();


    void on_supprimer_paie_clicked();

    void on_pushButton_4_clicked();


    void on_modifier_employe_e2_clicked();

    void on_imprimer_paie_clicked();



    void on_statistiques_clicked();
    void sendMail();

    void mailSent(QString status);


    void on_sendBtn_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();
    void on_trier_employe_2_clicked();
    void on_pushButton_5_clicked();
    void on_chercher_employe_clicked();

    void on_chercher_e_textChanged(const QString &arg1);

private:
    Ui::gestion_des_employe *ui;
    employee tmpemploye;
    paie tmppaie;

};

#endif // GESTION_DES_EMPLOYE_H
