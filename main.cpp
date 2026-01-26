#include <QApplication>
#include "loginwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    LoginWindow lw;
    lw.show();
    return app.exec();
}
