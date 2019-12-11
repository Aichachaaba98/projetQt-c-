#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>

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
signals :
    void testSignal();
private:
    Ui::login *ui;
    QString poste;

};
#endif // LOGIN_H
