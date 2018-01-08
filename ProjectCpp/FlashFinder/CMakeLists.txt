project (FlashFinderApp)

include_directories(
  ${OpenCV_INCLUDE_DIRS}
)

add_executable(FlashFinderApp
	Finder.h
	Finder.cpp
	FlashFinder.h
	FlashFinder.cpp
	main.cpp
)

target_link_libraries(FlashFinderApp ${OpenCV_LIBS})