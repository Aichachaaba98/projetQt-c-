#ifndef ALERTEQT_H
#define ALERTEQT_H

#include <QDialog>

#include "produitray.h"

namespace Ui {
class alerteqt;
}

class alerteqt : public QDialog
{
    Q_OBJECT

public:
    explicit alerteqt(QWidget *parent = nullptr);
    ~alerteqt();

private:
    Ui::alerteqt *ui;
    produitray pr;
};

#endif // ALERTEQT_H
