#include "pr_commande.h"

pr_commande::pr_commande()
{

}
pr_commande::pr_commande(int refcommande,int refproduit,int quantite)
{
  this->refcommande=refcommande;
  this->refproduit=refproduit;
  this->quantite=quantite;
}
QSqlQueryModel * pr_commande::Modelrefcommande_livs()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery *query = new QSqlQuery();
    query->prepare("select refcommande from commande");
    query->exec();
    model->setQuery(*query);
    return model;
}
QSqlQueryModel * pr_commande::Modelrefproduit()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery *query = new QSqlQuery();
    query->prepare("select refproduit from produit");
    query->exec();
    model->setQuery(*query);
    return model;
}
bool pr_commande::ajouter(){
    QSqlQuery query;
    QString res= QString::number(refcommande),res2= QString::number(refproduit),res3= QString::number(quantite);
    query.prepare("INSERT INTO con_commande (refcommande, refproduit, quantite) VALUES (:refcommande, :refproduit, :quantite)");
    query.bindValue(":refcommande", res);
    query.bindValue(":refproduit", res2);
    query.bindValue(":quantite",res3);
    return query.exec();
}
QSqlQueryModel * pr_commande::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from con_commande");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("refcommande"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("refproduit"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantite"));
    return model;
}
bool pr_commande::supprimer(int ref_ch,int ref_ch1)
{
QSqlQuery query;

query.prepare("Delete from con_commande where refproduit = :ref and refcommande =:refcommande");
query.bindValue(":ref", ref_ch);
query.bindValue(":refcommande", ref_ch1);
return    query.exec();
}
bool pr_commande::rech(int x,int y){
    QSqlQuery query;
    query.prepare("select * from con_commande where REFPRODUIT = :reference and refcommande =:refcommande;");
    query.bindValue(":reference", x);
    query.bindValue(":refcommande", y);
    return query.exec();
}
bool pr_commande::modifier(int a,int b,int c){
    QSqlQuery query;
    QString yep=QString::number(a);
    QString yep1=QString::number(b);
    QString yep2=QString::number(c);
    query.prepare("UPDATE con_commande set quantite=:quantite  where refproduit ='"+yep1+"' and refcommande='"+yep+"' ");
    query.bindValue(":refcommande", a);
    query.bindValue(":refproduit", b);
    query.bindValue(":quantite", c);

    return query.exec();
}
