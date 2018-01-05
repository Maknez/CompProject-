project (FlashFinderApp)

include_directories(
  ${OpenCV_INCLUDE_DIRS}
)

add_executable(FlashFinderApp
	FlashFinder.cpp
)

target_link_libraries(FlashFinderApp ${OpenCV_LIBS})
