#ifndef PLAYWINDOWS_H
#define PLAYWINDOWS_H
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMediaPlayer>
#include <QTimer>
#include"map.h"
class PlayWindows
{
private:
    Map gamemap;
public:
    PlayWindows();

    //加载map
    void LoadMap();
    //绘制map
    void PaintMap();
};

#endif // PLAYWINDOWS_H
