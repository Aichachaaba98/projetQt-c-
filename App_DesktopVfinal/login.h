#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QMediaPlayer>
#include"arduino.h"
QT_BEGIN_NAMESPACE
namespace Ui { class login; }
QT_END_NAMESPACE

class login : public QMainWindow
{
    Q_OBJECT

public:
        int test;
    login(QWidget *parent = nullptr);
    ~login();
    int get_test()const{return test;}
    void set_test(int);
private slots:
    void on_connecter_clicked();

    void on_check_mdp_toggled(bool checked);

    void on_comboBox_currentTextChanged(const QString &arg1);
    void on_comboBox_2_editTextChanged(const QString &arg1);

    void on_comboBox_2_currentTextChanged(const QString &arg1);
void update_label();
QByteArray getData(){return  data;}
signals :
    void testSignal();
private:
    Ui::login *ui;
    QString poste;
    QString langue;
 QMediaPlayer *player = new QMediaPlayer;
  QMediaPlayer *player1 = new QMediaPlayer;
  QByteArray data="";
  int carte=-5;
  Arduino A;
};
#endif // LOGIN_H
