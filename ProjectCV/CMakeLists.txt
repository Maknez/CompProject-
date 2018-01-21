cmake_minimum_required(VERSION 3.9.3)
set(OpenCV_DIR "C:/opencv/opencvInstall")
find_package(OpenCV    3.3.0    REQUIRED)


project(ProjectCV)



include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR} ${OpenCV_INCLUDE_DIRS})
find_package(Qt5Widgets)
find_package(Qt5Gui)
find_package(Qt5Core)
find_package(QT5)


set(ProjectCV_SRCS
CV.cpp
Finder.cpp
FindSquare.cpp
FlashFinder.cpp
FrameFinder.cpp
game.cpp
icon.cpp
main.cpp
moc_game.cpp
settings.cpp
ViewTransformation.cpp
)

set(ProjectCV_HEADERS
CV.h
Finder.h
FindSquare.h
FlashFinder.h
FrameFinder.h
game.h
icon.h
settings.h
ViewTransformation.h
) 

add_executable(ProjectCV ${ProjectCV_SRCS} ${ProjectCV_HEADERS})


target_link_libraries(ProjectCV
     Qt5::Widgets
     Qt5::Core
     Qt5::Gui
${OpenCV_LIBS}
)