#ifndef DATEEX_H
#define DATEEX_H

#include <QDialog>
#include "produitray.h"


namespace Ui {
class dateex;
}

class dateex : public QDialog
{
    Q_OBJECT

public:
    explicit dateex(QWidget *parent = nullptr);
    ~dateex();

private:
    Ui::dateex *ui;
    produitray pr;
};

#endif // DATEEX_H
