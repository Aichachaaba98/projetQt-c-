#include "produitray.h"



produitray::produitray()
{

}





produitray::~produitray()
{

}

bool produitray::ajouter()
{
    QSqlQuery query;
    QString res=QString::number(ref);
    //QString res2=QString::number(refray);
    //QString qt=QString::number(qtray);
    //QString sol;
    //sol.setNum(solde);
     query.prepare("INSERT INTO produitray (refproduit,nom,type,refrayon,qt_rayon,date_exp,solde)Values(:refproduit,:nom,:type,:refrayon,:qt_rayon,:date_exp,:solde)");
    query.bindValue(":refproduit",res);
     query.bindValue(":nom",nom);
    query.bindValue(":type",type);
     query.bindValue(":refrayon",refray);
      query.bindValue(":qt_rayon",qtray);
     query.bindValue(":date_exp",date_exp);
     query.bindValue(":solde",solde);
    return  query.exec();
}
QSqlQueryModel * produitray::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from produitray");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Reference produit"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Type"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Reference rayon"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Quantite"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Date d'expiration"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Solde"));
    return model;
}


QSqlQueryModel * produitray::chercher(int refray)
 {
      QSqlQueryModel * model = new QSqlQueryModel();
     QSqlQuery query;
     query.prepare(QString("select * from produitray WHERE refrayon=:refray"));

     query.bindValue(":refray",refray);
     query.exec();
     model->setQuery(query);

      model->setHeaderData(0,Qt::Horizontal,QObject::tr("Reference produit"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("Type"));
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("Reference rayon"));
      model->setHeaderData(4,Qt::Horizontal,QObject::tr("Quantite"));
      model->setHeaderData(5,Qt::Horizontal,QObject::tr("Date d'expiration"));
      model->setHeaderData(6,Qt::Horizontal,QObject::tr("Solde"));
return model;
 }


QSqlQueryModel * produitray::chercher1(QString nom)
 {
      QSqlQueryModel * model = new QSqlQueryModel();
     QSqlQuery query;
     query.prepare(QString("select * from produitray WHERE nom=:nom"));

     query.bindValue(":nom",nom);
     query.exec();
     model->setQuery(query);

      model->setHeaderData(0,Qt::Horizontal,QObject::tr("Reference produit"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("Type"));
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("Reference rayon"));
      model->setHeaderData(4,Qt::Horizontal,QObject::tr("Quantite"));
      model->setHeaderData(5,Qt::Horizontal,QObject::tr("Date d'expiration"));
      model->setHeaderData(6,Qt::Horizontal,QObject::tr("Solde"));
return model;
 }

QSqlQueryModel * produitray::chercher2(QString type)
 {
      QSqlQueryModel * model = new QSqlQueryModel();
     QSqlQuery query;
     query.prepare(QString("select * from produitray WHERE type=:type"));

     query.bindValue(":type",type);
     query.exec();
     model->setQuery(query);

      model->setHeaderData(0,Qt::Horizontal,QObject::tr("Reference produit"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("Type"));
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("Reference rayon"));
      model->setHeaderData(4,Qt::Horizontal,QObject::tr("Quantite"));
      model->setHeaderData(5,Qt::Horizontal,QObject::tr("Date d'expiration"));
      model->setHeaderData(6,Qt::Horizontal,QObject::tr("Solde"));
return model;
 }


QSqlQueryModel * produitray::triernom()
 { QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare(QString("SELECT * FROM produitray ORDER BY nom;"));
    query.exec();
    model->setQuery(query);
    return model;
 }

QSqlQueryModel * produitray::trierqt()
 { QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare(QString("SELECT * FROM produitray ORDER BY qt_rayon;"));
    query.exec();
    model->setQuery(query);
    return model;
 }

QSqlQueryModel * produitray::trierdate()
 { QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare(QString("SELECT * FROM produitray ORDER BY date_exp;"));
    query.exec();
    model->setQuery(query);
    return model;
 }

bool produitray::supprimer(int ref)
{
QSqlQuery query;
QString res=QString :: number(ref);
query.prepare("delete from PRODUITRAY where REFPRODUIT=:ref");
query.bindValue(":ref",res);
return query.exec();
}


bool produitray::modifier(int ref,QString nom, QString type, int refrayon, int qt, QDate date, int solde)
{
    QSqlQuery query;
    query.prepare("update produitray set  nom=:nom, type=:type, refrayon=:refrayon, qt_rayon=:qt, date_exp=:date, solde=:solde where refproduit =:ref;");
     query.bindValue(":ref",ref);
    query.bindValue(":nom",nom);
    query.bindValue(":type",type);
    query.bindValue(":refrayon", refrayon);
    query.bindValue(":qt", qt);
    query.bindValue(":date",date);
    query.bindValue(":solde",solde);

    return query.exec();
}

bool produitray::rech(int ref){
    QSqlQuery query;
    query.prepare("select * from produitray where refproduit =:ref;");
    query.bindValue(":ref", ref);
    return query.exec();
}
QSqlQueryModel * produitray::modeltype()
{
    QSqlQueryModel * model = new QSqlQueryModel;
    QSqlQuery * query= new QSqlQuery();
     query->prepare("select type from rayon");
    query->exec();
    model->setQuery(*query);
    return model;
}

QSqlQueryModel * produitray::alertedate(bool *test)
{QSqlQueryModel * model = new QSqlQueryModel;
 QSqlQuery query;
 query.prepare("select * from produitray where date_exp<= sysdate");
 query.exec();
 *test=query.first();
 model->setQuery(query);

 return model;
}

QSqlQueryModel * produitray::alerteqt()
{QSqlQueryModel * model = new QSqlQueryModel;
 QSqlQuery query;
 query.prepare("select * from produitray where qt_rayon =:qt");
 query.bindValue(":qt",0);
 query.exec();
 model->setQuery(query);

 return model;
}


