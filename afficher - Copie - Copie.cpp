#include "afficher.h"
#include "ui_afficher.h"

AFFICHER::AFFICHER(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AFFICHER)
{
    ui->setupUi(this);
}

AFFICHER::~AFFICHER()
{
    delete ui;
}
