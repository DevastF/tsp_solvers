# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/fnekovar/git/gsoa

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fnekovar/git/gsoa/build

# Include any dependencies generated for this target.
include crl/crl.loader/CMakeFiles/crl-loader.dir/depend.make

# Include the progress variables for this target.
include crl/crl.loader/CMakeFiles/crl-loader.dir/progress.make

# Include the compile flags for this target's objects.
include crl/crl.loader/CMakeFiles/crl-loader.dir/flags.make

crl/crl.loader/CMakeFiles/crl-loader.dir/src/distances_module.cc.o: crl/crl.loader/CMakeFiles/crl-loader.dir/flags.make
crl/crl.loader/CMakeFiles/crl-loader.dir/src/distances_module.cc.o: ../crl/crl.loader/src/distances_module.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fnekovar/git/gsoa/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object crl/crl.loader/CMakeFiles/crl-loader.dir/src/distances_module.cc.o"
	cd /home/fnekovar/git/gsoa/build/crl/crl.loader && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/crl-loader.dir/src/distances_module.cc.o -c /home/fnekovar/git/gsoa/crl/crl.loader/src/distances_module.cc

crl/crl.loader/CMakeFiles/crl-loader.dir/src/distances_module.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/crl-loader.dir/src/distances_module.cc.i"
	cd /home/fnekovar/git/gsoa/build/crl/crl.loader && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fnekovar/git/gsoa/crl/crl.loader/src/distances_module.cc > CMakeFiles/crl-loader.dir/src/distances_module.cc.i

crl/crl.loader/CMakeFiles/crl-loader.dir/src/distances_module.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/crl-loader.dir/src/distances_module.cc.s"
	cd /home/fnekovar/git/gsoa/build/crl/crl.loader && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fnekovar/git/gsoa/crl/crl.loader/src/distances_module.cc -o CMakeFiles/crl-loader.dir/src/distances_module.cc.s

crl/crl.loader/CMakeFiles/crl-loader.dir/src/distances_module.cc.o.requires:

.PHONY : crl/crl.loader/CMakeFiles/crl-loader.dir/src/distances_module.cc.o.requires

crl/crl.loader/CMakeFiles/crl-loader.dir/src/distances_module.cc.o.provides: crl/crl.loader/CMakeFiles/crl-loader.dir/src/distances_module.cc.o.requires
	$(MAKE) -f crl/crl.loader/CMakeFiles/crl-loader.dir/build.make crl/crl.loader/CMakeFiles/crl-loader.dir/src/distances_module.cc.o.provides.build
.PHONY : crl/crl.loader/CMakeFiles/crl-loader.dir/src/distances_module.cc.o.provides

crl/crl.loader/CMakeFiles/crl-loader.dir/src/distances_module.cc.o.provides.build: crl/crl.loader/CMakeFiles/crl-loader.dir/src/distances_module.cc.o


crl/crl.loader/CMakeFiles/crl-loader.dir/src/graph_module.cc.o: crl/crl.loader/CMakeFiles/crl-loader.dir/flags.make
crl/crl.loader/CMakeFiles/crl-loader.dir/src/graph_module.cc.o: ../crl/crl.loader/src/graph_module.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fnekovar/git/gsoa/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object crl/crl.loader/CMakeFiles/crl-loader.dir/src/graph_module.cc.o"
	cd /home/fnekovar/git/gsoa/build/crl/crl.loader && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/crl-loader.dir/src/graph_module.cc.o -c /home/fnekovar/git/gsoa/crl/crl.loader/src/graph_module.cc

crl/crl.loader/CMakeFiles/crl-loader.dir/src/graph_module.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/crl-loader.dir/src/graph_module.cc.i"
	cd /home/fnekovar/git/gsoa/build/crl/crl.loader && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fnekovar/git/gsoa/crl/crl.loader/src/graph_module.cc > CMakeFiles/crl-loader.dir/src/graph_module.cc.i

crl/crl.loader/CMakeFiles/crl-loader.dir/src/graph_module.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/crl-loader.dir/src/graph_module.cc.s"
	cd /home/fnekovar/git/gsoa/build/crl/crl.loader && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fnekovar/git/gsoa/crl/crl.loader/src/graph_module.cc -o CMakeFiles/crl-loader.dir/src/graph_module.cc.s

crl/crl.loader/CMakeFiles/crl-loader.dir/src/graph_module.cc.o.requires:

