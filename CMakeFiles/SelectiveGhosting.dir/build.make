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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/me/Projects/dlls/selectiveghosting

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/me/Projects/dlls/selectiveghosting

# Include any dependencies generated for this target.
include CMakeFiles/SelectiveGhosting.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SelectiveGhosting.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SelectiveGhosting.dir/flags.make

CMakeFiles/SelectiveGhosting.dir/src/SelectiveGhosting.cpp.obj: CMakeFiles/SelectiveGhosting.dir/flags.make
CMakeFiles/SelectiveGhosting.dir/src/SelectiveGhosting.cpp.obj: src/SelectiveGhosting.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/me/Projects/dlls/selectiveghosting/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SelectiveGhosting.dir/src/SelectiveGhosting.cpp.obj"
	/usr/bin/i686-w64-mingw32-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SelectiveGhosting.dir/src/SelectiveGhosting.cpp.obj -c /home/me/Projects/dlls/selectiveghosting/src/SelectiveGhosting.cpp

CMakeFiles/SelectiveGhosting.dir/src/SelectiveGhosting.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SelectiveGhosting.dir/src/SelectiveGhosting.cpp.i"
	/usr/bin/i686-w64-mingw32-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/me/Projects/dlls/selectiveghosting/src/SelectiveGhosting.cpp > CMakeFiles/SelectiveGhosting.dir/src/SelectiveGhosting.cpp.i

CMakeFiles/SelectiveGhosting.dir/src/SelectiveGhosting.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SelectiveGhosting.dir/src/SelectiveGhosting.cpp.s"
	/usr/bin/i686-w64-mingw32-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/me/Projects/dlls/selectiveghosting/src/SelectiveGhosting.cpp -o CMakeFiles/SelectiveGhosting.dir/src/SelectiveGhosting.cpp.s

CMakeFiles/SelectiveGhosting.dir/src/RedoBlHooks.cpp.obj: CMakeFiles/SelectiveGhosting.dir/flags.make
CMakeFiles/SelectiveGhosting.dir/src/RedoBlHooks.cpp.obj: src/RedoBlHooks.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/me/Projects/dlls/selectiveghosting/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SelectiveGhosting.dir/src/RedoBlHooks.cpp.obj"
	/usr/bin/i686-w64-mingw32-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SelectiveGhosting.dir/src/RedoBlHooks.cpp.obj -c /home/me/Projects/dlls/selectiveghosting/src/RedoBlHooks.cpp

CMakeFiles/SelectiveGhosting.dir/src/RedoBlHooks.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SelectiveGhosting.dir/src/RedoBlHooks.cpp.i"
	/usr/bin/i686-w64-mingw32-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/me/Projects/dlls/selectiveghosting/src/RedoBlHooks.cpp > CMakeFiles/SelectiveGhosting.dir/src/RedoBlHooks.cpp.i

CMakeFiles/SelectiveGhosting.dir/src/RedoBlHooks.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SelectiveGhosting.dir/src/RedoBlHooks.cpp.s"
	/usr/bin/i686-w64-mingw32-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/me/Projects/dlls/selectiveghosting/src/RedoBlHooks.cpp -o CMakeFiles/SelectiveGhosting.dir/src/RedoBlHooks.cpp.s

# Object files for target SelectiveGhosting
SelectiveGhosting_OBJECTS = \
"CMakeFiles/SelectiveGhosting.dir/src/SelectiveGhosting.cpp.obj" \
"CMakeFiles/SelectiveGhosting.dir/src/RedoBlHooks.cpp.obj"

# External object files for target SelectiveGhosting
SelectiveGhosting_EXTERNAL_OBJECTS =

SelectiveGhosting.dll: CMakeFiles/SelectiveGhosting.dir/src/SelectiveGhosting.cpp.obj
SelectiveGhosting.dll: CMakeFiles/SelectiveGhosting.dir/src/RedoBlHooks.cpp.obj
SelectiveGhosting.dll: CMakeFiles/SelectiveGhosting.dir/build.make
SelectiveGhosting.dll: CMakeFiles/SelectiveGhosting.dir/linklibs.rsp
SelectiveGhosting.dll: CMakeFiles/SelectiveGhosting.dir/objects1.rsp
SelectiveGhosting.dll: CMakeFiles/SelectiveGhosting.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/me/Projects/dlls/selectiveghosting/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX shared library SelectiveGhosting.dll"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SelectiveGhosting.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SelectiveGhosting.dir/build: SelectiveGhosting.dll

.PHONY : CMakeFiles/SelectiveGhosting.dir/build

CMakeFiles/SelectiveGhosting.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SelectiveGhosting.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SelectiveGhosting.dir/clean

CMakeFiles/SelectiveGhosting.dir/depend:
	cd /home/me/Projects/dlls/selectiveghosting && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/me/Projects/dlls/selectiveghosting /home/me/Projects/dlls/selectiveghosting /home/me/Projects/dlls/selectiveghosting /home/me/Projects/dlls/selectiveghosting /home/me/Projects/dlls/selectiveghosting/CMakeFiles/SelectiveGhosting.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SelectiveGhosting.dir/depend

