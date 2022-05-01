#ifndef SUNFLOWER_H
#define SUNFLOWER_H
#include <QGraphicsItem>
#include <QtWidgets>
#include <QPainter>
#include"tower.h"
#include"sunmanager.h"
class SunFlower : public Tower
{
public:
    SunManager* sm;
    SunFlower(int x,int y,SunManager* sm):Tower(x,y){
        this->sm=sm;
        img=new QMovie(":/image/SunFlower.gif");
        img->start();
    }
    void advance(int phase){

        if(!phase)
            return;


        if(cnt++>100){
            cnt=0;
            sm->sun+=25;
        }
        update();
    }
};

#endif // SUNFLOWER_H
