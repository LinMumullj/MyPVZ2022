#ifndef SUNMANAGER_H
#define SUNMANAGER_H
#include <QGraphicsItem>
#include <QtWidgets>
#include <QPainter>

class SunManager : public QGraphicsItem
{
public:
    QImage* img;
    int gameHP;
    int sun;
    SunManager(int x,int y,int sun,int gameHP){
        this->setX(x);
        this->setY(y);
        this->sun=sun;
        this->gameHP=gameHP;
        img=new QImage(":/image/Button.png");
    }
    //绑定矩形
    QRectF boundingRect() const override{
        return QRectF(0,0,300,100);
    }
    //以局部坐标绘制项目的内容
    //在QGraphicsItem子类中重新实现此函数，以使用painter提供项目的绘制实现。
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override{
        Q_UNUSED(option)
        Q_UNUSED(widget)
        painter->drawImage(boundingRect(), *img);

        painter->setFont(QFont(("宋体"),18,10));
        //painter->drawText(QRectF(15,25,80,80),"阳光：");
        painter->drawImage(QRectF(110,10,80,80),QImage(":/image/Sun.gif"));
        painter->setPen(Qt::yellow);
        painter->drawText(QRectF(200,25,80,80),QString::number(sun));

        painter->setPen(Qt::red);
        painter->setFont(QFont(("宋体"),18,15));
        painter->drawText(QRectF(30,25,80,80),QString::number(gameHP));



    }
    void advance(int phase) override{
        if(!phase)
            return;
        update();
    }

    void deHP(){
        gameHP--;
        if(gameHP==0){
            emit GameOver();
        }
    }
signals:
    void GameOver();
};

#endif // SUNMANAGER_H
