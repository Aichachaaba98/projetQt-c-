
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ajout.h"
#include "afficher.h"
#include "suppression.h"
#include "modifier.h"
#include  "affichagepr.h"
#include  "ajoutpr.h"
#include  "suppprod.h"
#include  "modifierprod.h"
#include  "dateex.h"
#include  "smtpaff.h"
#include  "notification.h"
#include  "alerteqt.h"
#include  "produitray.h"
#include <QSqlQueryModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{   notification n;
    ui->setupUi(this);
    bool *test;
    *test=false;
    //QSqlQueryModel * q;

    pr.alertedate(test);
    if (*test==true)
    n.notification_dateexp();
    
    
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ajouter_clicked()
{
   Ajout A;
    A.setWindowTitle("Ajout");
    A.exec();
}

void MainWindow::on_afficher_clicked()
{
    AFFICHER A;
    A.setWindowTitle("Afficher");
    A.exec();
}

void MainWindow::on_supprimer_clicked()
{
    Suppression A;
    A.setWindowTitle("Afficher");
    A.exec();
}

void MainWindow::on_modifier_clicked()
{
    Modifier A;
    A.setWindowTitle("Afficher");
    A.exec();

}



void MainWindow::on_afficher_2_clicked()
{
    affichagepr A;
    A.setWindowTitle("Affichage");
    A.exec();

}

void MainWindow::on_ajouter_2_clicked()
{
    ajoutpr A;
    A.setWindowTitle("Ajout");
    A.exec();

}

void MainWindow::on_supprimer_2_clicked()
{
    suppprod A;
    A.setWindowTitle("Suppression");
    A.exec();


}

void MainWindow::on_modifier_2_clicked()
{
 modifierprod  A;
 A.setWindowTitle("Modification");
 A.exec();
}

void MainWindow::on_controller_2_clicked()
{
    dateex A;
    A.setWindowTitle("Expiration");
    A.exec();
}

void MainWindow::on_alerte_2_clicked()
{
    smtpaff A;
    A.setWindowTitle("SMTP");
    A.exec();
}

void MainWindow::on_meilleurprod_2_clicked()
{
    alerteqt  A;
    A.setWindowTitle("Alerte");
    A.exec();

}
