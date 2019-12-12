#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "produitray.h"
#include "rayon.h"
#include <QMediaPlayer>
#include "smtp.h"
#include <QDialog>
#include <QtWidgets/QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_afficher_clicked();

    void on_modifier_clicked();

    void on_ajouter_clicked();

    void on_supprimer_clicked();

    void on_afficher_2_clicked();

    void on_ajouter_2_clicked();

    void on_supprimer_2_clicked();

    void on_modifier_2_clicked();

    void on_controller_2_clicked();

    void on_alerte_2_clicked();

    void on_meilleurprod_2_clicked();

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

    void on_comboBox_9_currentTextChanged(const QString &arg1);

    void on_refedit_9_textChanged(const QString &arg1);

    void on_pushButton_27_clicked();
    void sendMail();
    void mailSent(QString status);
    bool verif_nom(QString nom);
    void initialiser();

    void on_pushButton_9_clicked();

    void on_comboBox_3_activated(const QString &arg1);

private:
    Ui::MainWindow *ui;
    produitray pr;
QMediaPlayer *music =new QMediaPlayer();
Rayon tmprayon,tmp;
Rayon e;
QString collect;
QString type;
QDate date1;
int qt, solde;
};
#endif // MAINWINDOW_H
