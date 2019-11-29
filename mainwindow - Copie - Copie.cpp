#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ajout.h"
#include "afficher.h"
#include "suppression.h"
#include "modifier.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    Ajout A;
    A.setWindowTitle("Ajout");
    A.exec();
}

void MainWindow::on_pushButton_4_clicked()
{
    AFFICHER A;
    A.setWindowTitle("Afficher");
    A.exec();
}

void MainWindow::on_pushButton_5_clicked()
{
    Suppression A;
    A.setWindowTitle("Afficher");
    A.exec();
}

void MainWindow::on_pushButton_6_clicked()
{
    Modifier A;
    A.setWindowTitle("Afficher");
    A.exec();

}
