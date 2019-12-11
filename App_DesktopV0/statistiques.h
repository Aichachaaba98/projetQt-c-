#ifndef statistiques_H
#define statistiques_H

#include <QWidget>
#include <QMap>
#include <QVector>
namespace Ui {
class statistiques;
}

class statistiques : public QWidget
{
    Q_OBJECT

public:
    explicit statistiques(QWidget *parent = nullptr);
    ~statistiques();

private:
    Ui::statistiques *ui;
};


#endif // statistiques_H
