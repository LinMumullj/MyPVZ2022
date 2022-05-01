#ifndef PEASHOOTER_H
#define PEASHOOTER_H
#include <QGraphicsItem>
#include <QtWidgets>
#include <QPainter>
#include"tower.h"
#include"army.h"
#include"zombie.h"
class PeaShooter : public Tower
{
    Army* targetenemy;
public:
    PeaShooter(int x,int y):Tower(x,y){
        attack=10;
        targetenemy=NULL;
        img=new QMovie(":/image/Repeater.gif");
        img->start();
    }

    void hit(Army* am){
        am->HP-=attack;
        if(am->HP<=0)
          am->HP=0;
    }
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
    {
        Q_UNUSED(mode)
        return other->type() == Zombie::Type && qAbs(other->y() - y()) < 500 && qAbs(other->x() - x()) < 500;
    }

    void advance(int phase){
        if(!phase)
            return;
//        for(int i=0;i<scene()->items().size();i++){
//            if(scene()->items()[i]->type()==Zombie::Type){
//                if(abs(scene()->items()[i]->x() - this->x())<400 && (abs(scene()->items()[i]->y()-this->y())<400)){
//                    targetenemy=qgraphicsitem_cast<Zombie *>(scene()->items()[i]);
//                }
//            }
//        }
//        if(targetenemy)
//            hit(targetenemy);
        cnt++;
        if(cnt<15){
            update();
            return;
        }
        cnt=0;
        QList<QGraphicsItem*>list=collidingItems();
        if(!list.empty()){
            targetenemy=qgraphicsitem_cast<Zombie* >(list[0]);
            hit(targetenemy);
        }
        update();
    }


};

#endif // PEASHOOTER_H
