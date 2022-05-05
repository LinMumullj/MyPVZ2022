#ifndef CONEZOMBIE_H
#define CONEZOMBIE_H

#include"zombie.h"
class ConeZombie : public Zombie{
public:
    ConeZombie(int x,int y):Zombie(x,y){
        attackvalue=5;
        speed=5;
        maxHP=150;
        HP=150;

        if(img)
            delete img;
        img=new QMovie(":/image/ConeZombieWalk.gif");
        img->start();
        attackimg=new QMovie(":/image/ConeZombieAttack.gif");
        attackimg->start();
        pushPath();
    }
};


#endif // CONEZOMBIE_H
