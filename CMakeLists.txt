cmake_minimum_required(VERSION 3.25)
project(OhMyTask)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/Users/russ/Qt/6.5.1/macos/lib/cmake")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(OhMyTask main.cpp test.cpp test.h test.ui)
target_link_libraries(OhMyTask
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