.PHONY : crl/crl.loader/CMakeFiles/crl-loader.dir/src/graph_module.cc.o.requires

crl/crl.loader/CMakeFiles/crl-loader.dir/src/graph_module.cc.o.provides: crl/crl.loader/CMakeFiles/crl-loader.dir/src/graph_module.cc.o.requires
	$(MAKE) -f crl/crl.loader/CMakeFiles/crl-loader.dir/build.make crl/crl.loader/CMakeFiles/crl-loader.dir/src/graph_module.cc.o.provides.build
.PHONY : crl/crl.loader/CMakeFiles/crl-loader.dir/src/graph_module.cc.o.provides

crl/crl.loader/CMakeFiles/crl-loader.dir/src/graph_module.cc.o.provides.build: crl/crl.loader/CMakeFiles/crl-loader.dir/src/graph_module.cc.o


crl/crl.loader/CMakeFiles/crl-loader.dir/src/loader_types.cc.o: crl/crl.loader/CMakeFiles/crl-loader.dir/flags.make
crl/crl.loader/CMakeFiles/crl-loader.dir/src/loader_types.cc.o: ../crl/crl.loader/src/loader_types.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fnekovar/git/gsoa/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object crl/crl.loader/CMakeFiles/crl-loader.dir/src/loader_types.cc.o"
	cd /home/fnekovar/git/gsoa/build/crl/crl.loader && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/crl-loader.dir/src/loader_types.cc.o -c /home/fnekovar/git/gsoa/crl/crl.loader/src/loader_types.cc

crl/crl.loader/CMakeFiles/crl-loader.dir/src/loader_types.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/crl-loader.dir/src/loader_types.cc.i"
	cd /home/fnekovar/git/gsoa/build/crl/crl.loader && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fnekovar/git/gsoa/crl/crl.loader/src/loader_types.cc > CMakeFiles/crl-loader.dir/src/loader_types.cc.i

crl/crl.loader/CMakeFiles/crl-loader.dir/src/loader_types.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/crl-loader.dir/src/loader_types.cc.s"
	cd /home/fnekovar/git/gsoa/build/crl/crl.loader && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fnekovar/git/gsoa/crl/crl.loader/src/loader_types.cc -o CMakeFiles/crl-loader.dir/src/loader_types.cc.s

crl/crl.loader/CMakeFiles/crl-loader.dir/src/loader_types.cc.o.requires:

.PHONY : crl/crl.loader/CMakeFiles/crl-loader.dir/src/loader_types.cc.o.requires

crl/crl.loader/CMakeFiles/crl-loader.dir/src/loader_types.cc.o.provides: crl/crl.loader/CMakeFiles/crl-loader.dir/src/loader_types.cc.o.requires
	$(MAKE) -f crl/crl.loader/CMakeFiles/crl-loader.dir/build.make crl/crl.loader/CMakeFiles/crl-loader.dir/src/loader_types.cc.o.provides.build
.PHONY : crl/crl.loader/CMakeFiles/crl-loader.dir/src/loader_types.cc.o.provides

crl/crl.loader/CMakeFiles/crl-loader.dir/src/loader_types.cc.o.provides.build: crl/crl.loader/CMakeFiles/crl-loader.dir/src/loader_types.cc.o


crl/crl.loader/CMakeFiles/crl-loader.dir/src/map_partition_module.cc.o: crl/crl.loader/CMakeFiles/crl-loader.dir/flags.make
crl/crl.loader/CMakeFiles/crl-loader.dir/src/map_partition_module.cc.o: ../crl/crl.loader/src/map_partition_module.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fnekovar/git/gsoa/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object crl/crl.loader/CMakeFiles/crl-loader.dir/src/map_partition_module.cc.o"
	cd /home/fnekovar/git/gsoa/build/crl/crl.loader && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/crl-loader.dir/src/map_partition_module.cc.o -c /home/fnekovar/git/gsoa/crl/crl.loader/src/map_partition_module.cc

crl/crl.loader/CMakeFiles/crl-loader.dir/src/map_partition_module.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/crl-loader.dir/src/map_partition_module.cc.i"
	cd /home/fnekovar/git/gsoa/build/crl/crl.loader && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fnekovar/git/gsoa/crl/crl.loader/src/map_partition_module.cc > CMakeFiles/crl-loader.dir/src/map_partition_module.cc.i

