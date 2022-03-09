#include "nodewindow.h"

#include <QApplication>
#include <QtCore>
#include <QtGui>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NodeWindow w;
    w.show();
    return a.exec();
}
