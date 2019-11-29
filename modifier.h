#ifndef MODIFIER_H
#define MODIFIER_H

#include <QDialog>
#include "rayon.h"

namespace Ui {
class Modifier;
}

class Modifier : public QDialog
{
    Q_OBJECT

public:
    explicit Modifier(QWidget *parent = nullptr);
    ~Modifier();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Modifier *ui;
    Rayon tmprayon;
};

#endif // MODIFIER_H