crl/crl.loader/CMakeFiles/crl-loader.dir/src/map_partition_module.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/crl-loader.dir/src/map_partition_module.cc.s"
	cd /home/fnekovar/git/gsoa/build/crl/crl.loader && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fnekovar/git/gsoa/crl/crl.loader/src/map_partition_module.cc -o CMakeFiles/crl-loader.dir/src/map_partition_module.cc.s

crl/crl.loader/CMakeFiles/crl-loader.dir/src/map_partition_module.cc.o.requires:

.PHONY : crl/crl.loader/CMakeFiles/crl-loader.dir/src/map_partition_module.cc.o.requires

crl/crl.loader/CMakeFiles/crl-loader.dir/src/map_partition_module.cc.o.provides: crl/crl.loader/CMakeFiles/crl-loader.dir/src/map_partition_module.cc.o.requires
	$(MAKE) -f crl/crl.loader/CMakeFiles/crl-loader.dir/build.make crl/crl.loader/CMakeFiles/crl-loader.dir/src/map_partition_module.cc.o.provides.build
.PHONY : crl/crl.loader/CMakeFiles/crl-loader.dir/src/map_partition_module.cc.o.provides

crl/crl.loader/CMakeFiles/crl-loader.dir/src/map_partition_module.cc.o.provides.build: crl/crl.loader/CMakeFiles/crl-loader.dir/src/map_partition_module.cc.o


crl/crl.loader/CMakeFiles/crl-loader.dir/src/route_module.cc.o: crl/crl.loader/CMakeFiles/crl-loader.dir/flags.make
crl/crl.loader/CMakeFiles/crl-loader.dir/src/route_module.cc.o: ../crl/crl.loader/src/route_module.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fnekovar/git/gsoa/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object crl/crl.loader/CMakeFiles/crl-loader.dir/src/route_module.cc.o"
	cd /home/fnekovar/git/gsoa/build/crl/crl.loader && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/crl-loader.dir/src/route_module.cc.o -c /home/fnekovar/git/gsoa/crl/crl.loader/src/route_module.cc

crl/crl.loader/CMakeFiles/crl-loader.dir/src/route_module.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/crl-loader.dir/src/route_module.cc.i"
	cd /home/fnekovar/git/gsoa/build/crl/crl.loader && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fnekovar/git/gsoa/crl/crl.loader/src/route_module.cc > CMakeFiles/crl-loader.dir/src/route_module.cc.i

crl/crl.loader/CMakeFiles/crl-loader.dir/src/route_module.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/crl-loader.dir/src/route_module.cc.s"
	cd /home/fnekovar/git/gsoa/build/crl/crl.loader && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fnekovar/git/gsoa/crl/crl.loader/src/route_module.cc -o CMakeFiles/crl-loader.dir/src/route_module.cc.s

crl/crl.loader/CMakeFiles/crl-loader.dir/src/route_module.cc.o.requires:

.PHONY : crl/crl.loader/CMakeFiles/crl-loader.dir/src/route_module.cc.o.requires

crl/crl.loader/CMakeFiles/crl-loader.dir/src/route_module.cc.o.provides: crl/crl.loader/CMakeFiles/crl-loader.dir/src/route_module.cc.o.requires
	$(MAKE) -f crl/crl.loader/CMakeFiles/crl-loader.dir/build.make crl/crl.loader/CMakeFiles/crl-loader.dir/src/route_module.cc.o.provides.build
.PHONY : crl/crl.loader/CMakeFiles/crl-loader.dir/src/route_module.cc.o.provides

crl/crl.loader/CMakeFiles/crl-loader.dir/src/route_module.cc.o.provides.build: crl/crl.loader/CMakeFiles/crl-loader.dir/src/route_module.cc.o


crl/crl.loader/CMakeFiles/crl-loader.dir/src/text_format_loader.cc.o: crl/crl.loader/CMakeFiles/crl-loader.dir/flags.make
crl/crl.loader/CMakeFiles/crl-loader.dir/src/text_format_loader.cc.o: ../crl/crl.loader/src/text_format_loader.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fnekovar/git/gsoa/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object crl/crl.loader/CMakeFiles/crl-loader.dir/src/text_format_loader.cc.o"
	cd /home/fnekovar/git/gsoa/build/crl/crl.loader && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/crl-loader.dir/src/text_format_loader.cc.o -c /home/fnekovar/git/gsoa/crl/crl.loader/src/text_format_loader.cc

