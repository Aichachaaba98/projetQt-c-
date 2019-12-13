#ifndef MESSANGER_H
#define MESSANGER_H

#include <QWidget>
#include <QDialog>
namespace Ui {
class messanger;
}
class QTcpSocket;
namespace Duartecorporation
{
class messanger : public QWidget
{
    Q_OBJECT

public:
    explicit messanger(QWidget *parent = nullptr);
    ~messanger();
private slots:
    void on_send_clicked();

    void on_connect_clicked();
private:
    Ui::messanger *ui;
       QTcpSocket *mSocket;
};
}

#endif // MESSANGER_H
