#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include <QtDebug>
#include "login.h"
int main(int argc, char *argv[])
{  QApplication a(argc, argv);

    Connection c;
MainWindow w;

   if(c.ouvrirconnexion())
   {
       login l;
       l.show();
       QObject::connect(&l,&login::sig,&w,&MainWindow::show);

      return a.exec();
   }
    return 0;
}



