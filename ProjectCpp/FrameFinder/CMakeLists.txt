cmake_minimum_required(VERSION 3.9.3)

project (FrameFinderApp)

set(OpenCV_DIR "C:/opencv/opencvInstall")
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(OpenCV    3.3.0    REQUIRED)

include_directories(
  ${OpenCV_INCLUDE_DIRS}
)

add_executable(FrameFinderApp
	FrameFinder.cpp
)

target_link_libraries(FrameFinderApp ${OpenCV_LIBS})
