#include "editconfig.h"
#include "ui_editconfig.h"
#include <QSettings>
#include <QDir>
#include <QDebug>
#include <QMessageBox>

editConfig::editConfig(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editConfig)
{
    ui->setupUi(this);
}

editConfig::~editConfig()
{
    delete ui;
}

void editConfig::on_pushButtonSave_clicked()
{
    QSettings *localSettings=new QSettings(QString("%1%2").arg(QDir::homePath(), "/.gumh/gumh.conf"), QSettings::NativeFormat);
    localSettings->setValue("Program/interface",ui->comboBoxNetInc->currentText());
    localSettings->setValue("Program/DHCP Mode",ui->comboBoxDHCPMod->currentIndex());
    localSettings->setValue("Program/Auth Mode",ui->comboBoxAuthMod->currentIndex());
    localSettings->setValue("Program/Demon Mode",ui->comboBoxDemonMod->currentIndex());
    QMessageBox message(QMessageBox::Warning,"Information","Configuration Settings Save Successful!",QMessageBox::Yes|QMessageBox::No,NULL);
    if (message.exec()==QMessageBox::Yes || QMessageBox::No)
        message.close();
    delete localSettings;

}
