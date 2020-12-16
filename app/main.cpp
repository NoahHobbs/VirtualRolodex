#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QString uname = "noah hobbs";
    class name test;
    qDebug() << test.capsName(uname);
    QString phoneN = "5154430576";
    class phone ptest;
    qDebug() << ptest.checkPhone(phoneN);



    return a.exec();
}
