#ifndef BIENVENUE_H
#define BIENVENUE_H
#include <QPixmap>
#include "produit.h"
#include "login.h"
#include "produit.h"
#include "parkingint.h"
#include "mainwindow.h"
#include "aicha.h"
#include "gestion_reclamation.h"
#include "gestion_produits.h"
#include "gestion_des_employe.h"
#include <QDialog>

namespace Ui {
class bienvenue;
}

class bienvenue : public QDialog
{
    Q_OBJECT

public:
    explicit bienvenue(QWidget *parent = nullptr);
    ~bienvenue();
   void bienvenueYassine();
   void bienvenueArbi();
   void bienvenueFourat();

private:
    Ui::bienvenue *ui;
    int t;
};

#endif // BIENVENUE_H
