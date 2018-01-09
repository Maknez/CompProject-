cmake_minimum_required(VERSION 3.9.3)

set(OpenCV_DIR "C:/opencv/opencvInstall")

find_package(OpenCV    3.3.0    REQUIRED)

project (CompProject)

add_subdirectory(FlashFinder)

add_subdirectory(FrameFinder)

add_subdirectory(ViewTransformation)

add_subdirectory(PrototypeCam)

add_subdirectory(GUI)

add_subdirectory(PrototypeShowBinaryCam)