#ifndef CONNEXION_H
#define CONNEXION_H
#include <QSqlDatabase>

#include <QMainWindow>
#include <QObject>




class connexion
{
private:
    QSqlDatabase db;
public:
    connexion();
    bool ouvrirConnexion();
    void fermerConnexion();
};

#endif // CONNEXION_H
