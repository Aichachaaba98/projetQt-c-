#include "affichagepr.h"
#include "ui_affichagepr.h"

affichagepr::affichagepr(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::affichagepr)
{
    ui->setupUi(this);
}

affichagepr::~affichagepr()
{
    delete ui;
}

void affichagepr::on_radioButton_4_clicked()
{
     ui->tableView->setModel(pr.afficher());
}

void affichagepr::on_pushButton_3_clicked()
{   int refrayon= ui->lineEdit->text().toInt();
    ui->tableView->setModel(pr.chercher(refrayon));
}

void affichagepr::on_pushButton_4_clicked()
{
    QString nom= ui->lineEdit_2->text();
        ui->tableView->setModel(pr.chercher1(nom));
}



void affichagepr::on_comboBox_activated(const QString &arg1)
{
    pr.set_type(arg1);
}

void affichagepr::on_pushButton_5_clicked()
{
     ui->tableView->setModel(pr.chercher2(pr.get_type()));
}

void affichagepr::on_radioButton_5_clicked()
{
     ui->tableView->setModel(pr.triernom());
}

void affichagepr::on_radioButton_6_clicked()
{
    ui->tableView->setModel(pr.trierqt());
}

void affichagepr::on_radioButton_7_clicked()
{
    ui->tableView->setModel(pr.trierdate());
}
