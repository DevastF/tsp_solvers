# Install script for directory: /home/mrs/CLionProjects/PowerlineTSPmake/crl

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/mrs/CLionProjects/PowerlineTSPmake/cmake-build-debug/crl/crl/cmake_install.cmake")
  include("/home/mrs/CLionProjects/PowerlineTSPmake/cmake-build-debug/crl/crl.gui/cmake_install.cmake")
  include("/home/mrs/CLionProjects/PowerlineTSPmake/cmake-build-debug/crl/crl.algorithm/cmake_install.cmake")
  include("/home/mrs/CLionProjects/PowerlineTSPmake/cmake-build-debug/crl/crl.loader/cmake_install.cmake")
  include("/home/mrs/CLionProjects/PowerlineTSPmake/cmake-build-debug/crl/crl.tsplib/cmake_install.cmake")

endif()

