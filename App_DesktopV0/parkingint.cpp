#include "parkingint.h"
#include "ui_parkingint.h"
#include"abonne.h"
#include <QMessageBox>
#include "place.h"
#include "statamira.h"
#include <QSqlQueryModel>
#include <QTextDocument>
#include <QTextStream>
#include <QPrintDialog>
#include <QPrinter>
#include"QDate"

parkingint::parkingint(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::parkingint)
{
    ui->setupUi(this);
    ui->tabAbonne->setModel(tmpabonne.afficher());
    ui->tab_place->setModel(tmpplace.afficherp());
}

parkingint::~parkingint()
{
    delete ui;
}

void parkingint::on_pb_ajouter_clicked()
{

    QString email= ui->lineEdit_email->text();
    int id = ui->lineEdit_id->text().toInt();
    int hentre = ui->lineEdit_heure_entree->text().toInt();
    int hsortie  = ui->lineEdit_heure_sortie->text().toInt();
    abonne e(email,id,hentre,hsortie);
    bool test=false;
    int i;
    for(i=0;i<email.size();i++)
    {if(email[i]=="@")
    test=true;}
    if(test)
    {e.ajouter();}
    if(test)
    {ui->tabAbonne->setModel(tmpabonne.afficher());
        QMessageBox::information(nullptr, QObject::tr("Ajouter un abonne"),
                                 QObject::tr("abonne ajouté.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un abonne"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}

void parkingint::on_pb_supprimer_clicked()
{
    QString mail=ui->lineEdit_id_2->text();
    bool test=tmpabonne.supprimer(mail);
    if(test)
    {ui->tabAbonne->setModel(tmpabonne.afficher());
        QMessageBox::information(nullptr, QObject::tr("supprimer un abonne"),
                                 QObject::tr("abonne supprimer.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);}
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un abonne"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}

void parkingint::on_pushButton_clicked()
{
    QString email=ui->lineEdit_email->text();
    int id=ui->lineEdit_id->text().toInt();
    int hentre=ui->lineEdit_heure_entree->text().toInt();
    int hsortie=ui->lineEdit_heure_sortie->text().toInt();
    abonne a;
    bool atout=a.modifier(email,id,hentre,hsortie);
    if(atout)
    {ui->tabAbonne->setModel(tmpabonne.afficher());
        QMessageBox::information(nullptr, QObject::tr("modifier un abonne"),
                                 QObject::tr("abonne modifié.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);}
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier un abonne"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);


}

void parkingint::on_pushButton_ajouter_clicked()
{
    int id = ui->lineEdit_id2->text().toInt();
    int nb_place = ui->lineEdit_pnbplace->text().toInt();
    int nb_voiture  = ui->lineEdit_nbvoiture->text().toInt();
    float tarif = ui->lineEdit_tarif->text().toFloat();
    place p(id,nb_place,nb_voiture,tarif);
    bool test=false;
    if(id>0)
    {test=true;}
    if (test)
    {p.ajouterp();}
    if(test)
    {
        ui->tab_place->setModel(tmpplace.afficherp());

        QMessageBox::information(nullptr, QObject::tr("Ajouter une place"),
                                 QObject::tr("place ajouté.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter une place"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}

void parkingint::on_pushButton_2_clicked()
{
    int id=ui->lineEdit_idd->text().toInt();
    bool test=tmpplace.supprimerp(id);
    if(test)
    {ui->tab_place->setModel(tmpplace.afficherp());
        QMessageBox::information(nullptr, QObject::tr("supprimer une place"),
                                 QObject::tr("place supprimer.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);}
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une place"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}

void parkingint::on_pushButton_modifier_clicked()
{
    int id=ui->lineEdit_id2->text().toInt();
    int nb_place=ui->lineEdit_pnbplace->text().toInt();
    int nb_voiture=ui->lineEdit_nbvoiture->text().toInt();
    float tarif=ui->lineEdit_tarif->text().toFloat();
    place p;
    bool atout=p.modifierp(id,nb_place,nb_voiture,tarif);
    if(atout)
    {ui->tab_place->setModel(tmpplace.afficherp());
        QMessageBox::information(nullptr, QObject::tr("modifier une place"),
                                 QObject::tr("place modifié.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);}
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier une place"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}









void parkingint::on_pushButton_3_clicked()
{
    int id=ui->chercher->text().toInt();

    ui->tab_place->setModel(tmpplace.chercher(id));

}

void parkingint::on_stat_clicked()
{
    statamira *a=new statamira();
    a->show();
}




void parkingint::on_pushButton_4_clicked()
{
    int id=ui->lineEdit_chercher->text().toInt();

    ui->tabAbonne->setModel(tmpabonne.cherchera(id));
}


void parkingint::on_pushButton_5_clicked()
{
   ui->tab_place->setModel(tmpplace.trie(0));
}

void parkingint::on_pushButton_6_clicked()
{
     ui->tab_place->setModel(tmpplace.trie(1));
}

void parkingint::on_pushButton_7_clicked()
{
    ui->tabAbonne->setModel(tmpabonne.triea(0));
}

void parkingint::on_pushButton_8_clicked()
{
    ui->tabAbonne->setModel(tmpabonne.triea(2));
}

void parkingint::on_pushButton_9_clicked()
{
     ui->tab_place->setModel(tmpplace.afficherp());
}

void parkingint::on_pushButton_10_clicked()
{
     ui->tabAbonne->setModel(tmpabonne.afficher());
}

void parkingint::on_pushButton_11_clicked()
{
    QString strStream;
                QTextStream out(&strStream);

                const int rowCount = ui->tabAbonne->model()->rowCount();
                const int columnCount = ui->tabAbonne->model()->columnCount();
                QString TT = QDate::currentDate().toString("yyyy/MM/dd");
                out <<"<html>\n"
                      "<head>\n"
                       "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                    << "<title>ERP - COMmANDE LIST<title>\n "
                    << "</head>\n"
                    "<body bgcolor=#ffffff link=#5000A0>\n"
                    "<h1 style=\"text-align: center;\"><strong> *****LISTE DES Factures ***** "+TT+"</strong></h1>"
                    "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                      "</br> </br>";
                // headers
                out << "<thead><tr bgcolor=#d6e5ff>";
                for (int column = 0; column < columnCount; column++)
                    if (!ui->tabAbonne->isColumnHidden(column))
                        out << QString("<th>%1</th>").arg(ui->tabAbonne->model()->headerData(column, Qt::Horizontal).toString());
                out << "</tr></thead>\n";

                // data table
                for (int row = 0; row < rowCount; row++) {
                    out << "<tr>";
                    for (int column = 0; column < columnCount; column++) {
                        if (!ui->tabAbonne->isColumnHidden(column)) {
                            QString data =ui->tabAbonne->model()->data(ui->tabAbonne->model()->index(row, column)).toString().simplified();
                            out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                        }
                    }
                    out << "</tr>\n";
                }
                out <<  "</table>\n"
                    "</body>\n"
                    "</html>\n";

                QTextDocument *document = new QTextDocument();
                document->setHtml(strStream);

                QPrinter printer;

                QPrintDialog *baba = new QPrintDialog(&printer, NULL);
                if (baba->exec() == QDialog::Accepted) {
                    document->print(&printer);
                }

                delete document;

}
