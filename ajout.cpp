#include "ajout.h"
#include "ui_ajout.h"
#include "rayon.h"
#include <QMessageBox>

Ajout::Ajout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ajout)
{
    ui->setupUi(this);
}

Ajout::~Ajout()
{
    delete ui;
}



void Ajout::on_ok_clicked()
{


    int ref;
    int refemploye;

    QString type;


   ref = ui->refedit->text().toInt();
     type = ui->typeedit->text();
     refemploye = ui->lineEdit_8->text().toInt();



 // Rayon e(ref,type,refemploye);
     e.set_ref(ref);
     e.set_refemploye(refemploye);
     e.set_type(type);
  //bool test=e.ajouter();
  if(e.ajouter())
{
QMessageBox::information(nullptr, QObject::tr("Ajouter un rayon"),
                  QObject::tr("rayon ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else{
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un rayon"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
}
