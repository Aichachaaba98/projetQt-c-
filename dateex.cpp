#include "dateex.h"
#include "ui_dateex.h"

dateex::dateex(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dateex)
{
    ui->setupUi(this);
   // bool *test;
   /* *test=true;*/
    ui->tableView->setModel(pr.alertedate());
}

dateex::~dateex()
{
    delete ui;
}
