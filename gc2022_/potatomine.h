#ifndef POTATOMINE_H
#define POTATOMINE_H
#include <QGraphicsItem>
#include <QtWidgets>
#include <QPainter>
#include"tower.h"
#include"zombie.h"
class PotatoMine : public Tower
{
public:
    QImage* poimg;
    PotatoMine(int x,int y):Tower(x,y){
        poimg=new QImage(":/image/PotatoMine.png");
    }
    ~PotatoMine(){
        delete poimg;
    }
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override{
        Q_UNUSED(option)
        Q_UNUSED(widget)
        painter->drawImage(boundingRect(), *poimg);

    }
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override
    {
        Q_UNUSED(mode)
        return other->type() == Zombie::Type && other->y() == y() && other->x() == x();
    }

    void destroy(Zombie* zb){
        zb->HP=0;
        this->HP=0;

    }
    void advance(int phase) override{
        if (!phase)
            return;
        if(!collidingItems().empty()){
            destroy(qgraphicsitem_cast<Zombie* >(collidingItems()[0]));
        }
        update();
    }
};

#endif // POTATOMINE_H
