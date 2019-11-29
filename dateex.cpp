#include "dateex.h"
#include "ui_dateex.h"

dateex::dateex(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dateex)
{
    ui->setupUi(this);
    bool *test;
    ui->tableView->setModel(pr.alertedate(test));
}

dateex::~dateex()
{
    delete ui;
}
