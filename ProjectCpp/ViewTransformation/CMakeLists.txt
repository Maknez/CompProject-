project (ViewTranformation)

include_directories(
  ${OpenCV_INCLUDE_DIRS}
)

add_executable(ViewTranformation
	ViewTransformation.h
	ViewTransformation.cpp
	Finder.h
	Finder.cpp
	main.cpp
	FindSquare.cpp
	FindSquare.h
)

target_link_libraries(ViewTranformation ${OpenCV_LIBS})