project (PrototypeImgApp)

include_directories(
  ${OpenCV_INCLUDE_DIRS}
)

add_executable(PrototypeImgApp
	PrototypeImg.cpp
)

target_link_libraries(PrototypeImgApp ${OpenCV_LIBS})