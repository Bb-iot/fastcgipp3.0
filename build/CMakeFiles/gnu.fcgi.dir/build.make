# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/cmake-3.21.1/bin/cmake

# The command to remove a file.
RM = /opt/cmake-3.21.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/liubb/workspaces/1_Libsrc_code/fastcgipp-3.0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/liubb/workspaces/1_Libsrc_code/fastcgipp-3.0/build

# Include any dependencies generated for this target.
include CMakeFiles/gnu.fcgi.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/gnu.fcgi.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/gnu.fcgi.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gnu.fcgi.dir/flags.make

CMakeFiles/gnu.fcgi.dir/examples/gnu.cpp.o: CMakeFiles/gnu.fcgi.dir/flags.make
CMakeFiles/gnu.fcgi.dir/examples/gnu.cpp.o: ../examples/gnu.cpp
CMakeFiles/gnu.fcgi.dir/examples/gnu.cpp.o: CMakeFiles/gnu.fcgi.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liubb/workspaces/1_Libsrc_code/fastcgipp-3.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/gnu.fcgi.dir/examples/gnu.cpp.o"
	/opt/rv1126_sdk/host/bin/arm-linux-gnueabihf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gnu.fcgi.dir/examples/gnu.cpp.o -MF CMakeFiles/gnu.fcgi.dir/examples/gnu.cpp.o.d -o CMakeFiles/gnu.fcgi.dir/examples/gnu.cpp.o -c /home/liubb/workspaces/1_Libsrc_code/fastcgipp-3.0/examples/gnu.cpp

CMakeFiles/gnu.fcgi.dir/examples/gnu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gnu.fcgi.dir/examples/gnu.cpp.i"
	/opt/rv1126_sdk/host/bin/arm-linux-gnueabihf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liubb/workspaces/1_Libsrc_code/fastcgipp-3.0/examples/gnu.cpp > CMakeFiles/gnu.fcgi.dir/examples/gnu.cpp.i

CMakeFiles/gnu.fcgi.dir/examples/gnu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gnu.fcgi.dir/examples/gnu.cpp.s"
	/opt/rv1126_sdk/host/bin/arm-linux-gnueabihf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liubb/workspaces/1_Libsrc_code/fastcgipp-3.0/examples/gnu.cpp -o CMakeFiles/gnu.fcgi.dir/examples/gnu.cpp.s

# Object files for target gnu.fcgi
gnu_fcgi_OBJECTS = \
"CMakeFiles/gnu.fcgi.dir/examples/gnu.cpp.o"

# External object files for target gnu.fcgi
gnu_fcgi_EXTERNAL_OBJECTS =

gnu.fcgi: CMakeFiles/gnu.fcgi.dir/examples/gnu.cpp.o
gnu.fcgi: CMakeFiles/gnu.fcgi.dir/build.make
gnu.fcgi: libfastcgipp.so.3.0
gnu.fcgi: CMakeFiles/gnu.fcgi.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/liubb/workspaces/1_Libsrc_code/fastcgipp-3.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable gnu.fcgi"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gnu.fcgi.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gnu.fcgi.dir/build: gnu.fcgi
.PHONY : CMakeFiles/gnu.fcgi.dir/build

CMakeFiles/gnu.fcgi.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gnu.fcgi.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gnu.fcgi.dir/clean

CMakeFiles/gnu.fcgi.dir/depend:
	cd /home/liubb/workspaces/1_Libsrc_code/fastcgipp-3.0/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/liubb/workspaces/1_Libsrc_code/fastcgipp-3.0 /home/liubb/workspaces/1_Libsrc_code/fastcgipp-3.0 /home/liubb/workspaces/1_Libsrc_code/fastcgipp-3.0/build /home/liubb/workspaces/1_Libsrc_code/fastcgipp-3.0/build /home/liubb/workspaces/1_Libsrc_code/fastcgipp-3.0/build/CMakeFiles/gnu.fcgi.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gnu.fcgi.dir/depend

