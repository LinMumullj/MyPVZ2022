#ifndef PEASHOOTER_H
#define PEASHOOTER_H
#include <QGraphicsItem>
#include <QtWidgets>
#include <QPainter>
#include"tower.h"
#include"army.h"
#include"zombie.h"
#include"bullet.h"
class PeaShooter : public Tower
{
    Army* targetenemy;
    vector<Bullet*> *bullets;
    int direction;
public:
    PeaShooter(int x,int y,vector<Bullet*> *bullets):Tower(x,y){
        this->bullets=bullets;
        attack=10;
        targetenemy=NULL;
        img=new QMovie(":/image/Repeater.gif");
        img->start();
        direction=1;
    }

    void hit(Army* am){
        //向右
        Bullet* bl;
        if(am->x()>this->x()){
            bl = new Bullet(this->x()+85,this->y()+17,0,new QPoint(am->x()+50,am->y()+40));
            direction=1;
        }
        else
        {
            bl = new Bullet(this->x()+5,this->y()+17,0,new QPoint(am->x()+50,am->y()+40));
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
        return other->type() == Zombie::Type && qAbs(other->y() - y()) <= 100 && qAbs(other->x() - x()) <= 100;
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
            targetenemy=qgraphicsitem_cast<Zombie* >(list[list.size()-1]);
            hit(targetenemy);
        }
        update();
    }


};

#endif // PEASHOOTER_H
