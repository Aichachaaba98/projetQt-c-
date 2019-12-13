#ifndef MESSANGERCONNECTION_H
#define MESSANGERCONNECTION_H

#include <QDialog>

namespace Ui {
class MessangerConnection;
}
namespace Duartecorporation
{
class MessangerConnection : public QDialog
{
    Q_OBJECT

public:
    explicit MessangerConnection(QWidget *parent = nullptr);
    ~MessangerConnection();
    QString hostname () const {return  mHostname;}
    quint16 port () const{return  mport;}
private slots:
    void on_ok_clicked();

    void on_cancel_clicked();

private:
    Ui::MessangerConnection *ui;
    QString mHostname;
    quint16 mport;
};
}

#endif // MESSANGERCONNECTION_H
