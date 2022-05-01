#ifndef BUCKETZOMBIE_H
#define BUCKETZOMBIE_H
#include"zombie.h"
class BucketZombie : public Zombie{
public:
    BucketZombie(int x,int y):Zombie(x,y){
        attackvalue=10;
        speed=10;
        maxHP=400;
        HP=400;

        if(img)
            delete img;
        img=new QMovie(":/image/BucketZombieWalk.gif");
        img->start();
        attackimg=new QMovie(":/image/BucketZombieAttack.gif");
        attackimg->start();
        pushPath();
    }
    void pushPath(){
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

};





#endif // BUCKETZOMBIE_H
