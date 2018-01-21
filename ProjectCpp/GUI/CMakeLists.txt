cmake_minimum_required(VERSION 3.9.3)

project(GUI)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR} ${OpenCV_INCLUDE_DIRS})
find_package(Qt5Widgets)
find_package(Qt5Gui)
find_package(Qt5Core)
find_package(QT5)


set(GUI_SRCS 
box.cpp
dialog.cpp
game.cpp
main.cpp
mainwindow.cpp
moc_dialog.cpp
moc_game.cpp
moc_mainwindow.cpp
settings.cpp
ViewTransformation.cpp
Finder.cpp
FindSquare.cpp
FrameFinder.cpp	
CV.cpp
FlashFinder.cpp
)

set(GUI_HEADERS
box.h
CV.h
dialog.h
Finder.h
FindSquare.h
FrameFinder.h	
FlashFinder.h
game.h
mainwindow.h
settings.h
ui_dialog.h
ui_game.h
ui_mainwindow.h
ViewTransformation.h
) 

add_executable(GUI ${GUI_SRCS} ${GUI_HEADERS})


target_link_libraries(GUI
     Qt5::Widgets
     Qt5::Core
     Qt5::Gui
${OpenCV_LIBS}
)