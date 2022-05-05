#ifndef ARMY_H
#define ARMY_H
#include <QGraphicsItem>
#include <QtWidgets>
#include <QPainter>
#include<vector>
using namespace std;
class Army : public QGraphicsItem
{
protected:
    QMovie* img;
    QMovie* attackimg;
public:
    int cnt;
    int HP;
    int maxHP;
    int attackvalue;
    int speed;
    int state;//0走1攻击
    Army(){
        cnt=0;
        HP=100;
        maxHP=100;
        attackvalue=10;
        speed=20;
        state=0;
    }

    //绑定矩形
    QRectF boundingRect() const override{
        return QRectF(0,0,100,100);
    }
    //以局部坐标绘制项目的内容
    //在QGraphicsItem子类中重新实现此函数，以使用painter提供项目的绘制实现。
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override{
        Q_UNUSED(option)
        Q_UNUSED(widget)
        if(state==0){
            painter->drawImage(boundingRect(), img->currentImage());
        }else{
            painter->drawImage(boundingRect(), attackimg->currentImage());
        }

        painter->setBrush(Qt::white);
        painter->drawRect(0,0,100,10);
        painter->setBrush(Qt::red);
        painter->drawRect(0,0,100*HP/maxHP,10);
    }

    //默认如果其他项与此项的形状相交、包含或被此项的形状包含，则其他项会与此项发生冲突
//    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override{

//    }
    void advance(int phase) override{
        if(!phase)
            return;
        update();
    }
};

#endif // ARMY_H
