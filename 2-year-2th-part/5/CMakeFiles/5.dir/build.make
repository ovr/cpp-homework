# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.2.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.2.1/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ovr/projects/ovr/cpp-homework/2-year-2th-part/5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ovr/projects/ovr/cpp-homework/2-year-2th-part/5

# Include any dependencies generated for this target.
include CMakeFiles/5.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/5.dir/flags.make

CMakeFiles/5.dir/main.cpp.o: CMakeFiles/5.dir/flags.make
CMakeFiles/5.dir/main.cpp.o: main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/ovr/projects/ovr/cpp-homework/2-year-2th-part/5/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/5.dir/main.cpp.o"
	/Volumes/OSXTest/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/5.dir/main.cpp.o -c /Users/ovr/projects/ovr/cpp-homework/2-year-2th-part/5/main.cpp

CMakeFiles/5.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/5.dir/main.cpp.i"
	/Volumes/OSXTest/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/ovr/projects/ovr/cpp-homework/2-year-2th-part/5/main.cpp > CMakeFiles/5.dir/main.cpp.i

CMakeFiles/5.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/5.dir/main.cpp.s"
	/Volumes/OSXTest/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/ovr/projects/ovr/cpp-homework/2-year-2th-part/5/main.cpp -o CMakeFiles/5.dir/main.cpp.s

CMakeFiles/5.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/5.dir/main.cpp.o.requires

CMakeFiles/5.dir/main.cpp.o.provides: CMakeFiles/5.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/5.dir/build.make CMakeFiles/5.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/5.dir/main.cpp.o.provides

CMakeFiles/5.dir/main.cpp.o.provides.build: CMakeFiles/5.dir/main.cpp.o

# Object files for target 5
5_OBJECTS = \
"CMakeFiles/5.dir/main.cpp.o"

# External object files for target 5
5_EXTERNAL_OBJECTS =

5 : CMakeFiles/5.dir/main.cpp.o
5 : CMakeFiles/5.dir/build.make
5 : CMakeFiles/5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable 5"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/5.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/5.dir/build: 5
.PHONY : CMakeFiles/5.dir/build

CMakeFiles/5.dir/requires: CMakeFiles/5.dir/main.cpp.o.requires
.PHONY : CMakeFiles/5.dir/requires

CMakeFiles/5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/5.dir/cmake_clean.cmake
.PHONY : CMakeFiles/5.dir/clean

CMakeFiles/5.dir/depend:
	cd /Users/ovr/projects/ovr/cpp-homework/2-year-2th-part/5 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ovr/projects/ovr/cpp-homework/2-year-2th-part/5 /Users/ovr/projects/ovr/cpp-homework/2-year-2th-part/5 /Users/ovr/projects/ovr/cpp-homework/2-year-2th-part/5 /Users/ovr/projects/ovr/cpp-homework/2-year-2th-part/5 /Users/ovr/projects/ovr/cpp-homework/2-year-2th-part/5/CMakeFiles/5.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/5.dir/depend

