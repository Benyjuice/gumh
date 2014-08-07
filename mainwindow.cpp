#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTranslator>
#include <QLocale>
#include <QDir>
#include <QProcess>
#include <QStyle>
#include <QSettings>
#include <QDebug>
#include "dialogauth.h"
#include "editconfig.h"
#include "form.h"

QString username;
QString password;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QSettings *localSettings = new QSettings(QString("%1%2").arg(QDir::homePath(), "/.gumh/gumh.conf"), QSettings::NativeFormat);

    ui->setupUi(this);
    ui->UserName->setText(localSettings->value("Program/Username"," ").toString());
    ui->Password->setText(localSettings->value("Program/Password"," ").toString());
    if(localSettings->value("Program/Remember").toBool())
        ui->checkBoxRemember->setChecked(true);
    if(localSettings->value("Program/AutoAuth").toBool()) {
        ui->checkBoxAutoAuth->setChecked(true);
        DialogAuth di;
        di.exec();
    }
    //qDebug<<username.toAscii();
    delete localSettings;
    connect(ui->actionAdvanced_Settings,SIGNAL(triggered()),this,SLOT(actionSettings()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_authButton_clicked()
{
    QSettings *localSettings = new QSettings(QString("%1%2").arg(QDir::homePath(), "/.gumh/gumh.conf"), QSettings::NativeFormat);
    if(ui->checkBoxRemember->isChecked()) {
        localSettings->setValue("Program/Username",ui->UserName->text().toAscii());
        localSettings->setValue("Program/Password",ui->Password->text().toAscii());
        localSettings->setValue("Program/Remember",true);
    }
    if(ui->checkBoxAutoAuth->isChecked())
        localSettings->setValue("Program/AutoAuth",true);
    else
        localSettings->setValue("Program/AutoAuth",false);

    delete localSettings;
    DialogAuth di;
    di.setWindowTitle(tr("Authlizing"));
    di.exec();
}

void MainWindow::authrise()
{
           //renzheng hanshu
}

void MainWindow::actionSettings()
{
    editConfig edi;
    edi.exec();
}

