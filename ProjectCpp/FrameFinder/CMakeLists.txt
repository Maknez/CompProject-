project (FrameFinderApp)

include_directories(
  ${OpenCV_INCLUDE_DIRS}
)

add_executable(FrameFinderApp
	Finder.h
	Finder.cpp
	FrameFinder.h
	FrameFinder.cpp
	main.cpp
)

target_link_libraries(FrameFinderApp ${OpenCV_LIBS})