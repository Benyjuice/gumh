#include "logindioag.h"
#include "ui_logindioag.h"

loginDioag::loginDioag(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginDioag)
{
    ui->setupUi(this);
}

loginDioag::~loginDioag()
{
    delete ui;
}

void loginDioag::on_authButton_clicked()
{
    accept();
}
