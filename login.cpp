#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include <QMainWindow>
 #include <QMessageBox>
login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}


void login::on_pushButton_2_clicked()
{
    QString identifiant = ui->id_edit->text();
    QString mdp = ui->mdp_edit->text();
    //QSound::play("C:/Users/Ben Moussa/Desktop/Projet 2A/App_DesktopV0/y2mate.com - free_no_copyrightclicking_subscribe_button_with_sound_gIeF2xccRbU.mp3");
    if (identifiant == "aicha" && mdp== "aicha"){
      // hide();
        emit Enter();
      // MainWindow w;
       //w.show();
        //ui->etat->setText("identifiant et mot de passe correctes");
        //ui->progressBar->setValue(100);
    }
    else{
        //ui->etat->setText("identifiant et mot de passe incorrectes");
        QMessageBox::information(this,"Warning","Mot de passe ou identifiant incorrectes");
    }
}
