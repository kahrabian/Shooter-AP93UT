cmake_minimum_required(VERSION 3.2)
project(Shooter-AP93UT)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(SOURCE_FILES main.cpp)
add_executable(Shooter-AP93UT ${SOURCE_FILES} "Sources/Source Files/MyMenu.cpp" Sources/Headers/MyMenu.h "Sources/Source Files/MyMainWindow.cpp" Sources/Headers/MyMainWindow.h "Sources/Source Files/MyTutorial.cpp" Sources/Headers/MyTutorial.h "Sources/Source Files/MySetting.cpp" Sources/Headers/MySetting.h Sources/Headers/SettingData.h Sources/Headers/SettingData.h Sources/Headers/Resources.h "Sources/Source Files/Resources.cpp" Sources/Headers/MymodeTab.h "Sources/Source Files/MymodeTab.cpp" Sources/Headers/MythmTab.h "Sources/Source Files/MythmTab.cpp" Sources/Headers/MyaudioTab.h "Sources/Source Files/MyaudioTab.cpp"  Sources/Headers/MyaiTab.h "Sources/Source Files/MyaiTab.cpp")

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Multimedia REQUIRED)

qt5_use_modules(Shooter-AP93UT Core Widgets Gui Multimedia)
target_link_libraries(Shooter-AP93UT Qt5::Widgets Qt5::Gui Qt5::Core Qt5::Multimedia)