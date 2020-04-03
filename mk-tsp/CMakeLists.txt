cmake_minimum_required(VERSION 2.8)
project(mk-etsp)

set(SOURCE_FILES
   src/coords.cc
   src/mkgreed.cc
   src/route_path_utils.cc
   )

add_executable(mk-tsp src/mk-tsp.cc ${SOURCE_FILES})
target_include_directories(mk-tsp PUBLIC ${CMAKE_BINARY_DIR}/include) 
target_link_libraries(mk-tsp crl-algorithm crl-gui)

install(TARGETS mk-tsp DESTINATION .)
install(FILES mk-tsp.cfg DESTINATION .)
install(DIRECTORY etc DESTINATION .)

