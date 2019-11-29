#include "suppression.h"
#include "ui_suppression.h"
#include "rayon.h"
#include "afficher.h"
#include "ui_afficher.h"
#include <QMessageBox>

Suppression::Suppression(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Suppression)
{
    ui->setupUi(this);
}

Suppression::~Suppression()
{
    delete ui;
}


void Suppression::on_pushButton_clicked()
{
    int refrayon = ui->lineEdit_4->text().toInt();
    bool test= tmprayon.supprimer(refrayon);
    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("supprimer un rayon"),
                          QObject::tr("rayon supprimer.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
}
