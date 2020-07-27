cmake_minimum_required(VERSION 2.8)
project(mtspc)

set(SOURCE_FILES
   src/coords.cc
   src/grasp-constrained.cc
   src/route_path_utils.cc
   )

include_directories(include)

add_executable(t_mtspc src/t_mtspc.cc ${SOURCE_FILES})
target_include_directories(t_mtspc PUBLIC ${CMAKE_BINARY_DIR}/include) 
target_link_libraries(t_mtspc crl-algorithm crl-gui)

install(TARGETS t_mtspc DESTINATION .)
install(FILES t_mtspc.cfg DESTINATION .)
install(DIRECTORY etc DESTINATION .)

