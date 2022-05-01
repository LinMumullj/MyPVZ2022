#ifndef AIRCRAFT_H
#define AIRCRAFT_H
#include <QGraphicsItem>
#include <QtWidgets>
#include <QPainter>

class Aircraft : public QGraphicsItem
{
protected:
    QImage* img;
public:
    int HP;
    int maxHP;
    int attack;
    int speed;
    Aircraft(){
        HP=100;
        maxHP=100;
        attack=10;
        speed=10;
    }
    //设置图片
    void setImg(QString path){

    }
    //绑定矩形
    QRectF boundingRect() const override{
        return QRectF(0,0,50,100);
    }
    //以局部坐标绘制项目的内容
    //在QGraphicsItem子类中重新实现此函数，以使用painter提供项目的绘制实现。
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override{
        Q_UNUSED(option)
        Q_UNUSED(widget)
        painter->drawImage(boundingRect(), *img);
        painter->setBrush(Qt::white);
        painter->drawRect(-25,0,100,10);
        painter->setBrush(Qt::red);
        painter->drawRect(-25,0,100*HP/maxHP,10);
    }

    //默认如果其他项与此项的形状相交、包含或被此项的形状包含，则其他项会与此项发生冲突
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override{

    }
};

#endif // AIRCRAFT_H
