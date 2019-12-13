#ifndef notifiacationfourat_H
#define notifiacationfourat_H
#include <QSystemTrayIcon>
#include<QString>
class notificationfourat
{
private:
    int num;
    QString text,titre;
public:
    notificationfourat();
    notificationfourat(QString,QString);

    void afficher();
};

#endif // notifiacationfourat_H
