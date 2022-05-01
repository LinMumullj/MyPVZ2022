#ifndef BALLOONZOMBIE_H
#define BALLOONZOMBIE_H
#include <QGraphicsItem>
#include <QtWidgets>
#include <QPainter>
#include"aircraft.h"
#include<vector>
#include<QDebug>
#include"block.h"
using namespace std;
class BalloonZombie : public Aircraft
{
public:
    enum { Type = UserType + 5};
    int type()const override{
        return Type;
    }
    vector<QPoint*>path;
    BalloonZombie(int x,int y):Aircraft(){
        HP=150;
        maxHP=150;
        attack=10;
        speed=6;

        setZValue(2);
        this->setX(x);
        this->setY(y);
        img=new QImage(":/image/qqjs.png");
        pushPath();
    }


    void pushPath(){
        path.push_back(new QPoint(0,1200));
        path.push_back(new QPoint(100,1200));
        path.push_back(new QPoint(200,1200));
        path.push_back(new QPoint(300,1200));
        path.push_back(new QPoint(400,1200));
        path.push_back(new QPoint(500,1200));
        path.push_back(new QPoint(600,1200));
        path.push_back(new QPoint(700,1200));
        path.push_back(new QPoint(800,1200));
        path.push_back(new QPoint(900,1200));
        path.push_back(new QPoint(1000,1200));
        path.push_back(new QPoint(1100,1200));
        path.push_back(new QPoint(1200,1200));
        path.push_back(new QPoint(1300,1200));
        path.push_back(new QPoint(1400,1200));
    }
    void advance(int phase) override{
        if (!phase)
            return;
//        update();

//        if(!collidingItems().empty()){

//            qDebug()<<"僵尸pengzhuang";
//        }

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
        update();

//        if(x()==path.back()->x()&&y()==path.back()->y()){
//            this->scene()->removeItem(this);
//            delete this;
//        }

    }
};

#endif // BALLOONZOMBIE_H
