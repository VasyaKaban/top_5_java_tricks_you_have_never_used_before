# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/vasyakaban/items/psp/lab7/lab7

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vasyakaban/items/psp/lab7/build-lab7-Desktop-Debug

# Utility rule file for lab7_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/lab7_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lab7_autogen.dir/progress.make

CMakeFiles/lab7_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/vasyakaban/items/psp/lab7/build-lab7-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target lab7"
	/usr/bin/cmake -E cmake_autogen /home/vasyakaban/items/psp/lab7/build-lab7-Desktop-Debug/CMakeFiles/lab7_autogen.dir/AutogenInfo.json Debug

lab7_autogen: CMakeFiles/lab7_autogen
lab7_autogen: CMakeFiles/lab7_autogen.dir/build.make
.PHONY : lab7_autogen

# Rule to build all files generated by this target.
CMakeFiles/lab7_autogen.dir/build: lab7_autogen
.PHONY : CMakeFiles/lab7_autogen.dir/build

CMakeFiles/lab7_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab7_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab7_autogen.dir/clean

CMakeFiles/lab7_autogen.dir/depend:
	cd /home/vasyakaban/items/psp/lab7/build-lab7-Desktop-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vasyakaban/items/psp/lab7/lab7 /home/vasyakaban/items/psp/lab7/lab7 /home/vasyakaban/items/psp/lab7/build-lab7-Desktop-Debug /home/vasyakaban/items/psp/lab7/build-lab7-Desktop-Debug /home/vasyakaban/items/psp/lab7/build-lab7-Desktop-Debug/CMakeFiles/lab7_autogen.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/lab7_autogen.dir/depend

