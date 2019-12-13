#include "messanger.h"
#include "ui_messanger.h"
#include "messangerconnection.h"
#include <QTcpSocket>
#include <QTextStream>
namespace Duartecorporation
{
messanger::messanger(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::messanger)
{
    ui->setupUi(this);
    mSocket = new QTcpSocket(this);
    connect(mSocket,&QTcpSocket::readyRead , [&]() {
QTextStream T(mSocket);
auto text = T.readAll();
ui->textEdit->append(text);
    });
}

messanger::~messanger()
{
    delete ui;
}
void messanger::on_send_clicked()
{
QTextStream T (mSocket);
T << ui->nickname->text() << ": " << ui->message->text();
mSocket->flush();
ui->message->clear();
}

void messanger::on_connect_clicked()
{
    MessangerConnection d(this);
    if (d.exec() == QDialog::Rejected)
    {
        return;
    }


    mSocket->connectToHost(d.hostname(),d.port());


}

}
