#ifndef PAIE_H
#define PAIE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class paie
{
public:
    paie();
    paie(QString,int,int);
    QString get_poste();
    int   get_prix_h();
    int get_id_paie();
    bool ajouter_paie(QString poste,int prix_h,int id_paie);
    QSqlQueryModel * afficher_paie();

    bool modifier(int id_paie,int prix_h,QString poste);
    bool supprimer_paie(int id);


private:
    QString poste;
    int prix_h,id_paie;
};

#endif // PAIE_H
