cmake_minimum_required(VERSION 3.9.3)

set(OpenCV_DIR "C:/opencv/opencvInstall")

find_package(OpenCV    3.3.0    REQUIRED)

project (CompProject)

add_subdirectory(CV)

add_subdirectory(GUI)

