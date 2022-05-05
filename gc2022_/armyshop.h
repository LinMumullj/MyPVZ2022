#ifndef ARMYSHOP_H
#define ARMYSHOP_H

#include <QGraphicsItem>
#include <QtWidgets>
#include <QPainter>
#include<shop.h>
class ArmyShop : public Shop
{
public:
    ArmyShop(int x,int y):Shop(x,y){
        setZValue(3);
        imgshop=new QImage(":/image/marquee.PNG");
        imgu=new QImage(":/image/peanutcard.png");
        imgd=new QImage(":/image/spikecard.png");
        imgl=new QImage(":/image/potatocard.png");
        imgr=new QImage(":/image/Card.png");
    }
    //以局部坐标绘制项目的内容
    //在QGraphicsItem子类中重新实现此函数，以使用painter提供项目的绘制实现。
};

#endif // ARMYSHOP_H
