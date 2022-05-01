#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsItem>
#include <QtWidgets>
#include <QPainter>

class Bullet : public QGraphicsItem
{
public:
    QImage* img;
    int x;
    int y;
    Bullet(int x,int y){
        this->setX(x);
        this->setY(y);
        this->x=x;
        this->y=y;
        img=new QImage(":/image/Pea.png");
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
};

#endif // BULLET_H
