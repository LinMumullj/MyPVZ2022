#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("PVZ塔防-191220059");
    w.setFixedSize(1500,1500);
    w.setWindowIcon(QIcon(":/image/111.ico"));
    w.show();
    return a.exec();
}
