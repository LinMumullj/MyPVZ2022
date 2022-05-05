#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <QGraphicsItem>
#include <QtWidgets>
#include <QPainter>
#include"army.h"
#include<vector>
#include<QDebug>
#include"block.h"
#include"peanut.h"
using namespace std;
class Zombie : public Army
{
public:
    enum { Type = UserType + 2};
    int type()const override{
        return Type;
    }
    vector<QPoint*>path;
    Zombie(int x,int y):Army(){
        setZValue(1);
        this->setX(x);
        this->setY(y);

        attackvalue=5;
        speed=5;
        maxHP=100;
        HP=100;

        img=new QMovie(":/image/ZombieWalk1.gif");
        img->start();
        attackimg=new QMovie(":/image/ZombieAttack.gif");
        attackimg->start();
        pushPath();
    }
//    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override
//    {
//        Q_UNUSED(mode)
//        //other->type() == Block::Type &&
//        return other->type() == Block::Type && qAbs(other->y() - y()) < 400 && qAbs(other->x() - x()) < 400;
//    }
    virtual void pushPath(){
        path.push_back(new QPoint(0,1200));
        path.push_back(new QPoint(100,1200));
        path.push_back(new QPoint(200,1200));
        path.push_back(new QPoint(200,1100));
        path.push_back(new QPoint(200,1000));
        path.push_back(new QPoint(200,900));
        path.push_back(new QPoint(200,800));
        path.push_back(new QPoint(200,700));
        path.push_back(new QPoint(200,600));
        path.push_back(new QPoint(200,500));
        path.push_back(new QPoint(200,400));
        path.push_back(new QPoint(200,300));
        path.push_back(new QPoint(200,200));
        path.push_back(new QPoint(300,200));
        path.push_back(new QPoint(400,200));

        path.push_back(new QPoint(400,300));
        path.push_back(new QPoint(400,400));
        path.push_back(new QPoint(400,500));
        path.push_back(new QPoint(400,600));
        path.push_back(new QPoint(400,700));
        path.push_back(new QPoint(400,800));
        path.push_back(new QPoint(400,900));
        path.push_back(new QPoint(400,1000));

        path.push_back(new QPoint(500,1000));
        path.push_back(new QPoint(600,1000));
        path.push_back(new QPoint(700,1000));
        path.push_back(new QPoint(800,1000));

        path.push_back(new QPoint(800,900));
        path.push_back(new QPoint(800,800));
        path.push_back(new QPoint(800,700));
        path.push_back(new QPoint(800,600));
        path.push_back(new QPoint(800,500));
        path.push_back(new QPoint(800,400));

        path.push_back(new QPoint(900,400));
        path.push_back(new QPoint(1000,400));
        path.push_back(new QPoint(1100,400));
        path.push_back(new QPoint(1200,400));
        path.push_back(new QPoint(1300,400));
        path.push_back(new QPoint(1400,400));

        path.push_back(new QPoint(1400,500));
        path.push_back(new QPoint(1400,600));

        path.push_back(new QPoint(1300,600));
        path.push_back(new QPoint(1200,600));
        path.push_back(new QPoint(1100,600));
        path.push_back(new QPoint(1000,600));

        path.push_back(new QPoint(1000,700));
        path.push_back(new QPoint(1000,800));
        path.push_back(new QPoint(1000,900));
        path.push_back(new QPoint(1000,1000));
        path.push_back(new QPoint(1000,1100));
        path.push_back(new QPoint(1000,1200));

        path.push_back(new QPoint(1100,1200));
        path.push_back(new QPoint(1200,1200));
        path.push_back(new QPoint(1300,1200));
        path.push_back(new QPoint(1400,1200));
    }

    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override
    {

        //TODO:
        Q_UNUSED(mode)
        int flag=0;
        if(this->x()==other->x()){
            if(other->y() - this->y() < 100 && this->y() - other->y() <100)
                flag=1;
        }

        if(this->y()==other->y()){
            if(other->x() - this->x() < 100 && this->x() - other->x() < 100)
                flag=1;
        }

        return other->type() == Peanut::Type && flag;
    }

    void attack(Peanut * t){
        t->HP-=attackvalue;
        if(t->HP<=0)
          t->HP=0;
    }
    void advance(int phase) override{
        if (!phase)
            return;
        QList<QGraphicsItem*>list=collidingItems();
        if(!list.empty()){
            state=1;
            cnt++;
            if(cnt==10){
                cnt=0;
                attack(qgraphicsitem_cast<Peanut* >(list[0]));
            }

        }else{
            state=0;
            QPoint *p1=nullptr;
            QPoint *p2=nullptr;
            for(int i=0;i<path.size()-1;i++){
                p1=path.at(i);
                p2=path.at(i+1);
                if(((x()-p1->x())*(x()-p2->x()))<=0&&((y()-p1->y())*(y()-p2->y()))<=0)
                    if((x()!=p2->x()||y()!=p2->y()))//非端点
                        break;//找到所在路径(不包含终点)
            }
            //往下一个端点走
            if(x()>p2->x()){
                setX(x()-speed);
            }
            if(x()<p2->x()){
                setX(x()+speed);
            }
            if(y()>p2->y()){
                setY(y()-speed);
            }
            if(y()<p2->y()){
                setY(y()+speed);
            }
        }
        update();


    }
};

#endif // ZOMBIE_H
