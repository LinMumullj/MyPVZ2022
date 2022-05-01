#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMediaPlayer>
#include <QTimer>
#include"winwindows.h"
#include"map.h"
#include"block.h"
#include<QDebug>
#include"shop.h"
#include<vector>
//#include"tower.h"
#include"peashooter.h"
#include"snowshooter.h"
#include"peanut.h"
#include"sunflower.h"
//#include"army.h"
//#include"zombie.h"
#include"sunmanager.h"
#include"balloonzombie.h"
#include"conezombie.h"
#include"bucketzombie.h"
#include"footballzombie.h"
#include"armyshop.h"
using namespace std;
class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QMediaPlayer* AdvenceMediaPlayer;
    QTimer *timer;
    QTimer *addtimer;
    QGraphicsScene *scene;
    QGraphicsView *view;
    Map *gamemap;
    Shop * tmpshop;
    SunManager* sunmanager;
    vector<Tower*>towers;
    //阳光量
    int sun;
    int gameHP;
    //在初始化窗口时将地方路径push入，每次敌方行走pop出

    vector<Aircraft*>aircrafts;
    vector<Army*>enemys;
    vector<Army*>ourarmys;
    //状态量：
    bool selecting=0;
    bool selecting2=0;
    bool pausing=0;

    //起点终点位置
    int qdx;
    int qdy;
    int zdx;
    int zdy;


    int cnt;//局部计时器
    int allzombiecnt;//一局游戏僵尸剩余数量
    int nowzombiecnt;//当前场上僵尸数量
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void mousePressEvent(QMouseEvent *mouse) override{
        int x=mouse->pos().x()/100;
        int y=mouse->pos().y()/100;
        int type=gamemap->map[x][y];
        if(type==9){
            pause();
            return;
        }
        if(y==0){
            if(x==11||x==12||x==13)
                return;
        }
        if(selecting){
            //选择框中tower
            int tx=tmpshop->x/100;
            int ty=tmpshop->y/100;

            if(x==tx && y==ty-1 && sunmanager->sun >= 100){
                //上方豌豆射手
                PeaShooter* t =new PeaShooter(tx*100,ty*100);
                scene->addItem(t);
                towers.push_back(t);
                sunmanager->sun-=100;
            }else if(x==tx && y==ty+1 && sunmanager->sun >= 150){
                //下方寒冰射手
                SnowShooter* t =new SnowShooter(tx*100,ty*100);
                scene->addItem(t);
                towers.push_back(t);
                sunmanager->sun-=150;
            }else if(x==tx-1 && y==ty && sunmanager->sun >= 50){
                //左方向日葵
                SunFlower* t =new SunFlower(tx*100,ty*100,sunmanager);
                scene->addItem(t);
                towers.push_back(t);
                sunmanager->sun-=50;
            }else if(x==tx+1 && y==ty && sunmanager->sun >= 100){
                //右方坚果
//                Peanut* t =new Peanut(tx*100,ty*100);
//                scene->addItem(t);
//                towers.push_back(t);
//                sunmanager->sun-=100;
            }else{

            }
            selecting=0;
            scene->removeItem(tmpshop);
            delete tmpshop;
        }
        else if(selecting2){
            //选择框中tower
            int tx=tmpshop->x/100;
            int ty=tmpshop->y/100;

            if(x==tx && y==ty-1 && sunmanager->sun >= 50){
                //上方豌豆射手
                Peanut* t =new Peanut(tx*100,ty*100);
                scene->addItem(t);
                towers.push_back(t);
                sunmanager->sun-=50;
            }else{

            }
            selecting2=0;
            scene->removeItem(tmpshop);
            delete tmpshop;
        }
        else{

            bool flag1=0;//flag为1代表已经有建筑了
            if(type==0){
                for(int i=0;i<towers.size();i++){
                    if(x==towers[i]->x()/100 && y==towers[i]->y()/100){
                        //已经有建筑了，升级
                        if(!(x>1100 && y<100))
                            flag1=1;
                        //
                    }
                }

                if(!flag1){
                    tmpshop = new Shop(x*100,y*100);
                    scene->addItem(tmpshop);
                    selecting=1;
                }
            }
            else if(type==1){
                for(int i=0;i<towers.size();i++){
                    if(x==towers[i]->x()/100 && y==towers[i]->y()/100){
                        //已经有建筑了，升级
                        if(!(x>1100 && y<100))
                            flag1=1;
                        //
                    }
                }

                if(!flag1){
                    tmpshop = new ArmyShop(x*100,y*100);
                    scene->addItem(tmpshop);
                    selecting2=1;
                }
            }
        }
    }
    void pause(){
        if(pausing){
            timer->start();
            addtimer->start();
        }else{
            timer->stop();
            addtimer->stop();
        }
        pausing=!pausing;
    }
    void winGame(){
        this->timer->stop();
        this->close();
        WinWindows* w=new WinWindows(1);
    }
    void loseGame(){
        this->timer->stop();
        this->close();
        WinWindows* w=new WinWindows(0);
    }
