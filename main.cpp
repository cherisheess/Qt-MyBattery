#include "mybattery.h"

#include <QApplication>
#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyBattery m;
    m.show();

    widget w;
    w.show();

    return a.exec();
}
