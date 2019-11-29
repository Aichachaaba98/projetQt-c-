#include "afficher.h"
#include "ui_afficher.h"
#include "rayon.h"
#include <QSqlQueryModel>
#include <QMessageBox>

AFFICHER::AFFICHER(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AFFICHER)
{
    ui->setupUi(this);
  // ui->tableView->setModel(tmprayon.afficher());


}

AFFICHER::~AFFICHER()
{
    delete ui;
}






void AFFICHER::on_pushButton_2_clicked()
{

    int refrayon = ui->lineEdit->text().toInt();



    ui->tableView->setModel(tmprayon.chercher(refrayon));

    // ui->tableView->reset();


    //ui->tableView->setModel(tmprayon.chercher3(collect));
        QMessageBox::information(nullptr, QObject::tr("recherche un rayon"),
                          QObject::tr("rayon recherche.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
       // ui->tableView->setModel(tmprayon.afficher())



}

void AFFICHER::on_comboBox_activated(const QString &arg1)
{
    collect=arg1;
}




void AFFICHER::on_radioButton_4_clicked()
{    //ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
     //ui->tableView->setSortingEnabled(true);
    // ui->tableView->resizeRowsToContents();
     ui->tableView->setModel(tmprayon.afficher());


}




void AFFICHER::on_radioButton_5_clicked()
{
    ui->tableView->setModel(tmprayon.trierrefrayon());
}

void AFFICHER::on_radioButton_6_clicked()
{
     ui->tableView->setModel(tmprayon.trierrefemploye());
}

void AFFICHER::on_radioButton_7_clicked()
{
    ui->tableView->setModel(tmprayon.triertype());
}

void AFFICHER::on_pushButton_3_clicked()
{
    int refemploye = ui->lineEdit_2->text().toInt();
    ui->tableView->setModel(tmprayon.chercher2(refemploye));

}

void AFFICHER::on_pushButton_4_clicked()
{
     ui->tableView->setModel(tmprayon.chercher3(collect));
}
