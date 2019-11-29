#include "ajout.h"
#include "ui_ajout.h"

Ajout::Ajout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ajout)
{
    ui->setupUi(this);
}

Ajout::~Ajout()
{
    delete ui;
}
