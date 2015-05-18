#include "mainwindow.h"
#include "ourstormgame.h"

#include <QSize>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OurStormGame game(QSize(400,600));
    MainWindow w(&game);
    return a.exec();
}
