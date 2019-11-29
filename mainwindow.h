#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "produitray.h"

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

private:
    Ui::MainWindow *ui;
    produitray pr;
};
#endif // MAINWINDOW_H
