#ifndef PRODUITRAY_H
#define PRODUITRAY_H

#include <QMainWindow>
#include <QObject>
#include <QSharedDataPointer>
#include <QWidget>
#include <QDate>
#include <QSqlQuery>
#include <QString>
#include <QSqlQueryModel>
#include <QSqlTableModel>






class produitray
{
public:
    produitray();


    ~produitray();

    int get_ref(){return ref;}
    int get_refray(){return refray;}
    QString get_type(){return type;}
     int get_qtray (){return qtray;}
    int get_solde (){return solde;}
     QDate get_date (){return date_exp;}
     QString get_nom(){return nom;}


    void set_ref(int ref){this->ref=ref;}
    void set_refray(int refray){this->refray=refray;}
    void set_solde(int solde){this->solde=solde;}
    void set_qtray(int qt){this->qtray=qt;}
    void set_type(QString type){this->type=type;}
    void set_nom(QString nom){this->nom=nom;}
    void set_date(QDate date){this->date_exp=date;}

    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * chercher(int refray);
    QSqlQueryModel * chercher1(QString nom);
    QSqlQueryModel * chercher2(QString type);
    QSqlQueryModel * triernom();
    QSqlQueryModel * trierqt();
    QSqlQueryModel * trierdate();
    bool supprimer(int ref);
    bool modifier(int ref,QString nom, QString type, int refrayon, int qt, QDate date, int solde);
    bool rech(int ref);
     QSqlQueryModel * modeltype();
     QSqlQueryModel * alertedate(bool *test);
    QSqlQueryModel * alerteqt();
private:
    int ref;
    int refray;
    QString nom;
    QString type;
    int qtray;
    QDate date_exp;
    int solde;


};

#endif // PRODUITRAY_H
