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
CMAKE_COMMAND = "/Users/user/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/202.7660.37/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/user/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/202.7660.37/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/user/Desktop/Informatiks/learn_C

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/user/Desktop/Informatiks/learn_C/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/learn_C.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/learn_C.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/learn_C.dir/flags.make

CMakeFiles/learn_C.dir/day02/ex03/ft_isnegative.c.o: CMakeFiles/learn_C.dir/flags.make
CMakeFiles/learn_C.dir/day02/ex03/ft_isnegative.c.o: ../day02/ex03/ft_isnegative.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/user/Desktop/Informatiks/learn_C/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/learn_C.dir/day02/ex03/ft_isnegative.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/learn_C.dir/day02/ex03/ft_isnegative.c.o   -c /Users/user/Desktop/Informatiks/learn_C/day02/ex03/ft_isnegative.c

CMakeFiles/learn_C.dir/day02/ex03/ft_isnegative.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/learn_C.dir/day02/ex03/ft_isnegative.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/user/Desktop/Informatiks/learn_C/day02/ex03/ft_isnegative.c > CMakeFiles/learn_C.dir/day02/ex03/ft_isnegative.c.i

CMakeFiles/learn_C.dir/day02/ex03/ft_isnegative.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/learn_C.dir/day02/ex03/ft_isnegative.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/user/Desktop/Informatiks/learn_C/day02/ex03/ft_isnegative.c -o CMakeFiles/learn_C.dir/day02/ex03/ft_isnegative.c.s

CMakeFiles/learn_C.dir/Codewars/dice_throw.c.o: CMakeFiles/learn_C.dir/flags.make
CMakeFiles/learn_C.dir/Codewars/dice_throw.c.o: ../Codewars/dice_throw.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/user/Desktop/Informatiks/learn_C/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/learn_C.dir/Codewars/dice_throw.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/learn_C.dir/Codewars/dice_throw.c.o   -c /Users/user/Desktop/Informatiks/learn_C/Codewars/dice_throw.c

CMakeFiles/learn_C.dir/Codewars/dice_throw.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/learn_C.dir/Codewars/dice_throw.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/user/Desktop/Informatiks/learn_C/Codewars/dice_throw.c > CMakeFiles/learn_C.dir/Codewars/dice_throw.c.i

CMakeFiles/learn_C.dir/Codewars/dice_throw.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/learn_C.dir/Codewars/dice_throw.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/user/Desktop/Informatiks/learn_C/Codewars/dice_throw.c -o CMakeFiles/learn_C.dir/Codewars/dice_throw.c.s

# Object files for target learn_C
learn_C_OBJECTS = \
"CMakeFiles/learn_C.dir/day02/ex03/ft_isnegative.c.o" \
"CMakeFiles/learn_C.dir/Codewars/dice_throw.c.o"

# External object files for target learn_C
learn_C_EXTERNAL_OBJECTS =

learn_C: CMakeFiles/learn_C.dir/day02/ex03/ft_isnegative.c.o
learn_C: CMakeFiles/learn_C.dir/Codewars/dice_throw.c.o
learn_C: CMakeFiles/learn_C.dir/build.make
learn_C: CMakeFiles/learn_C.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/user/Desktop/Informatiks/learn_C/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable learn_C"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/learn_C.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/learn_C.dir/build: learn_C

.PHONY : CMakeFiles/learn_C.dir/build

CMakeFiles/learn_C.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/learn_C.dir/cmake_clean.cmake
.PHONY : CMakeFiles/learn_C.dir/clean

CMakeFiles/learn_C.dir/depend:
	cd /Users/user/Desktop/Informatiks/learn_C/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/user/Desktop/Informatiks/learn_C /Users/user/Desktop/Informatiks/learn_C /Users/user/Desktop/Informatiks/learn_C/cmake-build-debug /Users/user/Desktop/Informatiks/learn_C/cmake-build-debug /Users/user/Desktop/Informatiks/learn_C/cmake-build-debug/CMakeFiles/learn_C.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/learn_C.dir/depend

