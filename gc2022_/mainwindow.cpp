#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    bullets = new vector<Bullet*>;
    //数据初始化
    qdx=0;
    qdy=1200;
    zdx=1400;
    zdy=1200;

    cnt=0;
    cnt2=0;
    sun=200;
    gameHP=10;

    allzombiecnt=100;
    nowzombiecnt=0;
    //背景音乐的播放
    AdvenceMediaPlayer = new QMediaPlayer;
    AdvenceMediaPlayer->setMedia(QUrl("qrc:/sound/bgm1.mp3"));
    AdvenceMediaPlayer->setVolume(50);
    AdvenceMediaPlayer->play();



    //初始化scene和view
    scene = new QGraphicsScene(this);
    //scene->setSceneRect(0, 0, 500, 500);
    scene->setSceneRect(0, 0, 1500, 1500);
    //scene->setBackgroundBrush(QPixmap(":/images/Background2.png"));



    view = new QGraphicsView(scene,this);
    view->resize(1520,1520);
    view->setRenderHint(QPainter::Antialiasing);
    //view->setBackgroundBrush(QPixmap(":/images/Background2.png"));
    view->setCacheMode(QGraphicsView::CacheBackground);     //控制view的那一部分现在在缓存中，
    //CacheBackground标志使能view的背景缓存，例如
    //QGraphicsView view;
    //view.setBackgroundBrush(QImage(":/images/backgroundtile.png"));
    //view.setCacheMode(QGraphicsView::CacheBackground);每次view转换后cache就无效了，然而，当滚动区域时候，只有部分无效默认的，没有使用cache
    //这个属性控制着viewport应该如何刷新他的内容
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    view->show();



    gamemap=new Map;
    //QPainter painter(this);
    for(int i=0;i<gamemap->getMapsize();i++){
        for(int j=0;j<gamemap->getMapsize();j++){
            int tmp=gamemap->map[i][j];
            //painter.drawPixmap(i*100,j*100,100,100,QPixmap(":/image/wall/brick.gif"));
            Block* b=new Block(tmp);
            b->setPos(i*100,j*100);
            scene->addItem(b);
        }
    }
    pausebutton=new Block(9);
    pausebutton->setImg(":/image/continue.png");
    pausebutton->setPos(1400,0);
    scene->addItem(pausebutton);

    //加入全局管理器
    sunmanager = new SunManager(1000,0,sun,gameHP);
    scene->addItem(sunmanager);

    //加僵尸
    addtimer=new QTimer(this);
    //connect(timer,SIGNAL(timeout()),this,SLOT(update()));//重画
    connect(addtimer, SIGNAL(timeout()), this, SLOT(addZombie()));
    addtimer->start(2000);





    timer=new QTimer(this);
    //connect(timer,SIGNAL(timeout()),this,SLOT(update()));//重画
    connect(timer, &QTimer::timeout, scene, &QGraphicsScene::advance);
    connect(timer, &QTimer::timeout, this, &MainWindow::checkWin);
    connect(timer, &QTimer::timeout, this, &MainWindow::checkLose);
    timer->start(80);
}

MainWindow::~MainWindow()
{
}


