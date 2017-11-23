cmake_minimum_required(VERSION 3.9.3)

project (PrototypeImgApp)
set(CMAKE_INSTALL_PREFIX "C:/opencv/ProjectAppsInstall")
set(OpenCV_DIR "C:/opencv/opencvInstall")
set(OpenCV_B "C:/opencv/opencvInstall/x64/vc15/bin")
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
find_package(OpenCV    3.3.0    REQUIRED)

include_directories(
  ${OpenCV_INCLUDE_DIRS}
)

add_executable(PrototypeImgApp
	PrototypeImg.cpp
)

target_link_libraries(PrototypeImgApp ${OpenCV_LIBS})