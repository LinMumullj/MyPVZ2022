#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("坦克塔防");
    w.setFixedSize(1500,1500);
    w.show();
    return a.exec();
}
