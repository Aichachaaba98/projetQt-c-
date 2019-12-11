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
#include "gestion_des_employe.h"
#include "badis.h"

login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
    QPropertyAnimation *animationConnect = new QPropertyAnimation(ui->name,"geometry");
    animationConnect->setDuration(5000);
        animationConnect->setStartValue(QRect(-100,-100,40,40));
        animationConnect->setEndValue(QRect(70,110,700,150));
        animationConnect->start();
        QPropertyAnimation *animationConnect1 = new QPropertyAnimation(ui->session,("geometry"));
        animationConnect1->setDuration(5000);
            animationConnect1->setStartValue(QRect(200,604,40,40));
            animationConnect1->setEndValue(QRect(240,420,700,150));
            animationConnect1->start();
    QPixmap pix("C:/Users/Ben Moussa/Desktop/Projet 2A/CRUD_YaCine/affiche.jpg");
    ui->background2_2->setPixmap(pix);
    ui->statusbar->addPermanentWidget(ui->etat,3);
    ui->statusbar->addPermanentWidget(ui->progressBar,1);
    ui->progressBar->setValue(0);
   // ui->background->setWindowOpacity(0.5);



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
    QString identifiant = ui->id_edit->text();
    QString mdp = ui->mdp_edit->text();
    QString poste=ui->comboBox->currentText();
    produit p;
    set_test(p.verif_login(identifiant,mdp));

 qDebug () << "test:::::::" << test;
    if (test==2){

       gestion_des_employe p;
       p.exec();
        ui->etat->setText("identifiant et mot de passe correctes");
        ui->progressBar->setValue(100);
    }
    else if (test==1){
        QPixmap pixmap("C:/Users/Ben Moussa/Documents/App_DesktopV0/App_DesktopV0/IMG_0106.jpg");
        QSplashScreen splash(pixmap, Qt::WindowStaysOnTopHint);
        splash.show();
        QTimer t;
        t.singleShot(2500, &splash, &QWidget::close);

       Gestion_produits p1;
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
    else if (test==6){

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
