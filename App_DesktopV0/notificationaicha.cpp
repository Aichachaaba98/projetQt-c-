#include "notificationaicha.h"
#include <QSystemTrayIcon>
#include<QString>
notificationaicha::notificationaicha()
{
num=0;
}

void notificationaicha::notificationaicha_dateexp()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Users/HP ENVY/Desktop/PROJET Qt/RAYON/ajout.png"));
    //QString s = id;
    //notifyIcon->setVisible(1);
    notifyIcon->show();
    notifyIcon->showMessage("Alerte","Date expirée!",QSystemTrayIcon::Information,15000);
//num++;
}

/*void notificationaicha::notificationaicha_ajout_destination(QString id)
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Users/Haboub/Pictures/Wallpapers/witcherHorizon.jpg"));
    QString s = id;
    //notifyIcon->setVisible(1);
    notifyIcon->show();
    notifyIcon->showMessage("News","Une nouvelle destiantion a été ajoutée !",QSystemTrayIcon::Information,15000);
//num++;
}


void notificationaicha::notificationaicha_Ouverture(QString id)
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Users/Haboub/Pictures/Wallpapers/witcherHorizon.jpg"));
    QString s = id;
    //notifyIcon->setVisible(1);
    notifyIcon->show();
    notifyIcon->showMessage("Gestion d'agence de voyage","Nouvelle instance ouverte",QSystemTrayIcon::Information,15000);
//num++;
}
*/
