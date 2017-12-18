project (FrameFinderApp)

include_directories(
  ${OpenCV_INCLUDE_DIRS}
)

add_executable(FrameFinderApp
	FrameFinder.cpp
)

target_link_libraries(FrameFinderApp ${OpenCV_LIBS})