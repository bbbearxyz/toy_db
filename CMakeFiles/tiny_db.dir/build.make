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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mazijie/CLionProjects/tiny_db

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mazijie/CLionProjects/tiny_db

# Include any dependencies generated for this target.
include CMakeFiles/tiny_db.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tiny_db.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tiny_db.dir/flags.make

CMakeFiles/tiny_db.dir/main.cpp.o: CMakeFiles/tiny_db.dir/flags.make
CMakeFiles/tiny_db.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mazijie/CLionProjects/tiny_db/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tiny_db.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tiny_db.dir/main.cpp.o -c /Users/mazijie/CLionProjects/tiny_db/main.cpp

CMakeFiles/tiny_db.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tiny_db.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mazijie/CLionProjects/tiny_db/main.cpp > CMakeFiles/tiny_db.dir/main.cpp.i

CMakeFiles/tiny_db.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tiny_db.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mazijie/CLionProjects/tiny_db/main.cpp -o CMakeFiles/tiny_db.dir/main.cpp.s

CMakeFiles/tiny_db.dir/src/part_input/InputBuffer.cpp.o: CMakeFiles/tiny_db.dir/flags.make
CMakeFiles/tiny_db.dir/src/part_input/InputBuffer.cpp.o: src/part_input/InputBuffer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mazijie/CLionProjects/tiny_db/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/tiny_db.dir/src/part_input/InputBuffer.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tiny_db.dir/src/part_input/InputBuffer.cpp.o -c /Users/mazijie/CLionProjects/tiny_db/src/part_input/InputBuffer.cpp

CMakeFiles/tiny_db.dir/src/part_input/InputBuffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tiny_db.dir/src/part_input/InputBuffer.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mazijie/CLionProjects/tiny_db/src/part_input/InputBuffer.cpp > CMakeFiles/tiny_db.dir/src/part_input/InputBuffer.cpp.i

CMakeFiles/tiny_db.dir/src/part_input/InputBuffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tiny_db.dir/src/part_input/InputBuffer.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mazijie/CLionProjects/tiny_db/src/part_input/InputBuffer.cpp -o CMakeFiles/tiny_db.dir/src/part_input/InputBuffer.cpp.s

CMakeFiles/tiny_db.dir/src/part_process/Process.cpp.o: CMakeFiles/tiny_db.dir/flags.make
CMakeFiles/tiny_db.dir/src/part_process/Process.cpp.o: src/part_process/Process.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mazijie/CLionProjects/tiny_db/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/tiny_db.dir/src/part_process/Process.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tiny_db.dir/src/part_process/Process.cpp.o -c /Users/mazijie/CLionProjects/tiny_db/src/part_process/Process.cpp

CMakeFiles/tiny_db.dir/src/part_process/Process.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tiny_db.dir/src/part_process/Process.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mazijie/CLionProjects/tiny_db/src/part_process/Process.cpp > CMakeFiles/tiny_db.dir/src/part_process/Process.cpp.i

CMakeFiles/tiny_db.dir/src/part_process/Process.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tiny_db.dir/src/part_process/Process.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mazijie/CLionProjects/tiny_db/src/part_process/Process.cpp -o CMakeFiles/tiny_db.dir/src/part_process/Process.cpp.s

CMakeFiles/tiny_db.dir/src/part_command/Command.cpp.o: CMakeFiles/tiny_db.dir/flags.make
CMakeFiles/tiny_db.dir/src/part_command/Command.cpp.o: src/part_command/Command.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mazijie/CLionProjects/tiny_db/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/tiny_db.dir/src/part_command/Command.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tiny_db.dir/src/part_command/Command.cpp.o -c /Users/mazijie/CLionProjects/tiny_db/src/part_command/Command.cpp

CMakeFiles/tiny_db.dir/src/part_command/Command.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tiny_db.dir/src/part_command/Command.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mazijie/CLionProjects/tiny_db/src/part_command/Command.cpp > CMakeFiles/tiny_db.dir/src/part_command/Command.cpp.i

