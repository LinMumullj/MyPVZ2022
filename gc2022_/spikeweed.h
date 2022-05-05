#ifndef SPIKEWEED_H
#define SPIKEWEED_H
#include <QGraphicsItem>
#include <QtWidgets>
#include <QPainter>
#include"tower.h"
#include"zombie.h"

class SpikeWeed : public Tower
{
public:
    QImage* spimg;
    SpikeWeed(int x,int y):Tower(x,y){
        spimg=new QImage(":/image/Spikeweed1.png");
    }
    ~SpikeWeed(){
        delete spimg;
    }
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override{
        Q_UNUSED(option)
        Q_UNUSED(widget)
        painter->drawImage(boundingRect(), *spimg);

    }
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override
    {
        Q_UNUSED(mode)
//        return other->type() == Zombie::Type && Tower::collidesWithItem(other,mode);
        int flag=0;
        if(this->x()==other->x()){
            if(this->y() - other->y()  > 0 && this->y() - other->y()  < 100)
                flag=1;
        }

        if(this->y()==other->y()){
            if(other->x() - this->x() < 100 && this->x() - other->x() < 100)
                flag=1;
        }

        return other->type() == Zombie::Type && flag;
    }

    void hurt(Zombie* zb){
        cnt++;
        if(cnt>3){
            zb->HP-=3;
            cnt=0;
        }

    }
    void advance(int phase) override{
        if (!phase)
            return;
        QList<QGraphicsItem*>list=collidingItems();
        if(!list.empty()){
            for(auto p:list){
                hurt(qgraphicsitem_cast<Zombie* >(p));
            }
        }
        update();
    }
};

#endif // SPIKEWEED_H
