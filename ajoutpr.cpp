#include "ajoutpr.h"
#include "ui_ajoutpr.h"
#include <QMessageBox>


ajoutpr::ajoutpr(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajoutpr)
{
    ui->setupUi(this);
}

ajoutpr::~ajoutpr()
{
    delete ui;
}



void ajoutpr::on_ok_clicked()
{

    int ref;
    int refray;
    QString nom;


       ref = ui->refedit->text().toInt();
       nom = ui->refedit_2->text();
       refray= ui->refrayedit->text().toInt();


         pr.set_ref(ref);
         pr.set_nom(nom);
         pr.set_refray(refray);

      if(pr.ajouter())
    {
    QMessageBox::information(nullptr, QObject::tr("Ajout"),
                      QObject::tr("rayon ajouté.\n"
                                  "Click Ok to exit."), QMessageBox::Ok);

    }
      else{
          QMessageBox::critical(nullptr, QObject::tr("Ajout"),
                      QObject::tr("Erreur !\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void ajoutpr::on_comboBox_activated(const QString &arg1)
{
    pr.set_type(arg1);
}

void ajoutpr::on_dateEdit_userDateChanged(const QDate &date)
{
    pr.set_date(date);
}

void ajoutpr::on_spinBox_valueChanged(const QString &arg1)
{
    pr.set_qtray(arg1.toInt());
}


void ajoutpr::on_spinBox_2_valueChanged(const QString &arg1)
{
    pr.set_solde(arg1.toInt());
}
