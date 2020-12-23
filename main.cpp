#include "mainwindow.h"

#include <QApplication>

QString appPath;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    appPath = QApplication::applicationDirPath();
    MainWindow w;
    w.show();
    return a.exec();
}
