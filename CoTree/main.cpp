#include "CoTree.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CoTree w;
    w.show();
    return a.exec();
}
