project (CV)

include_directories(
  ${OpenCV_INCLUDE_DIRS}	
)

add_executable(CV
	ViewTransformation.h
	ViewTransformation.cpp
	Finder.h
	Finder.cpp
	main.cpp
	FindSquare.cpp
	FindSquare.h
	FrameFinder.cpp
	FrameFinder.h
	CV.cpp
	CV.h
	FlashFinder.cpp
	FlashFinder.h
	mainFromFlashFinder.cpp
)

target_link_libraries(CV ${OpenCV_LIBS})