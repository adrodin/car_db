cmake_minimum_required(VERSION 3.17)
project(v3)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR ON)


find_package(Qt5Widgets REQUIRED)


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

include_directories(src include libs)


add_executable(v3 main.cpp include/mainWindow.h src/mainWindow.cpp
        include/addDialog.h src/addDialog.cpp include/addWidget.h
        src/addWidget.cpp include/updateDialog.h src/updateDialog.cpp
        include/updateWidget.h src/updateWidget.cpp include/findDialog.h
        include/findWidget.h src/findDialog.cpp src/findWidget.cpp include/car.h
        src/car.cpp libs/sqlite3/sqlite3.h libs/sqlite3/sqlite3.c include/dbMenager.h
        src/dbMenager.cpp src/messageWindow.cpp include/messageWindow.h include/showCar.h
        src/showCar.cpp include/updateWindow.h src/updateWindow.cpp)

target_link_libraries(v3 Qt5::Widgets)



