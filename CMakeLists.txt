cmake_minimum_required(VERSION 3.2)
project(Shooter-AP93UT)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(SOURCE_FILES main.cpp)
add_executable(Shooter-AP93UT ${SOURCE_FILES} MyMenu.cpp MyMenu.h MyMainWindow.cpp MyMainWindow.h MyTutorial.cpp MyTutorial.h MySetting.cpp MySetting.h)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)
qt5_use_modules(Shooter-AP93UT Core Widgets Gui)
target_link_libraries(Shooter-AP93UT Qt5::Widgets Qt5::Gui Qt5::Core)