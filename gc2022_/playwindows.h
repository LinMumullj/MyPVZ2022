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
};

#endif // PLAYWINDOWS_H
