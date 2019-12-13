#include "notificationfourat.h"
#include <QSystemTrayIcon>
#include<QString>
notificationfourat::notificationfourat()
{
num=0;
}
notificationfourat::notificationfourat(QString titre,QString text)
{
  this->text=text;
    this->titre=titre;
}

void notificationfourat::afficher()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->setIcon(QIcon("C:/Users/HP ENVY/Desktop/PROJET Qt/RAYON/ajout.png"));
    notifyIcon->show();;
    notifyIcon->showMessage(titre,text,QSystemTrayIcon::Information,15000);
}
