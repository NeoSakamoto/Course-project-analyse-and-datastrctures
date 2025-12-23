#include <QApplication>
#include "menu.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Menu w;
    w.show();
    return app.exec();
}
