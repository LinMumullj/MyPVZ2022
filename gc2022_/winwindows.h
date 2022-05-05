#ifndef WINWINDOWS_H
#define WINWINDOWS_H
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include<qdebug.h>
class WinWindows : QMainWindow
{
    Q_OBJECT
public:
    int state;//0输 1赢
    WinWindows(int s)
    {
        setFixedSize(1500,1500);
        state=s;

        //QGraphicsScene* scs = new QGraphicsScene(this);

        setWindowTitle("塔防游戏");//设置标题和界面大小
        show();
    }
    void paintEvent(QPaintEvent * ev)
    {
        QPainter painter(this);
        if(state==0){
            painter.drawImage(QRectF(0,0,1500,1500), QImage(":/image/Fail.png"));
        }
        else{
            painter.drawImage(QRectF(0,0,1500,1500), QImage(":/image/Win.png"));
        }
    }

};

#endif // WINWINDOWS_H
