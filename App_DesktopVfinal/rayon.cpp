#include "rayon.h"
#include <QDebug>
#include <QSqlRecord>
#include <QSqlTableModel>

Rayon::Rayon()
{
    ref=0;
    type='-';
    refemploye=0;

}
 Rayon::Rayon(int ref,QString type,int refemploye)
 {
     this->ref=ref;
     this->type=type;
     this->refemploye=refemploye;

 }

 bool Rayon::ajouter()
 {
     QSqlQuery query;
         QString res=QString::number(ref);
      query.prepare("INSERT INTO Rayon(refrayon,type,refemploye)Values(AICHA_REFRAYON.nextval,:type,:refemploye)");
    // query.bindValue(":refrayon",res);
     query.bindValue(":type",type);
     query.bindValue(":refemploye",refemploye);
     return  query.exec();

 }

 QSqlQueryModel * Rayon::afficher()
 {
     QSqlQueryModel * model = new QSqlQueryModel();
     model->setQuery("select * from rayon");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("Reference rayon"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("Type"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("Reference employé"));
     return model;
 }

 QSqlQueryModel * Rayon::afficher2(int ref)
 {      QSqlQuery query1;
     QSqlQueryModel * model = new QSqlQueryModel();
     model->setQuery("SELECT * from rayon WHERE refrayon=:ref");
     query1.bindValue(":ref",ref);
        query1.exec();
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("Reference rayon"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("Type"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("Reference employé"));
     return model;
 }

 bool Rayon::supprimer(int refrayon)
 {
QSqlQuery query;
QString res=QString :: number(refrayon);
query.prepare("delete from rayon where refrayon =:refrayon");
query.bindValue(":refrayon",res);
return query.exec();
 }

QSqlQueryModel * Rayon::chercher(int ref)
 {

     QSqlQueryModel * model = new QSqlQueryModel();
     QSqlQuery query;
     query.prepare(QString("select * from rayon WHERE refrayon=:ref"));

     query.bindValue(":ref",ref);

      query.exec();

     //model->setQuery("select type from rayon");
     model->setQuery(query);
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("Reference rayon"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("Type"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("Reference employé"));


return model;
 }

QSqlQueryModel * Rayon::chercher2(int ref)
 {

     QSqlQueryModel * model = new QSqlQueryModel();
     QSqlQuery query;
     query.prepare(QString("select * from rayon WHERE refemploye=:ref"));

     query.bindValue(":ref",ref);

      query.exec();
     model->setQuery(query);
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("Reference rayon"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("Type"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("Reference employé"));


return model;
 }
QSqlQueryModel * Rayon::trierrefrayon()
 { QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare(QString("SELECT * FROM rayon ORDER BY refrayon;"));
    query.exec();
    model->setQuery(query);
    return model;
 }

QSqlQueryModel * Rayon::trierrefemploye()
 { QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare(QString("SELECT * FROM rayon ORDER BY refemploye;"));
    query.exec();
    model->setQuery(query);
    return model;
 }

QSqlQueryModel * Rayon::triertype()
 { QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare(QString("SELECT * FROM rayon ORDER BY type;"));
    query.exec();
    model->setQuery(query);
    return model;
 }

QSqlQueryModel * Rayon::chercher3(QString type)
 {

     QSqlQueryModel * model = new QSqlQueryModel();
     QSqlQuery query;
     query.prepare(QString("select * from rayon WHERE type=:type"));

     query.bindValue(":type",type);

      query.exec();
     model->setQuery(query);
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("Reference rayon"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("Type"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("Reference employé"));


return model;
 }

bool Rayon::modifier(int a,QString b,int c)
{
    QSqlQuery query;
    query.prepare("update rayon set type=:b ,refemploye=:c where refrayon =:a;");
    query.bindValue(":a", a);
    query.bindValue(":b", b);
    query.bindValue(":c", c);
    return query.exec();
}

bool Rayon::rech(int ref){
    QSqlQuery query;
    query.prepare("select * from rayon where refrayon =:ref;");
    query.bindValue(":ref", ref);
    return query.exec();
}
 /*void Rayon::chercher (int ref){

 QSqlQuery query1;


 query1.prepare("SELECT refrayon, type, refemploye FROM rayon WHERE refrayon=:ref");
 query1.bindValue(":ref",ref);
 query1.exec();
 while(query1.next())
 {
  ref = query1.value(0).toInt();
 type = query1.value(1).toString();
  refemploye = query1.value(2).toInt();
 }
 }*/
QString Rayon::retourneQuantite()
{
    QString quantity;
    QSqlQuery query;
    query.prepare("select * from produitray where qt_rayon > 0");
    query.exec();
    while(query.next())
    {
        quantity = query.value(4).toString();
    }
    return quantity;

}




Rayon::~Rayon()
{

}
