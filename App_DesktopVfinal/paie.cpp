#include "paie.h"
#include<QString>
paie::paie()
{
poste ="";
prix_h =0;
id_paie=0;
}
paie::paie(QString poste,int prix_h,int id_paie)
{

    this->poste=poste;
    this->prix_h=prix_h;
    this->id_paie=id_paie;


}
QString paie::get_poste(){return poste;}
int   paie::get_prix_h(){return prix_h;}
int paie::get_id_paie(){return id_paie;}
bool paie::ajouter_paie(QString poste,int prix_h,int id_paie)
{
    {
    QSqlQuery query;
    query.prepare("INSERT INTO paie (poste,prix_h,id_paie) "
                        "VALUES (:poste,:prix_h,:id_paie)");
    query.bindValue(":poste", poste);
    query.bindValue(":prix_h",prix_h);
    query.bindValue(":id_paie",id_paie);

    return    query.exec();
    }
}
QSqlQueryModel * paie::afficher_paie()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from paie");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("poste"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix_h"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("id_paie"));
    return model;
}
bool paie::supprimer_paie(int id_paie)
{


    QSqlQuery query;
        query.prepare("Delete from paie where id_paie=:id_paie");
        query.bindValue(":id_paie",id_paie);
        return query.exec();

}
bool paie::modifier(int id_paie,int prix_h,QString poste)
{
    QSqlQuery query ;


                    query.prepare("update paie set POSTE=:poste,PRIX_H=:prix_h where ID_PAIE=:id_paie");
                    query.bindValue (":poste",poste);
                    query.bindValue (":prix_h",prix_h);
                    query.bindValue(":id_paie",id_paie);
            return  query.exec();

    }


