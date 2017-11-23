cmake_minimum_required(VERSION 3.9.3)

project (FlashFinderApp)

set(OpenCV_DIR "C:/opencv/opencvInstall")
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)


find_package(OpenCV    3.3.0    REQUIRED)

include_directories(
  ${OpenCV_INCLUDE_DIRS}
)

add_executable(FlashFinderApp
	FlashFinder.cpp
)

target_link_libraries(FlashFinderApp ${OpenCV_LIBS})
