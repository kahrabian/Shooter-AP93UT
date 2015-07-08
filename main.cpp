#include <QApplication>
#include <Sources/Headers/MyMainWindow.h>

int main(int argc, char **argv)
{
    QApplication *app = new QApplication(argc, argv);
    MyMainWindow *mainwin = new MyMainWindow();
    return app->exec();
}