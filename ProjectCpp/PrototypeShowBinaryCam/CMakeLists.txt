project (PrototypeShowBinaryCam)

include_directories(
  ${OpenCV_INCLUDE_DIRS}
)

add_executable(PrototypeShowBinaryCam
	PrototypeShowBinaryCam.cpp
)

target_link_libraries(PrototypeShowBinaryCam ${OpenCV_LIBS})
