#ifndef TOWER_H
#define TOWER_H
#include <QGraphicsItem>
#include <QtWidgets>
#include <QPainter>

class Tower : public QGraphicsItem
{
protected:
    QMovie* img;

public:
    int attack;
    int HP;
    int maxHP;
    int cost;
    int cnt;
    enum { Type = UserType + 6};
    int type()const override{
        return Type;
    }
    Tower(int x,int y){
        this->setX(x);
        this->setY(y);
        attack=10;
        HP=100;
        maxHP=100;
        cost=50;
        cnt=0;
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
        painter->drawImage(boundingRect(), img->currentImage());
    }

    //默认如果其他项与此项的形状相交、包含或被此项的形状包含，则其他项会与此项发生冲突
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override{

    }
};

#endif // TOWER_H
