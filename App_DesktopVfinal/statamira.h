#ifndef statamira_H
#define statamira_H

#include <QDialog>
#include"connexion.h"
#include "qcustomplot.h"
#include <QWidget>

namespace Ui {
class statamira;
}

class statamira : public QDialog
{
    Q_OBJECT

public:
    explicit statamira(QWidget *parent = nullptr);
    ~statamira();
    void makePolt();

private:
    Ui::statamira *ui;
};

#endif // statamira_H