CMakeFiles/tiny_db.dir/src/part_command/Command.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tiny_db.dir/src/part_command/Command.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mazijie/CLionProjects/tiny_db/src/part_command/Command.cpp -o CMakeFiles/tiny_db.dir/src/part_command/Command.cpp.s

CMakeFiles/tiny_db.dir/src/part_table/Table.cpp.o: CMakeFiles/tiny_db.dir/flags.make
CMakeFiles/tiny_db.dir/src/part_table/Table.cpp.o: src/part_table/Table.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mazijie/CLionProjects/tiny_db/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/tiny_db.dir/src/part_table/Table.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tiny_db.dir/src/part_table/Table.cpp.o -c /Users/mazijie/CLionProjects/tiny_db/src/part_table/Table.cpp

CMakeFiles/tiny_db.dir/src/part_table/Table.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tiny_db.dir/src/part_table/Table.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mazijie/CLionProjects/tiny_db/src/part_table/Table.cpp > CMakeFiles/tiny_db.dir/src/part_table/Table.cpp.i

CMakeFiles/tiny_db.dir/src/part_table/Table.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tiny_db.dir/src/part_table/Table.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mazijie/CLionProjects/tiny_db/src/part_table/Table.cpp -o CMakeFiles/tiny_db.dir/src/part_table/Table.cpp.s

CMakeFiles/tiny_db.dir/src/part_table/Row.cpp.o: CMakeFiles/tiny_db.dir/flags.make
CMakeFiles/tiny_db.dir/src/part_table/Row.cpp.o: src/part_table/Row.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mazijie/CLionProjects/tiny_db/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/tiny_db.dir/src/part_table/Row.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tiny_db.dir/src/part_table/Row.cpp.o -c /Users/mazijie/CLionProjects/tiny_db/src/part_table/Row.cpp

CMakeFiles/tiny_db.dir/src/part_table/Row.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tiny_db.dir/src/part_table/Row.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mazijie/CLionProjects/tiny_db/src/part_table/Row.cpp > CMakeFiles/tiny_db.dir/src/part_table/Row.cpp.i

CMakeFiles/tiny_db.dir/src/part_table/Row.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tiny_db.dir/src/part_table/Row.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mazijie/CLionProjects/tiny_db/src/part_table/Row.cpp -o CMakeFiles/tiny_db.dir/src/part_table/Row.cpp.s

CMakeFiles/tiny_db.dir/src/part_table/Pager.cpp.o: CMakeFiles/tiny_db.dir/flags.make
CMakeFiles/tiny_db.dir/src/part_table/Pager.cpp.o: src/part_table/Pager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mazijie/CLionProjects/tiny_db/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/tiny_db.dir/src/part_table/Pager.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tiny_db.dir/src/part_table/Pager.cpp.o -c /Users/mazijie/CLionProjects/tiny_db/src/part_table/Pager.cpp

CMakeFiles/tiny_db.dir/src/part_table/Pager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tiny_db.dir/src/part_table/Pager.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mazijie/CLionProjects/tiny_db/src/part_table/Pager.cpp > CMakeFiles/tiny_db.dir/src/part_table/Pager.cpp.i

CMakeFiles/tiny_db.dir/src/part_table/Pager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tiny_db.dir/src/part_table/Pager.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mazijie/CLionProjects/tiny_db/src/part_table/Pager.cpp -o CMakeFiles/tiny_db.dir/src/part_table/Pager.cpp.s

CMakeFiles/tiny_db.dir/src/part_cursor/Cursor.cpp.o: CMakeFiles/tiny_db.dir/flags.make
CMakeFiles/tiny_db.dir/src/part_cursor/Cursor.cpp.o: src/part_cursor/Cursor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mazijie/CLionProjects/tiny_db/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/tiny_db.dir/src/part_cursor/Cursor.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tiny_db.dir/src/part_cursor/Cursor.cpp.o -c /Users/mazijie/CLionProjects/tiny_db/src/part_cursor/Cursor.cpp

CMakeFiles/tiny_db.dir/src/part_cursor/Cursor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tiny_db.dir/src/part_cursor/Cursor.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mazijie/CLionProjects/tiny_db/src/part_cursor/Cursor.cpp > CMakeFiles/tiny_db.dir/src/part_cursor/Cursor.cpp.i

