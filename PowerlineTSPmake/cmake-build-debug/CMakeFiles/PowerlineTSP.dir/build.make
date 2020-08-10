# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/123/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/123/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mrs/CLionProjects/PowerlineTSPmake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mrs/CLionProjects/PowerlineTSPmake/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/PowerlineTSP.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PowerlineTSP.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PowerlineTSP.dir/flags.make

CMakeFiles/PowerlineTSP.dir/src/t_mgctsp.cc.o: CMakeFiles/PowerlineTSP.dir/flags.make
CMakeFiles/PowerlineTSP.dir/src/t_mgctsp.cc.o: ../src/t_mgctsp.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mrs/CLionProjects/PowerlineTSPmake/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PowerlineTSP.dir/src/t_mgctsp.cc.o"
	ccache /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PowerlineTSP.dir/src/t_mgctsp.cc.o -c /home/mrs/CLionProjects/PowerlineTSPmake/src/t_mgctsp.cc

CMakeFiles/PowerlineTSP.dir/src/t_mgctsp.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PowerlineTSP.dir/src/t_mgctsp.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mrs/CLionProjects/PowerlineTSPmake/src/t_mgctsp.cc > CMakeFiles/PowerlineTSP.dir/src/t_mgctsp.cc.i

CMakeFiles/PowerlineTSP.dir/src/t_mgctsp.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PowerlineTSP.dir/src/t_mgctsp.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mrs/CLionProjects/PowerlineTSPmake/src/t_mgctsp.cc -o CMakeFiles/PowerlineTSP.dir/src/t_mgctsp.cc.s

# Object files for target PowerlineTSP
PowerlineTSP_OBJECTS = \
"CMakeFiles/PowerlineTSP.dir/src/t_mgctsp.cc.o"

# External object files for target PowerlineTSP
PowerlineTSP_EXTERNAL_OBJECTS =

PowerlineTSP: CMakeFiles/PowerlineTSP.dir/src/t_mgctsp.cc.o
PowerlineTSP: CMakeFiles/PowerlineTSP.dir/build.make
PowerlineTSP: ../lib/libcrl.a
PowerlineTSP: ../lib/libcrl-algorithm.a
PowerlineTSP: ../lib/libcrl-gui.a
PowerlineTSP: ../lib/libcrl-loader.a
PowerlineTSP: ../lib/libcrl-tsplib.a
PowerlineTSP: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
PowerlineTSP: /usr/lib/x86_64-linux-gnu/libboost_program_options.so
PowerlineTSP: /usr/lib/x86_64-linux-gnu/libboost_thread.so
PowerlineTSP: /usr/lib/x86_64-linux-gnu/libboost_system.so
PowerlineTSP: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
PowerlineTSP: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
PowerlineTSP: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
PowerlineTSP: /usr/lib/x86_64-linux-gnu/libcairo.so
PowerlineTSP: /usr/lib/x86_64-linux-gnu/libSM.so
PowerlineTSP: /usr/lib/x86_64-linux-gnu/libICE.so
PowerlineTSP: /usr/lib/x86_64-linux-gnu/libX11.so
PowerlineTSP: /usr/lib/x86_64-linux-gnu/libXext.so
PowerlineTSP: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
PowerlineTSP: CMakeFiles/PowerlineTSP.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mrs/CLionProjects/PowerlineTSPmake/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable PowerlineTSP"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PowerlineTSP.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PowerlineTSP.dir/build: PowerlineTSP

.PHONY : CMakeFiles/PowerlineTSP.dir/build

CMakeFiles/PowerlineTSP.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PowerlineTSP.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PowerlineTSP.dir/clean

CMakeFiles/PowerlineTSP.dir/depend:
	cd /home/mrs/CLionProjects/PowerlineTSPmake/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mrs/CLionProjects/PowerlineTSPmake /home/mrs/CLionProjects/PowerlineTSPmake /home/mrs/CLionProjects/PowerlineTSPmake/cmake-build-debug /home/mrs/CLionProjects/PowerlineTSPmake/cmake-build-debug /home/mrs/CLionProjects/PowerlineTSPmake/cmake-build-debug/CMakeFiles/PowerlineTSP.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PowerlineTSP.dir/depend
