
#include "aicha_en.h"
#include "ui_aicha_en.h"


#include  "notificationaicha.h"

#include  "produitray.h"
#include <QSqlQueryModel>

aicha_en::aicha_en(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::aicha_en)
{   notificationaicha n;
    ui->setupUi(this);
   // bool *test;
   // *test=false;
    //QSqlQueryModel * q;

   /*q->pr.alertedate();
    if (*test==true)*/
    n.notificationaicha_dateexp();
    music->setMedia(QUrl("C:/Users/HP ENVY/Documents/50 Cent - In Da Club (Int'l Version).mp3"));
    music->play();
     ui->comboBox_9->setModel(pr.modeltype());
     ui->comboBox_3->setModel(pr.modelrefpr());
      ui->comboBox_4->setModel(pr.modelrefray());
     connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
     connect(ui->exitBtn, SIGNAL(clicked()),this, SLOT(close()));
     ui->tableView_2->setModel(pr.alerteqt());
     ui->tableView_3->setModel(pr.alertedate());
}


aicha_en::~aicha_en()
{
    delete ui;
}


bool aicha_en::verif_nom(QString nom){
    bool test=true;
    int i;
        for(i=0;i<nom.length();i++){
            if(!(((nom[i]>='A')&&(nom[i]<='Z'))||((nom[i]>='a')&&(nom[i]<='z')))){
                test=false;
                return  test;


    }
  }
    return  test;
}



void aicha_en::initialiser()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();

    ui->lineEdit_23->clear();
    ui->refedit_5->clear();

    ui->lineEdit_7->clear();
    ui->lineEdit_12->clear();
}
void aicha_en::on_horizontalSlider_sliderMoved(int position)
{
   int volume=position;
    music->setVolume(volume);
}

void aicha_en::on_pushButton_clicked()
{
     music->play();
}

void aicha_en::on_pushButton_2_clicked()
{
    music->pause();
}

void aicha_en::on_comboBox_3_activated(const QString &arg1)
{
    pr.set_ref(arg1.toInt());
}


