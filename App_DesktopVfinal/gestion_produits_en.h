#ifndef gestion_produits_en_H
#define gestion_produits_en_H
#include "produit.h"
#include <QDialog>
#include "produit_livrer.h"
#include "smtp.h"
#include "pr_commande.h"
#include "QMediaPlayer"
#include "QMediaPlaylist"
#include "QVideoWidget"
#include "messanger.h"
namespace Ui {
class gestion_produits_en;
}

class gestion_produits_en : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_produits_en(QWidget *parent = nullptr);
    ~gestion_produits_en();

private slots:

    void sendMail();
    void mailSent(QString);
    void on_ajouter_clicked();

    void on_supprimer_clicked();
    void on_modifier_clicked();

    void on_comboBox_m_currentIndexChanged(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_comboBox_2_activated(const QString &arg1);

    void on_radioButton_4_clicked();



    void on_pushButton_clicked();

    void on_pushButton_4_clicked();



    void on_comboBox_m_2_currentIndexChanged(const QString &arg1);

    void on_modifier_2_clicked();

    void on_supprimer_2_clicked();

    void on_ajouter_2_clicked();

    void on_ajouter_3_clicked();

    void on_sendBtn_clicked();



    void on_radioButton_2_toggled(bool checked);

    void on_pushButton_7_clicked();

    void on_radioButton_clicked();

    void on_comboBox_11_currentTextChanged(const QString &arg1);

    void on_spinBox_valueChanged(int arg1);


    void on_checkBox_clicked(bool checked);

    void on_pushButton_8_clicked();

    void on_comboBox_12_activated(const QString &arg1);

    void on_pushButton_9_clicked();

    void on_ajouter_5_clicked();

    void on_modifier_3_clicked();

    void on_horizontalSlider_sliderMoved(int position);

    void on_pushButton_11_clicked();

    void on_pushButton_10_clicked();

    void on_verticalSlider_sliderMoved(int position);


    void on_reference_e_2_textChanged(const QString &arg1);

void on_radioButton_clicked(bool checked);
    void on_comboBox_13_currentTextChanged(const QString &arg1);

    void on_lineEdit_textChanged(const QString &arg1);

    void on_deconecter_clicked();

    void on_commandLinkButton_2_clicked();

    void on_commandLinkButton_5_clicked();

    void on_commandLinkButton_clicked();

    void on_commandLinkButton_4_clicked();

    void on_commandLinkButton_3_clicked();



private:
    Ui::gestion_produits_en *ui;
    produit tmpproduit;
    QString collect,champ;
    int qt,etat,volume;
    QString pays,type;
    produit_livrer tmpprodlivrer;
    QString tri;
    int etat1=0;
    pr_commande tmppr;
    QMediaPlaylist *playlist =new QMediaPlaylist();
      QMediaPlaylist *playlist2 =new QMediaPlaylist();
    QMediaPlayer *player = new QMediaPlayer;
     QMediaPlayer *player1 = new QMediaPlayer;
      QMediaPlayer *player2 = new QMediaPlayer;
     QVideoWidget *videoWidget = new QVideoWidget;
int t=0;

};

#endif // gestion_produits_en_H
