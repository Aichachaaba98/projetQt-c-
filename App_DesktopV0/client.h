#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class client
{
    QString email,nom,prenom;
    int abonne_carte;
public:
    client();
    client(QString,QString,QString,int);
    QString getemail();
    QString getnom();
    QString getprenom();
    int getabonne_carte();

    bool ajouterclient();
    bool modifierclient(QString email, QString nom, QString prenom, int abonne_carte);
    QSqlQueryModel * afficherclient();
    bool supprimerclient(QString);
    QSqlQueryModel * getMailModel();

    QSqlQueryModel * chercher_client_email(QString nom);
    QSqlQueryModel * chercher_client_nom(QString nom);

    QSqlQueryModel * afficher_tri_email();

};

#endif // CLIENT_H
