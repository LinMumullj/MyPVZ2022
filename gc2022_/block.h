#ifndef BLOCK_H
#define BLOCK_H
#include <QGraphicsItem>
#include <QtWidgets>
#include <QPainter>

class Block : public QGraphicsItem
{
protected:
    QImage* img;
    int type; //0墙 1路
public:
    enum { Type = UserType + 4};
    Block(int type){
        this->type=type;
        if(type==0){
            img=new QImage(":/image/wall/brick.gif");
        }else if(type==1){
            img=new QImage(":/image/wall/wood.gif");
        }else if(type==9){
            img=new QImage(":/image/continue.png");
        }
    }
    Block(const Block& t){
        this->type=t.type;
        if(type==0){
            img=new QImage(":/image/wall/brick.gif");
        }else if(type==1){
            img=new QImage(":/image/wall/wood.gif");
        }
        else if(type==9){
            img=new QImage(":/image/continue.png");
        }
    }
    ~Block(){
        delete img;
    }
    //设置图片
    void setImg(QString path){

    }
    //绑定矩形
    QRectF boundingRect() const override{
        return QRect(0,0,100,100);
    }
    //以局部坐标绘制项目的内容
    //在QGraphicsItem子类中重新实现此函数，以使用painter提供项目的绘制实现。
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override{
        Q_UNUSED(option)
        Q_UNUSED(widget)
        painter->drawImage(boundingRect(), *img);
    }
};

#endif // BLOCK_H
