#include "gestion_des_employev2.h"
#include "ui_gestion_des_employev2.h"
#include <QPixmap>
#include "employe.h"
#include"paie.h"
#include <QMessageBox>
#include <QTextDocument>
#include <QTextStream>
#include <QPrintDialog>
#include <QPrinter>
#include"QDate"
#include "statistiques.h"
#include <QDebug>
gestion_des_employe::gestion_des_employe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_des_employe)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/Ben Moussa/Desktop/Projet 2A/CRUD_YaCine/affiche.jpg");
    ui->tabemploye_2->setModel(tmpemploye.afficher());
    ui->tab_paie->setModel(tmppaie.afficher_paie());
   // ui->comboBox->setModel(tmpemploye.afficher_liste());
}

gestion_des_employe::~gestion_des_employe()
{
    delete ui;
}





void gestion_des_employe::on_ajouter_clicked()
{
    int ref = ui->ref_e->text().toInt();
    QString nom= ui->nom_e->text();
    QString prenom= ui->prenom_e->text();
    QString email=ui->email_e->text();
    QString poste =ui->poste_e->text();
    QString sexe =ui->sex_e->text();
  employee E;
  bool test=false;
  int i;
  for(i=0;i<email.size();i++)
  { if((email[i]=="@")&&((sexe=="homme")||(sexe=="femme")))
          test=true;}
   if(test)E.ajouter(ref,nom,prenom,email,poste,sexe);
  if(test)
{ui->tabemploye_2->setModel(tmpemploye.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un employe"),
                  QObject::tr("employe ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

  else
  {
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un employé"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
}
void gestion_des_employe::on_supprimer_clicked()
{
    int id_ch = ui->reference_sup_e->text().toInt();
    bool test=tmpemploye.supprimer(id_ch);
    if(test)
    {ui->tabemploye_2->setModel(tmpemploye.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un employe"),
                    QObject::tr("Employé supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un employe"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
}


void gestion_des_employe::on_pushButton_clicked()
{
    int prix_h  = ui->prix_h_e->text().toInt();
        QString  poste= ui->poste1_e->text();
        int id_paie = ui->id_paie->text().toInt();
      paie E;

      bool test=E.ajouter_paie(poste,prix_h,id_paie);
      if(test)
    {ui->tabemploye_2->setModel(tmpemploye.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Ajouter paie"),
                      QObject::tr("paie ajoutée.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter une paie"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);


}

void gestion_des_employe::on_comboBox_activated(const QString &arg1)
{

}


/*void gestion_des_employe::on_modifier_employe_clicked()
{
    tmpemploye.set_nom(ui->nom_e3->text());
    tmpemploye.set_prenom(ui->prenom_e3->text());
    tmpemploye.set_email(ui->email_e3->text());
    tmpemploye.set_poste(ui->poste_e3->text());
    tmpemploye.set_sext(ui->modifier_sex->text());
    tmpemploye.set_reference(ui->comboBox->currentText().toInt());
    bool test=tmpemploye.modifier();
    if (test){  ui->setupUi(this);
        ui->tabemploye_2->setModel(tmpemploye.afficher());
        ui->comboBox->setModel(tmpemploye.afficher_liste());}
}*/

void gestion_des_employe::on_supprimer_paie_clicked()
{
    int id_ch = ui->id_paie_e->text().toInt();
    bool test=tmppaie.supprimer_paie(id_ch);
    if(test)
    {ui->tab_paie->setModel(tmppaie.afficher_paie());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un employe"),
                    QObject::tr("paie supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un employe"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
}


void gestion_des_employe::on_pushButton_4_clicked()
{
    int id_paie = ui->poste1_e_2->text().toInt();
                int prix_h= ui->prix_h_e_2->text().toInt();
                QString poste = ui->id_paie_2->text();
                paie e ( poste, prix_h,id_paie);
                bool l=e.modifier(id_paie,prix_h,poste);
                if(l)
                {ui->tab_paie->setModel(tmppaie.afficher_paie());//refresh
                    QMessageBox::information(nullptr, QObject::tr("Supprimer un Achat"),
                                QObject::tr("Achat Modifié.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);

                }
                else
                    QMessageBox::critical(nullptr, QObject::tr("Supprimer un étudiant"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
}


void gestion_des_employe::on_modifier_employe_e2_clicked()
{
    int ref = ui->ref_e->text().toInt();
    QString nom= ui->nom_e->text();
    QString prenom= ui->prenom_e->text();
    QString email=ui->email_e->text();
    QString poste =ui->poste_e->text();
    QString sexe =ui->sex_e->text();
  employee E;
  bool test=E.modifier(ref,nom,prenom,email,poste,sexe);
  if(test)
{ui->tabemploye_2->setModel(tmpemploye.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un employe"),
                  QObject::tr("employe modiié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

  else
  {
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un employé"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

}

void gestion_des_employe::on_imprimer_paie_clicked()
{
    QString strStream;
            QTextStream out(&strStream);

            const int rowCount = ui->tab_paie->model()->rowCount();
            const int columnCount = ui->tab_paie->model()->columnCount();
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
                if (!ui->tab_paie->isColumnHidden(column))
                    out << QString("<th>%1</th>").arg(ui->tab_paie->model()->headerData(column, Qt::Horizontal).toString());
            out << "</tr></thead>\n";

            // data table
            for (int row = 0; row < rowCount; row++) {
                out << "<tr>";
                for (int column = 0; column < columnCount; column++) {
                    if (!ui->tab_paie->isColumnHidden(column)) {
                        QString data =ui->tab_paie->model()->data(ui->tab_paie->model()->index(row, column)).toString().simplified();
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

void gestion_des_employe::on_chercher_employe_clicked()
{
    int id = ui->chercher_e->text().toInt();
            ui->afficher_trie->setModel(tmpemploye.recherche_e(id));
qDebug()<<"tri";
}




void gestion_des_employe::on_statistiques_clicked()
{


        statistiques *a=new statistiques();
        a->show();


}
/*void gestion_des_employe::sendMail()
{
    Smtp* smtp = new Smtp(ui->uname->text(), ui->paswd->text(), ui->server->text(), ui->port->text().toUShort());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}
void gestion_des_employe::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}




void gestion_des_employe::on_sendBtn_clicked()
{
    sendMail();
}
*/


void gestion_des_employe::on_pushButton_9_clicked()
{
    ui->tabemploye_2->setModel(tmpemploye.tri(1));
}

void gestion_des_employe::on_pushButton_10_clicked()
{
     ui->tabemploye_2->setModel(tmpemploye.tri(0));
}

void gestion_des_employe::on_pushButton_5_clicked()
{qDebug()<<"tri";

    int id = ui->chercher_e->text().toInt();
            ui->afficher_trie->setModel(tmpemploye.recherche_e(id));
}

void gestion_des_employe::on_chercher_e_textChanged(const QString &arg1)
{int id = arg1.toInt();
    ui->afficher_trie->setModel(tmpemploye.recherche_e(id));


}
