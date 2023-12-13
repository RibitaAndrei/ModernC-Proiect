#include "qt_intMain.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qt_intMain w;
    w.show();
    return a.exec();
}
