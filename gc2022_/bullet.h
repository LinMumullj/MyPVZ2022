#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsItem>
#include <QtWidgets>
#include <QPainter>
#include<math.h>
class Bullet : public QGraphicsItem
{
public:
    enum { Type = UserType + 8};
    int type()const override{
        return Type;
    }
    QImage* img;
    QPoint* dest;
    int xmovevalue;
    int ymovevalue;
    float xspeed;
    float yspeed;

    bool islive;
    Bullet(int x,int y,int type,QPoint* dest){
        islive=1;
        this->setX(x);
        this->setY(y);
        this->dest=dest;
        xmovevalue=dest->x()-this->x();
        ymovevalue=dest->y()-this->y();
        xspeed=35*xmovevalue/sqrt(xmovevalue*xmovevalue+ymovevalue*ymovevalue);
        yspeed=qAbs(xspeed)*ymovevalue/qAbs(xmovevalue);
        if(type==0)
            img=new QImage(":/image/Pea.png");
        else{
            img=new QImage(":/image/PeaSnow.png");
        }
    }
    ~Bullet(){
        delete img;
        delete dest;
    }
    //绑定矩形
    QRectF boundingRect() const override{
        return QRectF(0,0,20,20);
    }
    //以局部坐标绘制项目的内容
    //在QGraphicsItem子类中重新实现此函数，以使用painter提供项目的绘制实现。
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override{
        Q_UNUSED(option)
        Q_UNUSED(widget)
        painter->drawImage(boundingRect(), *img);
    }

    //默认如果其他项与此项的形状相交、包含或被此项的形状包含，则其他项会与此项发生冲突
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override{

    }

    void advance(int phase) override{
        if(!phase)
            return;
        //update();
        if(xmovevalue * (dest->x()-this->x()-xspeed)>0)
        {
            setX(this->x()+xspeed);
            setY(this->y()+yspeed);
        }else{
            islive=0;
        }
        update();
    }
};

#endif // BULLET_H
