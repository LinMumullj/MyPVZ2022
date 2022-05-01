#ifndef SHOP_H
#define SHOP_H

#include <QGraphicsItem>
#include <QtWidgets>
#include <QPainter>
class Shop : public QGraphicsItem
{
protected:
    QImage* imgshop;
    QImage* imgu;
    QImage* imgd;
    QImage* imgl;
    QImage* imgr;

public:
    int x;
    int y;
    Shop(int x,int y){
        setZValue(3);
        this->setX(x);
        this->setY(y);
        this->x=x;
        this->y=y;
        imgshop=new QImage(":/image/marquee.PNG");
        imgu=new QImage(":/image/Repeater.png");
        imgd=new QImage(":/image/SnowPea.png");
        imgl=new QImage(":/image/SunFlower.png");
        imgr=new QImage(":/image/WallNut.png");
    }
    ~Shop(){
        delete imgshop;
        delete imgu;
        delete imgd;
        delete imgl;
        delete imgr;
    }
    //设置图片
    void setImg(QString path){

    }
    //绑定矩形
    QRectF boundingRect() const override{
        return QRectF(-100,-100,300,300);
    }
    //以局部坐标绘制项目的内容
    //在QGraphicsItem子类中重新实现此函数，以使用painter提供项目的绘制实现。
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override{
        Q_UNUSED(option)
        Q_UNUSED(widget)
        painter->drawImage(boundingRect(),*imgshop);
        painter->drawImage(QRectF(0,-100,100,100),*imgu);
        painter->drawImage(QRectF(0,100,100,100),*imgd);
        painter->drawImage(QRectF(-100,0,100,100),*imgl);
        //painter->drawImage(QRectF(100,0,100,100),*imgr);


//        painter->drawPixmap(x-100,y-100,300,300,QPixmap(":/image/marquee.PNG"));
//        painter->drawPixmap(x,y-100,100,100,QPixmap(":/image/Repeater.png"));
//        painter->drawPixmap(x,y+100,100,100,QPixmap(":/image/SnowPea.png"));
//        painter->drawPixmap(x-100,y,100,100,QPixmap(":/image/SunFlower.png"));
//        painter->drawPixmap(x+100,y,100,100,QPixmap(":/image/WallNut.png"));
    }
};

#endif // SHOP_H
