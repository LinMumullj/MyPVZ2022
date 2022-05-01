QT       += core gui
QT += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aircraft.cpp \
    army.cpp \
    armyshop.cpp \
    balloonzombie.cpp \
    block.cpp \
    bullet.cpp \
    main.cpp \
    mainwindow.cpp \
    map.cpp \
    peanut.cpp \
    peashooter.cpp \
    playwindows.cpp \
    shop.cpp \
    snowshooter.cpp \
    sunflower.cpp \
    sunmanager.cpp \
    tower.cpp \
    winwindows.cpp \
    zombie.cpp

HEADERS += \
    aircraft.h \
    army.h \
    armyshop.h \
    balloonzombie.h \
    block.h \
    bucketzombie.h \
    bullet.h \
    conezombie.h \
    footballzombie.h \
    mainwindow.h \
    map.h \
    peanut.h \
    peashooter.h \
    playwindows.h \
    shop.h \
    snowshooter.h \
    sunflower.h \
    sunmanager.h \
    tower.h \
    winwindows.h \
    zombie.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    qrs.qrc

DISTFILES += \
    save1.txt
