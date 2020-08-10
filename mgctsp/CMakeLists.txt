cmake_minimum_required(VERSION 2.8)
project(mtspc)

set(SOURCE_FILES
   ../../../CLionProjects/PowerlineTSP/src/coords.cc
   src/grasp-constrained.cc
   )

include_directories(include)

add_executable(t_mgctsp src/t_mgctsp.cc ${SOURCE_FILES})
target_include_directories(t_mgctsp PUBLIC ${CMAKE_BINARY_DIR}/include) 
target_link_libraries(t_mgctsp crl-algorithm crl-gui)

install(TARGETS t_mgctsp DESTINATION .)
install(FILES t_mgctsp.cfg DESTINATION .)
install(DIRECTORY etc DESTINATION .)

