#ifndef SNOWSHOOTER_H
#define SNOWSHOOTER_H
#include <QGraphicsItem>
#include <QtWidgets>
#include <QPainter>
#include"tower.h"
#include"army.h"
#include"aircraft.h"
#include"zombie.h"
#include"balloonzombie.h"
class SnowShooter : public Tower
{
    Aircraft* targetenemy;
public:
    SnowShooter(int x,int y):Tower(x,y){
        attack=6;
        targetenemy=NULL;
        img=new QMovie(":/image/SnowPea.gif");
        img->start();
    }

    void hit(Aircraft* am){
        am->HP-=attack;
        if(am->HP<=0)
          am->HP=0;
    }
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
    {
        Q_UNUSED(mode)
        return other->type() == BalloonZombie::Type && qAbs(other->y() - y()) < 700 && qAbs(other->x() - x()) < 700;
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
        if(cnt<10){
            update();
            return;
        }
        cnt=0;
        QList<QGraphicsItem*>list=collidingItems();
        if(!list.empty()){
            targetenemy=qgraphicsitem_cast<BalloonZombie* >(list[0]);
            hit(targetenemy);
        }
        update();
    }
};
#endif // SNOWSHOOTER_H
