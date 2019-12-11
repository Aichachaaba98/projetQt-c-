#include "carte.h"
#include <QString>

carte::carte()
{

}

carte::carte(QString email,int nb_points)
{
    nb_points=0;
    this->email=email;
    this->nb_points=nb_points;
}

QString carte::getemail(){return email;}
int carte::getnb_points(){return nb_points;}

bool carte::ajoutercarte()
{
    QSqlQuery query;
    QString res=QString::number(nb_points);
    query.prepare("INSERT INTO carte_fid(EMAIL,NB_POINTS)"
                  "VALUES (:email,:nb_points)");

    query.bindValue(":email",email);
    query.bindValue(":nb_points",res);

    return query.exec();
}

bool carte::modifiercarte(QString email,int nb_points)
{
    QSqlQuery query;
    QString res=QString::number(nb_points);
    query.prepare(" UPDATE CARTE_FID set NB_POINTS=:nb_points where EMAIL=:email");
    query.bindValue(":email",email);
    query.bindValue(":nb_points",res);
    return query.exec();
}

QSqlQueryModel *carte:: affichercarte()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select *from CARTE_FID");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("EMAIL"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NB_POINTS"));

    return model;
}

bool carte:: supprimercarte(QString email)
{
    QSqlQuery query;

    query.prepare("Delete from CARTE_FID where EMAIL=:email");
    query.bindValue(":email",email);

    return query.exec();
}

QSqlQueryModel *carte::getMailModel()

{
    QSqlQuery *query=new QSqlQuery();
    QSqlQueryModel *model=new QSqlQueryModel();
    query->prepare("select email from CARTE_FID;");
    query->exec();
    model->setQuery(*query);
    return model;
}

bool carte::ajouterpoints(QString email)
{
    QSqlQuery query,query2;
    int nbpoints;
    query2.prepare("select nb_points from carte_fid where email = : email");
    query2.bindValue(":email",email);
    query2.exec();
    nbpoints = query2.value(1).toInt();
    nbpoints++;
    query.prepare("update carte_fid set nb_points=:nbpoints , where email = :email ");
    query.bindValue(":email",email);
    query.bindValue(":nbpoints",nbpoints);
    query.exec();
}

QSqlQueryModel * carte::afficher_tri_nbpoints()
{
    QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from carte order by nb_points");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("EMAIL"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("NB_POINTS"));
return model;
}

QSqlQueryModel * carte::chercher_carte_email(QString nom)
{

    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    nom='%'+nom+'%';
    query.prepare(" select * from carte where email like :email order by email ");
    query.bindValue(":nom",nom);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("EMAIL"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NB_POINTS"));
        return model;

}

