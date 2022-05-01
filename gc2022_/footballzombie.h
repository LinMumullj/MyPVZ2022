#ifndef FOOTBALLZOMBIE_H
#define FOOTBALLZOMBIE_H
#include"zombie.h"
class FootballZombie : public Zombie{
public:
    FootballZombie(int x,int y):Zombie(x,y){
        attackvalue=15;
        speed=20;
        maxHP=250;
        HP=250;

        if(img)
            delete img;
        img=new QMovie(":/image/FootballZombieWalk.gif");
        img->start();
        attackimg=new QMovie(":/image/FootballZombieAttack.gif");
        attackimg->start();
        pushPath();
    }
};

#endif // FOOTBALLZOMBIE_H
