#ifndef RAYON_H
#define RAYON_H

#include <QMainWindow>
#include <QObject>
#include <QSharedDataPointer>
#include <QWidget>
#include <QSqlQuery>
#include <QString>
#include <QSqlQueryModel>
#include <QSqlTableModel>



class Rayon
{
public:
    Rayon();
    Rayon(int,QString,int);
    int get_ref(){return ref;}
    int get_refemploye(){return refemploye;}
    QString get_type(){return type;}
    void set_ref(int ref){this->ref=ref;}
    void set_refemploye(int refemploye){this->refemploye=refemploye;}
    void set_type(QString type){this->type=type;}
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
 QSqlQueryModel * afficher2(int ref);
    QSqlQueryModel * chercher (int ref);
     QSqlQueryModel * chercher2 (int ref);
     QSqlQueryModel * chercher3 (QString type);
     bool modifier(int a,QString b,int c);
     bool rech(int ref);
     QSqlQueryModel * trierrefrayon();
      QSqlQueryModel * trierrefemploye();
       QSqlQueryModel * triertype();



    ~Rayon();

private:
    int ref;
    QString type;
    int refemploye;
};

#endif // RAYON_H
