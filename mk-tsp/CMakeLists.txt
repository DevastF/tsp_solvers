cmake_minimum_required(VERSION 2.8)
project(mk-etsp)

set(SOURCE_FILES
   src/coords.cc
   src/mkgreed.cc
   src/route_path_utils.cc
   )

add_executable(tmk-tsp src/tmk-tsp.cc ${SOURCE_FILES})
target_include_directories(tmk-tsp PUBLIC ${CMAKE_BINARY_DIR}/include) 
target_link_libraries(tmk-tsp crl-algorithm crl-gui)

install(TARGETS tmk-tsp DESTINATION .)
install(FILES tmk-tsp.cfg DESTINATION .)
install(DIRECTORY etc DESTINATION .)

