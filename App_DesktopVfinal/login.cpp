#include "login.h"
#include "ui_login.h"
#include <QPixmap>
#include <QMessageBox>
#include <QSplashScreen>
#include <QtMultimedia/QSound>
#include <QPropertyAnimation>
#include "produit.h"
#include "parkingint.h"
#include "mainwindow.h"
#include "aicha.h"
#include "gestion_reclamation.h"
#include "gestion_produits.h"
#include "gestion_produits_en.h"
#include "gestion_des_employev2.h"
#include "badis.h"
#include "aicha_en.h"
login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
    QPropertyAnimation *animationConnect = new QPropertyAnimation(ui->name,"geometry");
    animationConnect->setDuration(5000);
        animationConnect->setStartValue(QRect(-100,-100,40,40));
        animationConnect->setEndValue(QRect(70,110,650,150));
        animationConnect->start();

    QPixmap pix("C:/Users/Ben Moussa/Desktop/Projet 2A/CRUD_YaCine/affiche.jpg");
    //ui->background2_2->setPixmap(pix);
    ui->statusbar->addPermanentWidget(ui->etat,3);
    ui->statusbar->addPermanentWidget(ui->progressBar,1);
    ui->progressBar->setValue(0);
   // ui->background->setWindowOpacity(0.5);
player->setMedia(QUrl("C:/Users/Ben Moussa/Downloads/Nouvel-enregistrement-15.mp3"));
 player1->setMedia(QUrl("C:/Users/Ben Moussa/Downloads/Nouvel-enregistrement-3.mp3"));
 /* ////////////////////////////////////////////// */
int ret=A.connect_arduino(); // lancer la connexion à arduino
 switch(ret){
 case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
     break;
 case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
    break;
 case(-1):qDebug() << "arduino is not available";
 }

  QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
  //le slot update_label suite à la reception du signal readyRead (reception des données).

}

login::~login()
{
    delete ui;
}

void login::set_test(int test){
this->test=test;
}
void login::on_connecter_clicked()
{
    if(A.getserial()->waitForReadyRead(10))
    data=A.read_from_arduino();
    qDebug() << "data : " << data;

        if(data=="1")
        {carte=100;}
        if(data=="0")
        {carte=200;}
    QString identifiant = ui->id_edit->text();
    QString mdp = ui->mdp_edit->text();
    //QString poste=ui->comboBox->currentText();
    produit p;
    set_test(p.verif_login(identifiant,mdp));

 qDebug () << "test:::::::" << test;
    if (test==2||carte==100){

       gestion_des_employe p;
       p.exec();
        ui->etat->setText("identifiant et mot de passe correctes");
        ui->progressBar->setValue(100);player->play();
    }
    else if ((test==1)&&(langue=="Français")){
        player->play();
        QPixmap pixmap("C:/Users/Ben Moussa/yassine.png");
        QSplashScreen splash(pixmap, Qt::WindowStaysOnTopHint);
        splash.show();
        QTimer t;
        t.singleShot(4000, &splash, &QWidget::close);

       Gestion_produits p1;
       p1.exec();
        ui->etat->setText("identifiant et mot de passe correctes");
        ui->progressBar->setValue(100);

    }
    else if ((test==4)&&(langue=="Français")){
        //QPixmap pixmap("C:/Users/Ben Moussa/yassine.png");
       // QSplashScreen splash(pixmap, Qt::WindowStaysOnTopHint);
     //   splash.show();
        QTimer t;
     //   t.singleShot(2500, &splash, &QWidget::close);

       aicha p1;
       p1.exec();
        ui->etat->setText("identifiant et mot de passe correctes");
        ui->progressBar->setValue(100);player->play();
    }
    else if ((test==1)&&(langue=="English")){
        player1->play();
        QPixmap pixmap("C:/Users/Ben Moussa/yassine.png");
        QSplashScreen splash(pixmap, Qt::WindowStaysOnTopHint);
        splash.show();
        QTimer t;
        t.singleShot(4000, &splash, &QWidget::close);

       gestion_produits_en p1;
       p1.exec();
        ui->etat->setText("identifiant et mot de passe correctes");
        ui->progressBar->setValue(100);
    }
    else if ((test==4)&&(langue=="English")){
       // QPixmap pixmap("C:/Users/Ben Moussa/yassine.png");
       // QSplashScreen splash(pixmap, Qt::WindowStaysOnTopHint);
       // splash.show();
        QTimer t;
       // t.singleShot(2500, &splash, &QWidget::close);

       aicha_en p1;
       p1.exec();
        ui->etat->setText("identifiant et mot de passe correctes");
        ui->progressBar->setValue(100);
    }
    else if (test==3){

      parkingint p;
      p.exec();
        ui->etat->setText("identifiant et mot de passe correctes");
        ui->progressBar->setValue(100);
    }
    else if (test==4){

      aicha p;
      p.exec();
        ui->etat->setText("identifiant et mot de passe correctes");
        ui->progressBar->setValue(100);
    }
    else if (test==5){

        Gestion_reclamation p;
      p.exec();
        ui->etat->setText("identifiant et mot de passe correctes");
        ui->progressBar->setValue(100);
    }
    else if (test==6||carte==200){

        badis p;
      p.exec();
        ui->etat->setText("identifiant et mot de passe correctes");
        ui->progressBar->setValue(100);
    }
    else if(test==0){
        ui->etat->setText("identifiant et mot de passe incorrectes");
        QMessageBox::information(this,"Warning","Mot de passe ou identifiant incorrectes");
    }
}
void login::on_check_mdp_toggled(bool checked)
{

    if(checked){
        ui->mdp_edit->setEchoMode(QLineEdit::Normal);
    }
    else
         ui->mdp_edit->setEchoMode(QLineEdit::Password);
}

void login::on_comboBox_currentTextChanged(const QString &arg1)
{
    poste=arg1;

}

void login::on_comboBox_2_editTextChanged(const QString &arg1)
{
    langue=arg1;
     qDebug () << "langue:::::::" << langue;
}

void login::on_comboBox_2_currentTextChanged(const QString &arg1)
{
    langue=arg1;
     qDebug () << "langue:::::::" << langue;
}
void login::update_label()
{


    if(A.getserial()->waitForReadyRead(10))
data=A.read_from_arduino();
qDebug() << "data : " << data;

    if(data=="1")
    {carte=100;}
    if(data=="0")
    {carte=200;}

}
