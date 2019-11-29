#ifndef AJOUT_H
#define AJOUT_H

#include <QDialog>
#include "rayon.h"
namespace Ui {
class Ajout;
}

class Ajout : public QDialog
{
    Q_OBJECT

public:
    explicit Ajout(QWidget *parent = nullptr);
    ~Ajout();

private slots:
    void on_ok_clicked();

private:
    Ui::Ajout *ui;
    Rayon e;
};

#endif // AJOUT_H
