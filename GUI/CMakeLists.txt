cmake_minimum_required(VERSION 3.9.3)

project(GUI)

set(CMAKE_PREFIX_PATH "C:/Qt/5.9.2/msvc2017_64")
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

set ( SOURCES
 main.cpp
 mainwindow.cpp
)

set ( MOC_HEADERS mainwindow.h)
set ( UIS mainwindow.ui)


find_package(Qt5Widgets)
find_package(Qt5Gui)
find_package(Qt5Core)

add_executable(GUI
     main.cpp
     mainwindow.cpp
     mainwindow.h
)

target_link_libraries(GUI
     Qt5::Widgets
     Qt5::Core
     Qt5::Gui
)
