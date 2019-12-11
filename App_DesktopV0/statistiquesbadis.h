
#ifndef statistiquesbadis_H
#define statistiquesbadis_H

#include <QDialog>
#include"connexion.h"
#include "customp.h"
#include <QWidget>

namespace Ui {
class statistiquesbadis;
}

class statistiquesbadis : public QDialog
{
    Q_OBJECT

public:
    explicit statistiquesbadis(QWidget *parent = nullptr);
    ~statistiquesbadis();
    void makePolt();


private:
    Ui::statistiquesbadis *ui;
};

#endif // statistiquesbadis_H
