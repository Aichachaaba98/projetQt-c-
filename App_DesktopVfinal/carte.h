#ifndef PLAT_H
#define PLAT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class carte
{
    int nb_points;
    QString email;
public:
    carte();
    carte(QString email,int nb_points);
    QString getemail();
    int getnb_points ();


    bool ajoutercarte();
    bool modifiercarte(QString,int);
    QSqlQueryModel * affichercarte();
    bool supprimercarte(QString);
    QSqlQueryModel * getMailModel();
    bool ajouterpoints(QString);
    QSqlQueryModel * afficher_tri_nbpoints();
    QSqlQueryModel * chercher_carte_email(QString nom);

};




#endif // PLAT_H