crl/crl.loader/CMakeFiles/crl-loader.dir/src/text_format_loader.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/crl-loader.dir/src/text_format_loader.cc.i"
	cd /home/fnekovar/git/gsoa/build/crl/crl.loader && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fnekovar/git/gsoa/crl/crl.loader/src/text_format_loader.cc > CMakeFiles/crl-loader.dir/src/text_format_loader.cc.i

crl/crl.loader/CMakeFiles/crl-loader.dir/src/text_format_loader.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/crl-loader.dir/src/text_format_loader.cc.s"
	cd /home/fnekovar/git/gsoa/build/crl/crl.loader && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fnekovar/git/gsoa/crl/crl.loader/src/text_format_loader.cc -o CMakeFiles/crl-loader.dir/src/text_format_loader.cc.s

crl/crl.loader/CMakeFiles/crl-loader.dir/src/text_format_loader.cc.o.requires:

.PHONY : crl/crl.loader/CMakeFiles/crl-loader.dir/src/text_format_loader.cc.o.requires

crl/crl.loader/CMakeFiles/crl-loader.dir/src/text_format_loader.cc.o.provides: crl/crl.loader/CMakeFiles/crl-loader.dir/src/text_format_loader.cc.o.requires
	$(MAKE) -f crl/crl.loader/CMakeFiles/crl-loader.dir/build.make crl/crl.loader/CMakeFiles/crl-loader.dir/src/text_format_loader.cc.o.provides.build
.PHONY : crl/crl.loader/CMakeFiles/crl-loader.dir/src/text_format_loader.cc.o.provides

crl/crl.loader/CMakeFiles/crl-loader.dir/src/text_format_loader.cc.o.provides.build: crl/crl.loader/CMakeFiles/crl-loader.dir/src/text_format_loader.cc.o


crl/crl.loader/CMakeFiles/crl-loader.dir/src/text_stream.cc.o: crl/crl.loader/CMakeFiles/crl-loader.dir/flags.make
crl/crl.loader/CMakeFiles/crl-loader.dir/src/text_stream.cc.o: ../crl/crl.loader/src/text_stream.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fnekovar/git/gsoa/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object crl/crl.loader/CMakeFiles/crl-loader.dir/src/text_stream.cc.o"
	cd /home/fnekovar/git/gsoa/build/crl/crl.loader && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/crl-loader.dir/src/text_stream.cc.o -c /home/fnekovar/git/gsoa/crl/crl.loader/src/text_stream.cc

crl/crl.loader/CMakeFiles/crl-loader.dir/src/text_stream.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/crl-loader.dir/src/text_stream.cc.i"
	cd /home/fnekovar/git/gsoa/build/crl/crl.loader && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fnekovar/git/gsoa/crl/crl.loader/src/text_stream.cc > CMakeFiles/crl-loader.dir/src/text_stream.cc.i

crl/crl.loader/CMakeFiles/crl-loader.dir/src/text_stream.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/crl-loader.dir/src/text_stream.cc.s"
	cd /home/fnekovar/git/gsoa/build/crl/crl.loader && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fnekovar/git/gsoa/crl/crl.loader/src/text_stream.cc -o CMakeFiles/crl-loader.dir/src/text_stream.cc.s

crl/crl.loader/CMakeFiles/crl-loader.dir/src/text_stream.cc.o.requires:

.PHONY : crl/crl.loader/CMakeFiles/crl-loader.dir/src/text_stream.cc.o.requires

crl/crl.loader/CMakeFiles/crl-loader.dir/src/text_stream.cc.o.provides: crl/crl.loader/CMakeFiles/crl-loader.dir/src/text_stream.cc.o.requires
	$(MAKE) -f crl/crl.loader/CMakeFiles/crl-loader.dir/build.make crl/crl.loader/CMakeFiles/crl-loader.dir/src/text_stream.cc.o.provides.build
.PHONY : crl/crl.loader/CMakeFiles/crl-loader.dir/src/text_stream.cc.o.provides

crl/crl.loader/CMakeFiles/crl-loader.dir/src/text_stream.cc.o.provides.build: crl/crl.loader/CMakeFiles/crl-loader.dir/src/text_stream.cc.o


