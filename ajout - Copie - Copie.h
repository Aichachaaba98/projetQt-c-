#ifndef AJOUT_H
#define AJOUT_H

#include <QDialog>

namespace Ui {
class Ajout;
}

class Ajout : public QDialog
{
    Q_OBJECT

public:
    explicit Ajout(QWidget *parent = nullptr);
    ~Ajout();

private:
    Ui::Ajout *ui;
};

#endif // AJOUT_H
