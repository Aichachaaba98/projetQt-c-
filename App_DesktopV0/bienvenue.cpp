#include "bienvenue.h"
#include "ui_bienvenue.h"
#include <QPixmap>
#include "produit.h"
#include "login.h"
#include "produit.h"
#include "parkingint.h"
#include "mainwindow.h"
#include "aicha.h"
#include "gestion_reclamation.h"
#include "gestion_produits.h"
#include "gestion_des_employe.h"
bienvenue::bienvenue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bienvenue)
{
    ui->setupUi(this);
    login l;
    Gestion_produits gp;

    QObject::connect(&l,&login::testSignal,this,&bienvenue::bienvenueYassine);
    ui->progressBar->setValue(0);
    QPixmap pix("C:/Users/Ben Moussa/Desktop/Projet 2A/App_DesktopV0/IMG_0133.jpg");
    ui->label->setPixmap(pix);
    ui->label_2->setText("Yassine Ben moussa");
    int i=0;
        ui->progressBar->setValue(i++);
    qDebug () << "test:::::::" << t;
     /*  if (t==2){
          gestion_des_employe p;
          p.exec();
                 }
       else if (t==1){

           for(int i=0;i<100;i=i+4){
               ui->progressBar->setValue(i);
               if(ui->progressBar->value()==100){
          Gestion_produits p1;
          p1.exec();}}

       }
       else if (t==3){

         parkingint p;
         p.exec();

       }
       else if (t==4){

         aicha p;
         p.exec();

       }
       else if (t==5){

           Gestion_reclamation p;
         p.exec();

       }*/
}

bienvenue::~bienvenue()
{
    delete ui;
}

void bienvenue::bienvenueArbi()
{
    gestion_des_employe ge;
ge.exec();
}
void bienvenue::bienvenueYassine()
{
    Gestion_produits gp;
    gp.show();
}
void bienvenue::bienvenueFourat()
{
    Gestion_reclamation gr;
    gr.exec();
}
