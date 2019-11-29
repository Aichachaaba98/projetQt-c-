#include "modifierprod.h"
#include "ui_modifierprod.h"
#include <QSqlQueryModel>
#include <QMessageBox>
#include <produitray.h>

modifierprod::modifierprod(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifierprod)
{

    ui->setupUi(this);
     ui->comboBox->setModel(pr.modeltype());
}

modifierprod::~modifierprod()
{
    delete ui;
}

void modifierprod::on_ok_clicked()
{
    int  ref = ui->refedit->text().toInt();
    QString nom = ui->refedit_2->text();
     int refrayon  = ui->refrayedit->text().toInt();


    if(pr.rech(ref)){
        bool test = pr.modifier(ref,nom,type,refrayon,qt,date1,solde);
        if(test){

            QMessageBox::information(nullptr,QObject::tr("produit modifié"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
        }
        else {QMessageBox::information(nullptr,QObject::tr("IMPOSSIBLE"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);}
    }
}

void modifierprod::on_comboBox_activated(const QString &arg1)
{
    type=arg1;
}

void modifierprod::on_dateEdit_userDateChanged(const QDate &date)
{
  date1=date;
}

void modifierprod::on_spinBox_valueChanged(const QString &arg1)
{
    qt=arg1.toInt();
}

void modifierprod::on_spinBox_2_valueChanged(const QString &arg1)
{
   solde=arg1.toInt();
}

/*void modifierprod::on_comboBox_currentIndexChanged(const QString &arg1)
{
     QString code = QString::number(arg1.toInt());
        QSqlQuery query;
        query.prepare("select * from produitray where refrayon='"+code+"'");
        query.exec();
        while(query.next())
        {
            ui->nom_m->setText(query.value(1).toString());
            ui->type_m->setText(query.value(2).toString());
            ui->pays_m->setText(query.value(4).toString());
            ui->quantite_m->setText(query.value(5).toString());
        }
}*/

void modifierprod::on_refedit_textChanged(const QString &arg1)
{
    QString code = QString::number(arg1.toInt());
       QSqlQuery query;
       query.prepare("select * from produitray where refproduit='"+code+"'");
       query.exec();
       while(query.next())
       {
           ui->refedit_2->setText(query.value(1).toString());
           //ui->comboBox->setCurrentText(query.value(2));
           ui->refrayedit->setText(query.value(3).toString());
          // ui->quantite_m->setText(query.value(5).toString());
       }
}
