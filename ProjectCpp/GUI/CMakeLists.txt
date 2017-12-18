cmake_minimum_required(VERSION 3.9.3)

project(GUI)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})
find_package(Qt5Widgets)
find_package(Qt5Gui)
find_package(Qt5Core)
find_package(QT5)

set(GUI_SRCS 
dialog.cpp
moc_settings.cpp
main.cpp
mainwindow.cpp
moc_mainwindow.cpp
settings.cpp
moc_settings.cpp
)

set(GUI_HEADERS
dialog.h
mainwindow.h
ui_mainwindow.h
moc_predefs.h
settings.h
ui_settings.h
ui_dialog.h
) 

add_executable(GUI ${GUI_SRCS} ${GUI_HEADERS})


target_link_libraries(GUI
     Qt5::Widgets
     Qt5::Core
     Qt5::Gui
)