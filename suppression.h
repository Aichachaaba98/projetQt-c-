#ifndef SUPPRESSION_H
#define SUPPRESSION_H
#include"rayon.h"
#include "ui_afficher.h"

#include <QDialog>

namespace Ui {
class Suppression;
}

class Suppression : public QDialog
{
    Q_OBJECT

public:
    explicit Suppression(QWidget *parent = nullptr);
    ~Suppression();

private slots:


    void on_pushButton_clicked();

private:
    Ui::Suppression *ui;
    Rayon tmprayon;
};

#endif // SUPPRESSION_H
