cmake_minimum_required(VERSION 2.8)
project(edge-traversal)

(SOURCE_FILES
   src/edge_traversal.cc
   )

add_executable(edge-traversal src/edge-traversal.cc ${SOURCE_FILES})
target_include_directories(edge-traversal PUBLIC ${CMAKE_BINARY_DIR}/include) 
target_link_libraries(edge-traversal)

install(TARGETS edge-traversal DESTINATION .)

