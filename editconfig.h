#ifndef EDITCONFIG_H
#define EDITCONFIG_H

#include <QDialog>

namespace Ui {
class editConfig;
}

class editConfig : public QDialog
{
    Q_OBJECT

public:
    explicit editConfig(QWidget *parent = 0);
    ~editConfig();

private slots:
    void on_pushButtonSave_clicked();

private:
    Ui::editConfig *ui;
};

#endif // EDITCONFIG_H
