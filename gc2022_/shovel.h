#ifndef SHOVEL_H
#define SHOVEL_H
#include <QGraphicsItem>
#include <QtWidgets>
#include <QPainter>

class Shovel : public QGraphicsItem
{
public:

    QImage* img1;
    QImage* img2;
    Shovel(int x,int y){
        setZValue(3);
        this->setX(x);
        this->setY(y);
        img1=new QImage(":/image/ShovelBank.png");
        img2=new QImage(":/image/Shovel.png");
    }
    ~Shovel(){
        delete img1;
        delete img2;
    }
    //绑定矩形
    QRectF boundingRect() const override{
        return QRectF(0,-100,100,100);
    }
    //以局部坐标绘制项目的内容
    //在QGraphicsItem子类中重新实现此函数，以使用painter提供项目的绘制实现。
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override{
        Q_UNUSED(option)
        Q_UNUSED(widget)
        painter->drawImage(boundingRect(),*img1);
        painter->drawImage(boundingRect(),*img2);
    }
};

#endif // SHOVEL_H
