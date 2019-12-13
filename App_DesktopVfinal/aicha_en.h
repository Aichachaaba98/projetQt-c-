#ifndef aicha_en_H
#define aicha_en_H

#include <QDialog>
#include "produitray.h"
#include "rayon.h"
#include <QMediaPlayer>
#include "smtp.h"
#include <QDialog>
#include <QtWidgets/QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class aicha_en; }
QT_END_NAMESPACE

class aicha_en : public QDialog
{
    Q_OBJECT

public:
    aicha_en(QWidget *parent = nullptr);
    ~aicha_en();

private slots:


    void on_horizontalSlider_sliderMoved(int position);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_23_clicked();

    void on_radioButton_23_clicked();

    void on_pushButton_24_clicked();

    void on_radioButton_9_clicked();

    void on_radioButton_11_clicked();

    void on_radioButton_10_clicked();

    void on_comboBox_2_activated(const QString &arg1);

    void on_pushButton_8_clicked();

    void on_modifier_rayon_clicked();

    void on_supprimer_rayon_clicked();

    void on_ok_clicked();

    void on_pushButton_3_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_dateEdit_userDateChanged(const QDate &date);

    void on_spinBox_valueChanged(const QString &arg1);

    void on_spinBox_2_valueChanged(const QString &arg1);

    void on_radioButton_5_clicked();

    void on_radioButton_6_clicked();

    void on_radioButton_7_clicked();

    void on_radioButton_8_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_comboBox_8_activated(const QString &arg1);

    void on_pushButton_22_clicked();

    void on_comboBox_9_activated(const QString &arg1);

    void on_dateEdit_3_userDateChanged(const QDate &date);

    void on_spinBox_5_valueChanged(const QString &arg1);

    void on_spinBox_6_valueChanged(const QString &arg1);


    void on_refedit_9_textChanged(const QString &arg1);

    void on_pushButton_27_clicked();
    void sendMail();
    void mailSent(QString status);
    bool verif_nom(QString nom);
    void on_comboBox_3_activated(const QString &arg1);


    void on_pushButton_9_clicked();

    void on_sendBtn_clicked();

    void on_pushButton_10_clicked();

    void on_comboBox_4_activated(const QString &arg1);
    void initialiser();
private:
    Ui::aicha_en *ui;
    produitray pr;
QMediaPlayer *music =new QMediaPlayer();
Rayon tmprayon,tmp;
Rayon e;
QString collect;
QString type;
QDate date1;
int qt, solde;
};
#endif // aicha_en_H
