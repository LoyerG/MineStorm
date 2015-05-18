#-------------------------------------------------
#
# Project created by QtCreator 2014-11-29T18:41:50
#
#-------------------------------------------------

QT       += core gui
QMAKE_CXXFLAGS += -std=c++0x

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OurStorm
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    controller.cpp \
    gameboard.cpp \
    game.cpp \
    ourstormgame.cpp \
    drawableobject.cpp \
    spaceship.cpp \
    bullet.cpp \
    star.cpp \
    heartdrawablestrategy.cpp \
    bulletdrawablestrategy.cpp \
    spaceshipdrawablestrategy.cpp \
    staralivedrawablestrategy.cpp \
    starborndrawablestrategy.cpp \
    explodedrawablestrategy.cpp \
    drawablestrategy.cpp \
    starship.cpp \
    starshipdrawablestrategy.cpp

HEADERS  += mainwindow.h \
    controller.h \
    gameboard.h \
    game.h \
    ourstormgame.h \
    drawableobject.h \
    spaceship.h \
    bullet.h \
    star.h \
    heartdrawablestrategy.h \
    bulletdrawablestrategy.h \
    drawablestrategy.h \
    explodedrawablestrategy.h \
    spaceshipdrawablestrategy.h \
    staralivedrawablestrategy.h \
    starborndrawablestrategy.h \
    starship.h \
    starshipdrawablestrategy.h

RESOURCES = ressources.qrc
