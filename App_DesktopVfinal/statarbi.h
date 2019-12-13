#ifndef statarbi_H
#define statarbi_H

#include <QDialog>
#include"connexion.h"
#include "qcustomplot.h"
#include <QWidget>

namespace Ui {
class statarbi;
}

class statarbi : public QDialog
{
    Q_OBJECT

public:
    explicit statarbi(QWidget *parent = nullptr);
    ~statarbi();
    void makePolt();


private:
    Ui::statarbi *ui;
};

#endif // statarbi_H
