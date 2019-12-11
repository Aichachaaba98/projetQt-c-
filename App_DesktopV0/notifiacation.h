
#ifndef NOTIFICATION_H
#define NOTIFICATION_H
#include <QSystemTrayIcon>
#include<QString>
class notifiacation
{
private:
    int num;
public:
    notifiacation();
    void notifiacation_ajout_produit(QString);
    void notifiacation_commande(QString id);
    void notifiacation_ajout_procommande(QString id);
    void notifiacation_supprimer_produit(QString id);
    void notifiacation_modifier_produit(QString id);
    void notifiacation_commande_supprimer(QString id);
    void notifiacation_commande_modifier(QString id);
    void notifiacation_email_sent(QString id);
};

#endif // NOTIFICATION_H