void aicha_en::on_pushButton_23_clicked()
{
    int refrayon = ui->lineEdit_7->text().toInt();
    ui->taberayon->setModel(tmprayon.chercher(refrayon));

    // ui->tableView->reset();


    //ui->tableView->setModel(tmprayon.chercher3(collect));
        QMessageBox::information(nullptr, QObject::tr("recherche un rayon"),
                          QObject::tr("rayon recherche.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
       // ui->tableView->setModel(tmprayon.afficher())
initialiser();
}

void aicha_en::on_radioButton_23_clicked()
{
    ui->taberayon->setModel(tmprayon.afficher());
}

void aicha_en::on_pushButton_24_clicked()
{
    int refemploye = ui->lineEdit_12->text().toInt();
    ui->taberayon->setModel(tmprayon.chercher2(refemploye));
}

void aicha_en::on_radioButton_9_clicked()
{
    ui->taberayon->setModel(tmprayon.triertype());
}

void aicha_en::on_radioButton_11_clicked()
{
    ui->taberayon->setModel(tmprayon.trierrefrayon());
}

void aicha_en::on_radioButton_10_clicked()
{
    ui->taberayon->setModel(tmprayon.trierrefemploye());
}

void aicha_en::on_comboBox_2_activated(const QString &arg1)
{
    collect=arg1;
}

void aicha_en::on_pushButton_8_clicked()
{
     ui->taberayon->setModel(tmprayon.chercher3(collect));
}

void aicha_en::on_modifier_rayon_clicked()
{
    int  refrayon = ui->lineEdit_11->text().toInt();
    QString type = ui->lineEdit_13->text();
     int refemploye  = ui->lineEdit_14->text().toInt();


    if(tmprayon.rech(refrayon)){
        bool test = tmprayon.modifier(refrayon,type,refemploye);
        if(test){
            //ui->tabpersonnel->setModel(tmppersonnel.afficher());
            QMessageBox::information(nullptr,QObject::tr("Personnel modifier"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
            ui->taberayon->setModel(tmprayon.afficher());
        }
    }initialiser();
}

void aicha_en::on_supprimer_rayon_clicked()
{
    int refrayon = ui->supprimer_rayon->text().toInt();
    bool test= tmprayon.supprimer(refrayon);
    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("supprimer un rayon"),
                          QObject::tr("rayon supprimer.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
        ui->taberayon->setModel(tmprayon.afficher());
    }initialiser();
}

void aicha_en::on_ok_clicked()
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

}initialiser();
}

void aicha_en::on_pushButton_3_clicked()
{


    QString nom;


      // ref = ui->refedit_4->text().toInt();
       nom = ui->refedit_5->text();
      // refray= ui->refrayedit->text().toInt();

       if(verif_nom(nom)==true){


        // pr.set_ref(ref);
         pr.set_nom(nom);
         //pr.set_refray(refray);

      if((pr.ajouter())&&(verif_nom(nom)))
    {
    QMessageBox::information(nullptr, QObject::tr("Ajout"),
                      QObject::tr("rayon ajouté.\n"
                                  "Click Ok to exit."), QMessageBox::Ok);
    ui->tableView_2->setModel(pr.alerteqt());
    ui->tableView->setModel(pr.afficher());
    ui->tableView_3->setModel(pr.alertedate());
}
    }
      else{
          QMessageBox::critical(nullptr, QObject::tr("Ajout"),
                      QObject::tr("Erreur !\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
    }initialiser();
}

void aicha_en::on_comboBox_activated(const QString &arg1)
{
    pr.set_type(arg1);
}

void aicha_en::on_dateEdit_userDateChanged(const QDate &date)
{
     pr.set_date(date);
}

void aicha_en::on_spinBox_valueChanged(const QString &arg1)
{
    pr.set_qtray(arg1.toInt());
}



void aicha_en::on_spinBox_2_valueChanged(const QString &arg1)
{
    pr.set_solde(arg1.toInt());
}

void aicha_en::on_radioButton_5_clicked()
{
    ui->tableView->setModel(pr.afficher());
}

void aicha_en::on_radioButton_6_clicked()
{
    ui->tableView->setModel(pr.triernom());
}

void aicha_en::on_radioButton_7_clicked()
{
     ui->tableView->setModel(pr.trierqt());
}

void aicha_en::on_radioButton_8_clicked()
{
    ui->tableView->setModel(pr.trierdate());
}

void aicha_en::on_pushButton_4_clicked()
{
    int refrayon= ui->lineEdit->text().toInt();
        ui->tableView->setModel(pr.chercher(refrayon));
}

void aicha_en::on_pushButton_5_clicked()
{
    QString nom= ui->lineEdit_2->text();
   if (verif_nom(nom))
   { ui->tableView->setModel(pr.chercher1(nom));}
   else {QMessageBox::critical(nullptr, QObject::tr("Recherche"),
                               QObject::tr("Erreur !\n"
                                           "Saisir un nom!"), QMessageBox::Cancel);}initialiser();
}

void aicha_en::on_pushButton_6_clicked()
{
    ui->tableView->setModel(pr.chercher2(pr.get_type()));
}

void aicha_en::on_comboBox_8_activated(const QString &arg1)
{
    pr.set_type(arg1);
}

void aicha_en::on_pushButton_22_clicked()
{
    int  ref = ui->refedit_9->text().toInt();
    QString nom = ui->refedit_10->text();
     int refrayon  = ui->refrayedit_3->text().toInt();


    if((pr.rech(ref))&&(verif_nom(nom))){
        bool test = pr.modifier(ref,nom,type,refrayon,qt,date1,solde);
        if(test){

            QMessageBox::information(nullptr,QObject::tr("produit modifié"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
            ui->tableView->setModel(pr.afficher());
            ui->tableView_2->setModel(pr.alerteqt());
            ui->tableView_3->setModel(pr.alertedate());
        }
        else {QMessageBox::information(nullptr,QObject::tr("IMPOSSIBLE"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);}
    }initialiser();
}

void aicha_en::on_comboBox_9_activated(const QString &arg1)
{
    type=arg1;
}

void aicha_en::on_dateEdit_3_userDateChanged(const QDate &date)
{
    date1=date;
}
void aicha_en::on_spinBox_5_valueChanged(const QString &arg1)
{
    qt=arg1.toInt();
}

void aicha_en::on_spinBox_6_valueChanged(const QString &arg1)
{
    solde=arg1.toInt();
}



void aicha_en::on_refedit_9_textChanged(const QString &arg1)
{
    QString code = QString::number(arg1.toInt());
       QSqlQuery query;
       query.prepare("select * from produitray where refproduit='"+code+"'");
       query.exec();
       while(query.next())
       {
           ui->refedit_10->setText(query.value(1).toString());
           //ui->comboBox->setCurrentText(query.value(2));
           ui->refrayedit_3->setText(query.value(3).toString());
          // ui->quantite_m->setText(query.value(5).toString());
       }
}

void aicha_en::on_pushButton_27_clicked()
{
    int ref = ui->lineEdit_23->text().toInt();
    bool test= pr.supprimer(ref);
    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("suppression"),
                          QObject::tr("Produit supprimé.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView->setModel(pr.afficher());
        ui->tableView_2->setModel(pr.alerteqt());
        ui->tableView_3->setModel(pr.alertedate());
    }
    else QMessageBox::information(nullptr, QObject::tr("suppression"),
                                  QObject::tr("erreur."), QMessageBox::Cancel);initialiser();
}


void aicha_en::sendMail()
{
    Smtp* smtp = new Smtp(ui->uname->text(), ui->paswd->text(), ui->server->text(), ui->port->text().toUShort());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}

void aicha_en::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}





void aicha_en::on_comboBox_4_activated(const QString &arg1)
{
    pr.set_refray(arg1.toInt());
}
