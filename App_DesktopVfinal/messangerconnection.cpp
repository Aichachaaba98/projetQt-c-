#include "messangerconnection.h"
#include "ui_messangerconnection.h"
namespace Duartecorporation
{
MessangerConnection::MessangerConnection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MessangerConnection)
{
    ui->setupUi(this);
}

MessangerConnection::~MessangerConnection()
{
    delete ui;
}

void MessangerConnection::on_ok_clicked()
{
mHostname = "localhost";
mport = 3333;
accept();
}

void MessangerConnection::on_cancel_clicked()
{
reject();
}
}
