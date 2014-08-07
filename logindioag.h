#ifndef LOGINDIOAG_H
#define LOGINDIOAG_H

#include <QDialog>

namespace Ui {
class loginDioag;
}

class loginDioag : public QDialog
{
    Q_OBJECT

public:
    explicit loginDioag(QWidget *parent = 0);
    ~loginDioag();

private slots:
    void on_authButton_clicked();

private:
    Ui::loginDioag *ui;
};

#endif // LOGINDIOAG_H