//    void checkWin(){

//    }
//    void checkLose(){
//        Block* tmp=qgraphicsitem_cast<Block* >(scene->itemAt(zdx,zdy,QTransform()));
//        if(!tmp->collidingItems().empty()){
//            loseGame();
//        }
//    }
public slots:
    void addZombie(){

        cnt++;
        if(cnt<3){
            return;
        }
        cnt=0;
        if(allzombiecnt>90){
            Zombie* t=new Zombie(qdx,qdy);
            scene->addItem(t);
            enemys.push_back(t);
        }else if(allzombiecnt>80){
            ConeZombie* t=new ConeZombie(qdx,qdy);
            scene->addItem(t);
            enemys.push_back(t);
        }else if(allzombiecnt>70){
            BucketZombie* t=new BucketZombie(qdx,qdy);
            scene->addItem(t);
            enemys.push_back(t);
        }else if(allzombiecnt>0){
            FootballZombie* t=new FootballZombie(qdx,qdy);
            scene->addItem(t);
            enemys.push_back(t);
        }else{
            return;
        }
        nowzombiecnt++;
        allzombiecnt--;
        if(allzombiecnt<=0){
            return;
        }


        if(allzombiecnt<50){
            cnt++;
            if(cnt==6){
                cnt=0;
                BalloonZombie* a=new BalloonZombie(qdx,qdy);
                scene->addItem(a);
                aircrafts.push_back(a);
                allzombiecnt--;
                nowzombiecnt++;
                if(allzombiecnt<=0){
                    return;
                }
            }
        }
    }
    void checkWin(){
        if(nowzombiecnt==0 && allzombiecnt<=0){
            winGame();
        }
    }
    void checkLose(){
        //Block* tmp=qgraphicsitem_cast<Block* >(scene->itemAt(zdx,zdy,QTransform()));
        //


        for(auto it=enemys.begin();it!=enemys.end();){
            if((*it)->x()==zdx && (*it)->y()==zdy){
                sunmanager->gameHP--;

                qDebug()<<"跑了一个僵尸";

                scene->removeItem(*it);
                Army* p=*it;
                enemys.erase(it);
                delete p;
                nowzombiecnt--;
            }else if((*it)->HP<=0){
                scene->removeItem(*it);
                Army* p=*it;
                enemys.erase(it);
                delete p;

                sunmanager->sun+=10;
                nowzombiecnt--;
            }else{
                it++;
            }
        }

        for(auto it=aircrafts.begin();it!=aircrafts.end();){
            if((*it)->x()==zdx && (*it)->y()==zdy){
                sunmanager->gameHP--;

                qDebug()<<"跑了一个僵尸";

                scene->removeItem(*it);
                Aircraft* p=*it;
                aircrafts.erase(it);
                delete p;

                nowzombiecnt--;
            }else if((*it)->HP<=0){
                scene->removeItem(*it);
                Aircraft* p=*it;
                aircrafts.erase(it);
                delete p;

                sunmanager->sun+=10;

                nowzombiecnt--;
            }else{
                it++;
            }
        }

        for(auto it=towers.begin();it!=towers.end();){
            if((*it)->HP<=0){
                scene->removeItem(*it);
                Tower* p=*it;
                towers.erase(it);
                delete p;
            }else{
                it++;
            }
        }

//        for(int i=0;i<enemys.size();i++){
//            if(enemys[i]->x()==zdx && enemys[i]->y()==zdy){
//                gameHP--;
//                scene->removeItem(enemys[i]);
//                enemys.erase(enemys.begin()+i);
//                delete enemys[i];
//            }
//        }
        if(sunmanager->gameHP<=0){
            loseGame();
        }

    }
};


#endif // MAINWINDOW_H