CMakeFiles/tiny_db.dir/src/part_cursor/Cursor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tiny_db.dir/src/part_cursor/Cursor.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mazijie/CLionProjects/tiny_db/src/part_cursor/Cursor.cpp -o CMakeFiles/tiny_db.dir/src/part_cursor/Cursor.cpp.s

CMakeFiles/tiny_db.dir/src/part_tree/Node.cpp.o: CMakeFiles/tiny_db.dir/flags.make
CMakeFiles/tiny_db.dir/src/part_tree/Node.cpp.o: src/part_tree/Node.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mazijie/CLionProjects/tiny_db/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/tiny_db.dir/src/part_tree/Node.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tiny_db.dir/src/part_tree/Node.cpp.o -c /Users/mazijie/CLionProjects/tiny_db/src/part_tree/Node.cpp

CMakeFiles/tiny_db.dir/src/part_tree/Node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tiny_db.dir/src/part_tree/Node.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mazijie/CLionProjects/tiny_db/src/part_tree/Node.cpp > CMakeFiles/tiny_db.dir/src/part_tree/Node.cpp.i

CMakeFiles/tiny_db.dir/src/part_tree/Node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tiny_db.dir/src/part_tree/Node.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mazijie/CLionProjects/tiny_db/src/part_tree/Node.cpp -o CMakeFiles/tiny_db.dir/src/part_tree/Node.cpp.s

# Object files for target tiny_db
tiny_db_OBJECTS = \
"CMakeFiles/tiny_db.dir/main.cpp.o" \
"CMakeFiles/tiny_db.dir/src/part_input/InputBuffer.cpp.o" \
"CMakeFiles/tiny_db.dir/src/part_process/Process.cpp.o" \
"CMakeFiles/tiny_db.dir/src/part_command/Command.cpp.o" \
"CMakeFiles/tiny_db.dir/src/part_table/Table.cpp.o" \
"CMakeFiles/tiny_db.dir/src/part_table/Row.cpp.o" \
"CMakeFiles/tiny_db.dir/src/part_table/Pager.cpp.o" \
"CMakeFiles/tiny_db.dir/src/part_cursor/Cursor.cpp.o" \
"CMakeFiles/tiny_db.dir/src/part_tree/Node.cpp.o"

# External object files for target tiny_db
tiny_db_EXTERNAL_OBJECTS =

tiny_db: CMakeFiles/tiny_db.dir/main.cpp.o
tiny_db: CMakeFiles/tiny_db.dir/src/part_input/InputBuffer.cpp.o
tiny_db: CMakeFiles/tiny_db.dir/src/part_process/Process.cpp.o
tiny_db: CMakeFiles/tiny_db.dir/src/part_command/Command.cpp.o
tiny_db: CMakeFiles/tiny_db.dir/src/part_table/Table.cpp.o
tiny_db: CMakeFiles/tiny_db.dir/src/part_table/Row.cpp.o
tiny_db: CMakeFiles/tiny_db.dir/src/part_table/Pager.cpp.o
tiny_db: CMakeFiles/tiny_db.dir/src/part_cursor/Cursor.cpp.o
tiny_db: CMakeFiles/tiny_db.dir/src/part_tree/Node.cpp.o
tiny_db: CMakeFiles/tiny_db.dir/build.make
tiny_db: CMakeFiles/tiny_db.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mazijie/CLionProjects/tiny_db/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable tiny_db"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tiny_db.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tiny_db.dir/build: tiny_db

.PHONY : CMakeFiles/tiny_db.dir/build

CMakeFiles/tiny_db.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tiny_db.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tiny_db.dir/clean

CMakeFiles/tiny_db.dir/depend:
	cd /Users/mazijie/CLionProjects/tiny_db && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mazijie/CLionProjects/tiny_db /Users/mazijie/CLionProjects/tiny_db /Users/mazijie/CLionProjects/tiny_db /Users/mazijie/CLionProjects/tiny_db /Users/mazijie/CLionProjects/tiny_db/CMakeFiles/tiny_db.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tiny_db.dir/depend
