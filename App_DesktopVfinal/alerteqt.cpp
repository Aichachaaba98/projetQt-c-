#include "alerteqt.h"


alerteqt::alerteqt(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::alerteqt)
{
    ui->setupUi(this);
    ui->tableView->setModel(pr.alerteqt());
}

alerteqt::~alerteqt()
{
    delete ui;
}
