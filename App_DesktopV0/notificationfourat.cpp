#include "notificationfourat.h"
#include <QSystemTrayIcon>
#include<QString>
notificationfourat::notificationfourat()
{
num=0;
}

void notificationfourat::afficher()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->show();
    notifyIcon->showMessage("Rappel","une reclamation a depassé la date limite (7 JOURS ) ",QSystemTrayIcon::Information,15000);
}
