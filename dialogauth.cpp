#include "dialogauth.h"
#include "ui_dialogauth.h"
#include <QTranslator>
#include <QLocale>
#include <QDir>
#include <QProcess>
#include <QDebug>
#include <QSettings>
#include <string>

DialogAuth::DialogAuth(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAuth)
{


    QSettings *localSettings=new QSettings(QString("%1%2").arg(QDir::homePath(), "/.gumh/gumh.conf"), QSettings::NativeFormat);
    ui->setupUi(this);
    ui->progressBar_auth->setValue(0);
    command="mentohust ";
    flag += QString("-u%1 -p%2 ").arg(localSettings->value("Program/Username").toString(),
                                   localSettings->value("Program/Password").toString());//add User Name and Password

    flag += QString("-d%1 -b%2 -n%3 -a%4").arg(localSettings->value("Program/DHCP Mode").toString(),
                                               localSettings->value("Program/Demon Mode").toString(),
                                               localSettings->value("Program/interface").toString(),
                                               localSettings->value("Program/Auth Mode").toString());//add Basic Configurations

    command += flag;
    QProcess starter;
    starter.start(command);
    qDebug() << command;
    starter.waitForFinished();
    QByteArray StdOut=starter.readAllStandardOutput();
    char *StdOut_n = new char[StdOut.length()];
    for (int i=0; i<StdOut.length(); i++)
        StdOut_n[i]=StdOut[i];
    QString str=QString(StdOut_n);

    qDebug() << "ERROR:" <<str;
    ui->progressBar_auth->setValue(100);
}

DialogAuth::~DialogAuth()
{
    delete ui;
}
