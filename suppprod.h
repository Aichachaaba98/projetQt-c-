#ifndef SUPPPROD_H
#define SUPPPROD_H

#include <QDialog>
#include "produitray.h"

namespace Ui {
class suppprod;
}

class suppprod : public QDialog
{
    Q_OBJECT

public:
    explicit suppprod(QWidget *parent = nullptr);
    ~suppprod();

private slots:
    void on_pushButton_clicked();

private:
    Ui::suppprod *ui;
    produitray pr;

};

#endif // SUPPPROD_H
