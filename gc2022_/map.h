#ifndef MAP_H
#define MAP_H
#include <QGraphicsItem>
#include <QtWidgets>
#include <QPainter>
#include <fstream>
#include <iostream>
#include<QDebug>
#include<vector>
#include"tower.h"
#include"army.h"
#include"aircraft.h"
#include"block.h"
using namespace std;

class Map
{
private:
    //gamemap  0为山体，1为路径，//2为Tower，3为army，4为aircraft, //5为起点, 6为终点

    int mapsize;


public:
    int **map;
    vector<Tower>towers;
    Map(){

        mapsize=15;
        map=new int*[mapsize];
        for(int i=0;i<mapsize;i++){
            map[i]=new int[mapsize];
            for(int j=0;j<mapsize;j++){
                map[i][j]=0;
            }
        }
        //初始地图save1.txt
        LoadMap("D:\\Qtcode\\gc2022_\\save1.txt");
    }
    void LoadMap(string path){
        ifstream is(path);
        if(!is)
            qDebug()<<"file not exist";

        for(int i=0;i<mapsize;i++){
            for(int j=0;j<mapsize;j++){
                is>>map[j][i];
                //qDebug()<<map[i][j]<<' ';
            }
        }
    }
    int getMapsize(){
        return mapsize;
    }
};

#endif // MAP_H
