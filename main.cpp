#include <QApplication>
#include "MyMenu.h"
#include "MyMainWindow.h"

int main(int argc, char **argv)
{
    QApplication app (argc, argv);
    MyMainWindow *mainwin = new MyMainWindow();
    return app.exec();
}