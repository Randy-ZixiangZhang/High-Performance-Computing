# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/randy-zixiang/Documents/Documents - Randy-ZixiangZhang’s MacBook Pro/HPC/Project1_FInal/some_library"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/randy-zixiang/Documents/Documents - Randy-ZixiangZhang’s MacBook Pro/HPC/Project1_FInal/some_library/build"

# Include any dependencies generated for this target.
include CMakeFiles/demo.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/demo.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/demo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/demo.dir/flags.make

CMakeFiles/demo.dir/demo_lib.cpp.o: CMakeFiles/demo.dir/flags.make
CMakeFiles/demo.dir/demo_lib.cpp.o: ../demo_lib.cpp
CMakeFiles/demo.dir/demo_lib.cpp.o: CMakeFiles/demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/randy-zixiang/Documents/Documents - Randy-ZixiangZhang’s MacBook Pro/HPC/Project1_FInal/some_library/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/demo.dir/demo_lib.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/demo.dir/demo_lib.cpp.o -MF CMakeFiles/demo.dir/demo_lib.cpp.o.d -o CMakeFiles/demo.dir/demo_lib.cpp.o -c "/Users/randy-zixiang/Documents/Documents - Randy-ZixiangZhang’s MacBook Pro/HPC/Project1_FInal/some_library/demo_lib.cpp"

CMakeFiles/demo.dir/demo_lib.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/demo_lib.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/randy-zixiang/Documents/Documents - Randy-ZixiangZhang’s MacBook Pro/HPC/Project1_FInal/some_library/demo_lib.cpp" > CMakeFiles/demo.dir/demo_lib.cpp.i

CMakeFiles/demo.dir/demo_lib.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/demo_lib.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/randy-zixiang/Documents/Documents - Randy-ZixiangZhang’s MacBook Pro/HPC/Project1_FInal/some_library/demo_lib.cpp" -o CMakeFiles/demo.dir/demo_lib.cpp.s

# Object files for target demo
demo_OBJECTS = \
"CMakeFiles/demo.dir/demo_lib.cpp.o"

# External object files for target demo
demo_EXTERNAL_OBJECTS =

libdemo.dylib: CMakeFiles/demo.dir/demo_lib.cpp.o
libdemo.dylib: CMakeFiles/demo.dir/build.make
libdemo.dylib: CMakeFiles/demo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/randy-zixiang/Documents/Documents - Randy-ZixiangZhang’s MacBook Pro/HPC/Project1_FInal/some_library/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libdemo.dylib"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/demo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/demo.dir/build: libdemo.dylib
.PHONY : CMakeFiles/demo.dir/build

CMakeFiles/demo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/demo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/demo.dir/clean

CMakeFiles/demo.dir/depend:
	cd "/Users/randy-zixiang/Documents/Documents - Randy-ZixiangZhang’s MacBook Pro/HPC/Project1_FInal/some_library/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/randy-zixiang/Documents/Documents - Randy-ZixiangZhang’s MacBook Pro/HPC/Project1_FInal/some_library" "/Users/randy-zixiang/Documents/Documents - Randy-ZixiangZhang’s MacBook Pro/HPC/Project1_FInal/some_library" "/Users/randy-zixiang/Documents/Documents - Randy-ZixiangZhang’s MacBook Pro/HPC/Project1_FInal/some_library/build" "/Users/randy-zixiang/Documents/Documents - Randy-ZixiangZhang’s MacBook Pro/HPC/Project1_FInal/some_library/build" "/Users/randy-zixiang/Documents/Documents - Randy-ZixiangZhang’s MacBook Pro/HPC/Project1_FInal/some_library/build/CMakeFiles/demo.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/demo.dir/depend
