#ifndef SMTPAFF_H
#define SMTPAFF_H

#include <QDialog>
#include <QtWidgets/QMessageBox>
#include "smtp.h"

namespace Ui {
class smtpaff;
}

class smtpaff : public QDialog
{
    Q_OBJECT

public:
    explicit smtpaff(QWidget *parent = nullptr);
    ~smtpaff();

private:
    Ui::smtpaff *ui;
 private slots:
    void sendMail();
    void mailSent(QString);
};

#endif // SMTPAFF_H
