#include "suppprod.h"
#include "ui_suppprod.h"
#include "produitray.h"
#include <QMessageBox>

suppprod::suppprod(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::suppprod)
{
    ui->setupUi(this);
}

suppprod::~suppprod()
{
    delete ui;
}

void suppprod::on_pushButton_clicked()
{
    int ref = ui->lineEdit_4->text().toInt();
    bool test= pr.supprimer(ref);
    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("suppression"),
                          QObject::tr("Produit supprimé.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else QMessageBox::information(nullptr, QObject::tr("suppression"),
                                  QObject::tr("erreur."), QMessageBox::Cancel);
}
