#include <QApplication>
#include <Sources/Headers/MyMainWindow.h>

QString SettingData::p1_nm = "Player 1";
QString SettingData::p2_nm = "Player 2";
int SettingData::gMode = 1;
int SettingData::gDiff = 1;
int SettingData::uShp = 0;
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
    app->exec();
	delete app;
	delete mainwin;
    return 0;
}