# Object files for target crl-loader
crl__loader_OBJECTS = \
"CMakeFiles/crl-loader.dir/src/distances_module.cc.o" \
"CMakeFiles/crl-loader.dir/src/graph_module.cc.o" \
"CMakeFiles/crl-loader.dir/src/loader_types.cc.o" \
"CMakeFiles/crl-loader.dir/src/map_partition_module.cc.o" \
"CMakeFiles/crl-loader.dir/src/route_module.cc.o" \
"CMakeFiles/crl-loader.dir/src/text_format_loader.cc.o" \
"CMakeFiles/crl-loader.dir/src/text_stream.cc.o"

# External object files for target crl-loader
crl__loader_EXTERNAL_OBJECTS =

crl/crl.loader/libcrl-loader.a: crl/crl.loader/CMakeFiles/crl-loader.dir/src/distances_module.cc.o
crl/crl.loader/libcrl-loader.a: crl/crl.loader/CMakeFiles/crl-loader.dir/src/graph_module.cc.o
crl/crl.loader/libcrl-loader.a: crl/crl.loader/CMakeFiles/crl-loader.dir/src/loader_types.cc.o
crl/crl.loader/libcrl-loader.a: crl/crl.loader/CMakeFiles/crl-loader.dir/src/map_partition_module.cc.o
crl/crl.loader/libcrl-loader.a: crl/crl.loader/CMakeFiles/crl-loader.dir/src/route_module.cc.o
crl/crl.loader/libcrl-loader.a: crl/crl.loader/CMakeFiles/crl-loader.dir/src/text_format_loader.cc.o
crl/crl.loader/libcrl-loader.a: crl/crl.loader/CMakeFiles/crl-loader.dir/src/text_stream.cc.o
crl/crl.loader/libcrl-loader.a: crl/crl.loader/CMakeFiles/crl-loader.dir/build.make
crl/crl.loader/libcrl-loader.a: crl/crl.loader/CMakeFiles/crl-loader.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fnekovar/git/gsoa/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX static library libcrl-loader.a"
	cd /home/fnekovar/git/gsoa/build/crl/crl.loader && $(CMAKE_COMMAND) -P CMakeFiles/crl-loader.dir/cmake_clean_target.cmake
	cd /home/fnekovar/git/gsoa/build/crl/crl.loader && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/crl-loader.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
crl/crl.loader/CMakeFiles/crl-loader.dir/build: crl/crl.loader/libcrl-loader.a

.PHONY : crl/crl.loader/CMakeFiles/crl-loader.dir/build

crl/crl.loader/CMakeFiles/crl-loader.dir/requires: crl/crl.loader/CMakeFiles/crl-loader.dir/src/distances_module.cc.o.requires
crl/crl.loader/CMakeFiles/crl-loader.dir/requires: crl/crl.loader/CMakeFiles/crl-loader.dir/src/graph_module.cc.o.requires
crl/crl.loader/CMakeFiles/crl-loader.dir/requires: crl/crl.loader/CMakeFiles/crl-loader.dir/src/loader_types.cc.o.requires
crl/crl.loader/CMakeFiles/crl-loader.dir/requires: crl/crl.loader/CMakeFiles/crl-loader.dir/src/map_partition_module.cc.o.requires
crl/crl.loader/CMakeFiles/crl-loader.dir/requires: crl/crl.loader/CMakeFiles/crl-loader.dir/src/route_module.cc.o.requires
crl/crl.loader/CMakeFiles/crl-loader.dir/requires: crl/crl.loader/CMakeFiles/crl-loader.dir/src/text_format_loader.cc.o.requires
crl/crl.loader/CMakeFiles/crl-loader.dir/requires: crl/crl.loader/CMakeFiles/crl-loader.dir/src/text_stream.cc.o.requires

.PHONY : crl/crl.loader/CMakeFiles/crl-loader.dir/requires

crl/crl.loader/CMakeFiles/crl-loader.dir/clean:
	cd /home/fnekovar/git/gsoa/build/crl/crl.loader && $(CMAKE_COMMAND) -P CMakeFiles/crl-loader.dir/cmake_clean.cmake
.PHONY : crl/crl.loader/CMakeFiles/crl-loader.dir/clean

crl/crl.loader/CMakeFiles/crl-loader.dir/depend:
	cd /home/fnekovar/git/gsoa/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fnekovar/git/gsoa /home/fnekovar/git/gsoa/crl/crl.loader /home/fnekovar/git/gsoa/build /home/fnekovar/git/gsoa/build/crl/crl.loader /home/fnekovar/git/gsoa/build/crl/crl.loader/CMakeFiles/crl-loader.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : crl/crl.loader/CMakeFiles/crl-loader.dir/depend

