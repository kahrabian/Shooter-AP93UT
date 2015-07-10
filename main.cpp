#include <QApplication>
#include <Sources/Headers/MyMainWindow.h>

int SettingData::gMode = 1;
int SettingData::gDiff = 1;
int SettingData::uShp = 0;
int SettingData::aln = 0;
int SettingData::env = 0;
int SettingData::mVol = 50;
bool SettingData::mMut = false;
int SettingData::sfVol = 50;
bool SettingData::sfMut = false;
int SettingData::aiDiff = 1;
int SettingData::aiShp = 0;

int main(int argc, char **argv)
{
    QApplication *app = new QApplication(argc, argv);
    MyMainWindow *mainwin = new MyMainWindow();
    return app->exec();
}