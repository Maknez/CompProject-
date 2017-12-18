project (PrototypeCamApp)

include_directories(
  ${OpenCV_INCLUDE_DIRS}
)

add_executable(PrototypeCamApp
	PrototypeCam.cpp
)

target_link_libraries(PrototypeCamApp ${OpenCV_LIBS})
