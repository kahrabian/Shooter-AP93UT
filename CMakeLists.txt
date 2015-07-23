cmake_minimum_required(VERSION 3.2)
project(Shooter-AP93UT)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(SOURCE_FILES main.cpp)
add_executable(Shooter-AP93UT ${SOURCE_FILES} "Sources/Source Files/Widgets/MyMenu.cpp" Sources/Headers/Widgets/MyMenu.h "Sources/Source Files/MyMainWindow.cpp" Sources/Headers/MyMainWindow.h "Sources/Source Files/Widgets/MyTutorial.cpp" Sources/Headers/Widgets/MyTutorial.h "Sources/Source Files/Widgets/MySetting.cpp" Sources/Headers/Widgets/MySetting.h Sources/Headers/SettingData.h Sources/Headers/Resources.h "Sources/Source Files/Resources.cpp" Sources/Headers/Settings/MymodeTab.h "Sources/Source Files/Settings/MymodeTab.cpp" Sources/Headers/Settings/MythmTab.h "Sources/Source Files/Settings/MythmTab.cpp" Sources/Headers/Settings/MyaudioTab.h "Sources/Source Files/Settings/MyaudioTab.cpp"  Sources/Headers/Settings/MyaiTab.h "Sources/Source Files/Settings/MyaiTab.cpp" Sources/Headers/Widgets/MyGame.h "Sources/Source Files/Widgets/MyGame.cpp" Sources/Headers/Game\ Objects/MyShip.h "Sources/Source Files/Game Objects/MyShip.cpp" Sources/Headers/Game\ Objects/MyAlien.h Sources/Headers/Game\ Objects/MyBullet.h Sources/Headers/Game\ Objects/MyAsteroid.h Sources/Headers/Game\ Objects/MyStar.h Sources/Headers/Game\ Objects/MyLife.h Sources/Headers/Game\ Objects/MyShield.h Sources/Headers/Game\ Objects/MyShipShield.h Sources/Headers/Game\ Objects/MyMagic.h "Sources/Source Files/Game Objects/MyAlien.cpp" "Sources/Source Files/Game Objects/MyAsteroid.cpp" "Sources/Source Files/Game Objects/MyBullet.cpp" "Sources/Source Files/Game Objects/MyLife.cpp" "Sources/Source Files/Game Objects/MyShield.cpp" "Sources/Source Files/Game Objects/MyStar.cpp" Sources/Headers/Widgets/MyName.h "Sources/Source Files/Widgets/MyName.cpp" Sources/Headers/Widgets/MyPause.h "Sources/Source Files/Widgets/MyPause.cpp" Sources/Headers/Widgets/MyEnd.h "Sources/Source Files/Widgets/MyEnd.cpp" "Sources/Source Files/Game Objects/MyMagic.cpp" "Sources/Source Files/Game Objects/MyShipShield.cpp" "Sources/Headers/Game Objects/MyExplosion.h" "Sources/Source Files/Game Objects/MyExplosion.cpp")

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Multimedia REQUIRED)

qt5_use_modules(Shooter-AP93UT Core Widgets Gui Multimedia)
target_link_libraries(Shooter-AP93UT Qt5::Widgets Qt5::Gui Qt5::Core Qt5::Multimedia)