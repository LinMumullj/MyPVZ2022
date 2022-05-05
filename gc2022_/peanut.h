#ifndef PEANUT_H
#define PEANUT_H
#include <QGraphicsItem>
#include <QtWidgets>
#include <QPainter>
#include"tower.h"

class Peanut : public Tower
{
public:
    enum { Type = UserType + 7};
    int type()const override{
        return Type;
    }
    Peanut(int x,int y):Tower(x,y){
        img=new QMovie(":/image/WallNut.gif");
        img->start();
    }
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override{
        Q_UNUSED(option)
        Q_UNUSED(widget)
        painter->drawImage(boundingRect(), img->currentImage());
        painter->setBrush(Qt::white);
        painter->drawRect(-10,-10,120,10);
        painter->setBrush(Qt::green);
        painter->drawRect(-10,-10,120*HP/maxHP,10);
    }
    void advance(int phase){
        update();
    }
};

#endif // PEANUT_H
