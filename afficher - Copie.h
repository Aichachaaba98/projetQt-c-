#ifndef AFFICHER_H
#define AFFICHER_H

#include <QDialog>

namespace Ui {
class AFFICHER;
}

class AFFICHER : public QDialog
{
    Q_OBJECT

public:
    explicit AFFICHER(QWidget *parent = nullptr);
    ~AFFICHER();

private:
    Ui::AFFICHER *ui;
};

#endif // AFFICHER_H
