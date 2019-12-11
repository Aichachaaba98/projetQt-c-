#include "client.h"
#include "carte.h"

client::client()
{

}

client::client(QString email, QString nom, QString prenom,int abonne_carte)
{
    this->email=email;
    this->nom=nom;
    this->prenom=prenom;
    this->abonne_carte=abonne_carte;
}

QString client::getemail(){return email;}
QString client::getnom(){return nom;}
QString client::getprenom(){return prenom;}
int client::getabonne_carte(){return abonne_carte;}

bool client::ajouterclient()
{
    QSqlQuery query;
    query.prepare("INSERT INTO client(EMAIL, NOM, PRENOM ,ABONNE_CARTE)"
                  "VALUES (:email, :nom ,:prenom, :abonne_carte )");


    query.bindValue(":email",email);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":abonne_carte",abonne_carte);

    return query.exec();
}

bool client::modifierclient(QString email,QString nom,QString prenom,int abonne_carte)
{
    QSqlQuery query;
    query.prepare(" UPDATE client set NOM=:nom ,PRENOM=:prenom,ABONNE_CARTE=:abonne_carte where EMAIL='"+email+"'");
    //query.bindValue(":email",email);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":abonne_carte",abonne_carte);
    return query.exec();
}

QSqlQueryModel *client:: afficherclient()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select *from client");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("EMAIL"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("ABONNE_CARTE"));


    return model;
}

bool client:: supprimerclient(QString email)
{
    QSqlQuery query;

    query.prepare("delete from client where EMAIL=:email");
    query.bindValue(":email",email);

    return query.exec();
}

QSqlQueryModel *client::getMailModel()
{
    QSqlQuery *query=new QSqlQuery();
    QSqlQueryModel *model=new QSqlQueryModel();
    query->prepare("select email from client;");
    query->exec();
    model->setQuery(*query);
    return model;
}

QSqlQueryModel * client::chercher_client_email(QString nom)
{

    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    nom='%'+nom+'%';
    query.prepare(" select * from client where email like :nom order by email ");
    query.bindValue(":nom",nom);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("EMAIL"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ABONNE_CARTE"));
        return model;

}

QSqlQueryModel * client::chercher_client_nom(QString nom)
{

    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    nom='%'+nom+'%';
    query.prepare(" select * from client where nom like :nom order by nom ");
    query.bindValue(":nom",nom);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("EMAIL"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ABONNE_CARTE"));
        return model;

}

QSqlQueryModel * client::afficher_tri_email()
{
    QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from client order by email");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("EMAIL"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("ABONNE_CARTE"));
return model;
}
