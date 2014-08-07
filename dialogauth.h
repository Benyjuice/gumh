#ifndef DIALOGAUTH_H
#define DIALOGAUTH_H

#include <QDialog>

namespace Ui {
class DialogAuth;
}

class DialogAuth : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAuth(QWidget *parent = 0);
    ~DialogAuth();


private:
    Ui::DialogAuth *ui;
    QString command;
    QString flag;
    qint16 process_valu;
};

#endif // DIALOGAUTH_H
