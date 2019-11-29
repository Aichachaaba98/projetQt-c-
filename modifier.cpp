#include "modifier.h"
#include "ui_modifier.h"
#include <QSqlQueryModel>
#include <QMessageBox>

Modifier::Modifier(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Modifier)
{
    ui->setupUi(this);
}

Modifier::~Modifier()
{
    delete ui;
}

void Modifier::on_pushButton_clicked()
{
        int  refrayon = ui->lineEdit_4->text().toInt();
        QString type = ui->lineEdit_5->text();
         int refemploye  = ui->lineEdit_8->text().toInt();


        if(tmprayon.rech(refrayon)){
            bool test = tmprayon.modifier(refrayon,type,refemploye);
            if(test){
                //ui->tabpersonnel->setModel(tmppersonnel.afficher());
                QMessageBox::information(nullptr,QObject::tr("Personnel modifier"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
            }
        }
}
