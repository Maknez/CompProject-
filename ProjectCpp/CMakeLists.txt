cmake_minimum_required(VERSION 3.9.3)

project (CompProject)
set(CMAKE_INSTALL_PREFIX "C:/opencv/ProjectAppsInstall")
add_subdirectory(FlashFinder)

add_subdirectory(FrameFinder)

add_subdirectory(PrototypeImg)

add_subdirectory(PrototypeCam)

add_subdirectory(GUI)