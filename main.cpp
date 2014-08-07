#include "mainwindow.h"
#include "logindioag.h"
#include <QApplication>
#include <QSettings>
#include <QDir>
#include <QTranslator>
#include <QProcess>

int main(int argc, char *argv[])
{
    FILE *ptr;
    int test=0;
    char *buf = new char[BUFSIZ];
    if ((ptr = popen("id | grep uid=0", "r")) != NULL)
        while (fgets(buf, BUFSIZ, ptr) != NULL) test++;
    delete []buf;
    pclose(ptr);
    if (test==0) {
        QString cm = QString("gksudo %1").arg(argv[0]);
        QProcess cms;
        cms.start(cm);
        cms.waitForFinished(5000);

    }
    else {
    QApplication a(argc, argv);
    MainWindow w;
    QTranslator trans;
    trans.load(":/res/app_zh_CN.qm");
    a.installTranslator(&trans);
    w.show();
    QApplication::setStyle("plastique");
    return a.exec();
    }
}
