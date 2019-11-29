
#include "login.h"
#include <QApplication>
#include <QMessageBox>
#include "connexion.h"
#include <QtDebug>
#include "login.h"
#include "mainwindow.h"
int main(int argc, char *argv[])
{  QApplication a(argc, argv);
    QApplication::setStyle("plastique");
    connexion c;

  c.ouvrirConnexion();
  MainWindow w;

  login l;
      l.show();
      QObject::connect(&l,&login::Enter,&w,&MainWindow::show);
        return a.exec();
    //  QMessageBox::information(nullptr, QObject::tr("Database is open"),
      //            QObject::tr("connection avec succés.\n"
        //                      "Click Cancel to exit."), QMessageBox::Cancel);
      //return a.exec();

  //}
  //else
    //  QMessageBox::critical(nullptr, QObject::tr("database is not open"),
      //            QObject::tr("connection failed.\n"
        //                      "Click Cancel to exit."), QMessageBox::Cancel);


}
