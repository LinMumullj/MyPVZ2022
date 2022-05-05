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

};





#endif // BUCKETZOMBIE_H
