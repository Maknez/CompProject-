cmake_minimum_required(VERSION 3.9.3)

project(GUI)



include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})
find_package(Qt5Widgets)
find_package(Qt5Gui)
find_package(Qt5Core)
find_package(QT5)
set(CMAKE_AUTOMOC OFF)
SET(CMAKE_AUTOUIC OFF)  



set(GUI_SRCS 
main.cpp
mainwindow.cpp
)
#set(GUI_UIS 
#mainwindow.ui
#)
qt5_wrap_ui(GUI_UI2H mainwindow.ui)

set(GUI_HEADERS
mainwindow.h
${GUI_UI2H}
) 

#qt5_automoc(${qm2cm_SRCS})

add_executable(GUI ${GUI_SRCS} ${GUI_HEADERS})
#target_link_libraries(GUI ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})

target_link_libraries(GUI
     Qt5::Widgets
     Qt5::Core
     Qt5::Gui
)