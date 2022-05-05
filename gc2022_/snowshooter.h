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
#include"bullet.h"
class SnowShooter : public Tower
{
    Aircraft* targetenemy;
    vector<Bullet*> *bullets;
    int direction;
public:
    SnowShooter(int x,int y,vector<Bullet*> *bullets):Tower(x,y){
        this->bullets=bullets;
        attack=30;
        targetenemy=NULL;
        img=new QMovie(":/image/SnowPea.gif");
        img->start();
        direction=1;
    }

    void hit(Aircraft* am){
        Bullet* bl;
        if(am->x()>this->x()){
            bl = new Bullet(this->x()+85,this->y()+17,1,new QPoint(am->x()+50,am->y()+40));
            direction=1;
        }
        else
        {
            bl = new Bullet(this->x()+5,this->y()+17,1,new QPoint(am->x()+50,am->y()+40));
            direction=0;
        }
        scene()->addItem(bl);
        bullets->push_back(bl);
        am->HP-=attack;
        if(am->HP<=0)
          am->HP=0;
    }
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override
    {
        Q_UNUSED(mode)
        return other->type() == BalloonZombie::Type && qAbs(other->y() - this->y()) <= 1500 && qAbs(other->x() - this->x()) <= 1500;
    }
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override{
        Q_UNUSED(option)
        Q_UNUSED(widget)
        if(direction)
            painter->drawImage(boundingRect(), img->currentImage());
        else{
            painter->drawImage(boundingRect(), img->currentImage().mirrored(true,false));
        }
    }

    void advance(int phase)override{
        if(!phase)
            return;
        cnt++;
        if(cnt<10){
            update();
            return;
        }
        cnt=0;
        QList<QGraphicsItem*>list=collidingItems();
        if(!list.empty()){
            targetenemy=qgraphicsitem_cast<BalloonZombie* >(list[list.size()-1]);
            hit(targetenemy);
        }
        update();
    }
};
#endif // SNOWSHOOTER_H
