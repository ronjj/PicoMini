# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.30.2/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.30.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ronaldjabouin/Documents/picominimain/PicoMini/_deps/cimg-subbuild

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ronaldjabouin/Documents/picominimain/PicoMini/_deps/cimg-subbuild

# Utility rule file for cimg-populate.

# Include any custom commands dependencies for this target.
include CMakeFiles/cimg-populate.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/cimg-populate.dir/progress.make

CMakeFiles/cimg-populate: CMakeFiles/cimg-populate-complete

CMakeFiles/cimg-populate-complete: cimg-populate-prefix/src/cimg-populate-stamp/cimg-populate-install
CMakeFiles/cimg-populate-complete: cimg-populate-prefix/src/cimg-populate-stamp/cimg-populate-mkdir
CMakeFiles/cimg-populate-complete: cimg-populate-prefix/src/cimg-populate-stamp/cimg-populate-download
CMakeFiles/cimg-populate-complete: cimg-populate-prefix/src/cimg-populate-stamp/cimg-populate-update
CMakeFiles/cimg-populate-complete: cimg-populate-prefix/src/cimg-populate-stamp/cimg-populate-patch
CMakeFiles/cimg-populate-complete: cimg-populate-prefix/src/cimg-populate-stamp/cimg-populate-configure
CMakeFiles/cimg-populate-complete: cimg-populate-prefix/src/cimg-populate-stamp/cimg-populate-build
CMakeFiles/cimg-populate-complete: cimg-populate-prefix/src/cimg-populate-stamp/cimg-populate-install
CMakeFiles/cimg-populate-complete: cimg-populate-prefix/src/cimg-populate-stamp/cimg-populate-test
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/ronaldjabouin/Documents/picominimain/PicoMini/_deps/cimg-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Completed 'cimg-populate'"
	/opt/homebrew/Cellar/cmake/3.30.2/bin/cmake -E make_directory /Users/ronaldjabouin/Documents/picominimain/PicoMini/_deps/cimg-subbuild/CMakeFiles
	/opt/homebrew/Cellar/cmake/3.30.2/bin/cmake -E touch /Users/ronaldjabouin/Documents/picominimain/PicoMini/_deps/cimg-subbuild/CMakeFiles/cimg-populate-complete
	/opt/homebrew/Cellar/cmake/3.30.2/bin/cmake -E touch /Users/ronaldjabouin/Documents/picominimain/PicoMini/_deps/cimg-subbuild/cimg-populate-prefix/src/cimg-populate-stamp/cimg-populate-done

cimg-populate-prefix/src/cimg-populate-stamp/cimg-populate-build: cimg-populate-prefix/src/cimg-populate-stamp/cimg-populate-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/ronaldjabouin/Documents/picominimain/PicoMini/_deps/cimg-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "No build step for 'cimg-populate'"
	cd /Users/ronaldjabouin/Documents/picominimain/picomini/_deps/cimg-build && /opt/homebrew/Cellar/cmake/3.30.2/bin/cmake -E echo_append
	cd /Users/ronaldjabouin/Documents/picominimain/picomini/_deps/cimg-build && /opt/homebrew/Cellar/cmake/3.30.2/bin/cmake -E touch /Users/ronaldjabouin/Documents/picominimain/PicoMini/_deps/cimg-subbuild/cimg-populate-prefix/src/cimg-populate-stamp/cimg-populate-build

cimg-populate-prefix/src/cimg-populate-stamp/cimg-populate-configure: cimg-populate-prefix/tmp/cimg-populate-cfgcmd.txt
cimg-populate-prefix/src/cimg-populate-stamp/cimg-populate-configure: cimg-populate-prefix/src/cimg-populate-stamp/cimg-populate-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/ronaldjabouin/Documents/picominimain/PicoMini/_deps/cimg-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "No configure step for 'cimg-populate'"
	cd /Users/ronaldjabouin/Documents/picominimain/picomini/_deps/cimg-build && /opt/homebrew/Cellar/cmake/3.30.2/bin/cmake -E echo_append
	cd /Users/ronaldjabouin/Documents/picominimain/picomini/_deps/cimg-build && /opt/homebrew/Cellar/cmake/3.30.2/bin/cmake -E touch /Users/ronaldjabouin/Documents/picominimain/PicoMini/_deps/cimg-subbuild/cimg-populate-prefix/src/cimg-populate-stamp/cimg-populate-configure

cimg-populate-prefix/src/cimg-populate-stamp/cimg-populate-download: cimg-populate-prefix/src/cimg-populate-stamp/download-cimg-populate.cmake
cimg-populate-prefix/src/cimg-populate-stamp/cimg-populate-download: cimg-populate-prefix/src/cimg-populate-stamp/cimg-populate-urlinfo.txt
cimg-populate-prefix/src/cimg-populate-stamp/cimg-populate-download: cimg-populate-prefix/src/cimg-populate-stamp/cimg-populate-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/ronaldjabouin/Documents/picominimain/PicoMini/_deps/cimg-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Performing download step (download, verify and extract) for 'cimg-populate'"
	cd /Users/ronaldjabouin/Documents/picominimain/picomini/_deps && /opt/homebrew/Cellar/cmake/3.30.2/bin/cmake -DCMAKE_MESSAGE_LOG_LEVEL=VERBOSE -P /Users/ronaldjabouin/Documents/picominimain/PicoMini/_deps/cimg-subbuild/cimg-populate-prefix/src/cimg-populate-stamp/download-cimg-populate.cmake
	cd /Users/ronaldjabouin/Documents/picominimain/picomini/_deps && /opt/homebrew/Cellar/cmake/3.30.2/bin/cmake -DCMAKE_MESSAGE_LOG_LEVEL=VERBOSE -P /Users/ronaldjabouin/Documents/picominimain/PicoMini/_deps/cimg-subbuild/cimg-populate-prefix/src/cimg-populate-stamp/verify-cimg-populate.cmake
	cd /Users/ronaldjabouin/Documents/picominimain/picomini/_deps && /opt/homebrew/Cellar/cmake/3.30.2/bin/cmake -DCMAKE_MESSAGE_LOG_LEVEL=VERBOSE -P /Users/ronaldjabouin/Documents/picominimain/PicoMini/_deps/cimg-subbuild/cimg-populate-prefix/src/cimg-populate-stamp/extract-cimg-populate.cmake
	cd /Users/ronaldjabouin/Documents/picominimain/picomini/_deps && /opt/homebrew/Cellar/cmake/3.30.2/bin/cmake -E touch /Users/ronaldjabouin/Documents/picominimain/PicoMini/_deps/cimg-subbuild/cimg-populate-prefix/src/cimg-populate-stamp/cimg-populate-download

cimg-populate-prefix/src/cimg-populate-stamp/cimg-populate-install: cimg-populate-prefix/src/cimg-populate-stamp/cimg-populate-build
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/ronaldjabouin/Documents/picominimain/PicoMini/_deps/cimg-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "No install step for 'cimg-populate'"
	cd /Users/ronaldjabouin/Documents/picominimain/picomini/_deps/cimg-build && /opt/homebrew/Cellar/cmake/3.30.2/bin/cmake -E echo_append
	cd /Users/ronaldjabouin/Documents/picominimain/picomini/_deps/cimg-build && /opt/homebrew/Cellar/cmake/3.30.2/bin/cmake -E touch /Users/ronaldjabouin/Documents/picominimain/PicoMini/_deps/cimg-subbuild/cimg-populate-prefix/src/cimg-populate-stamp/cimg-populate-install

cimg-populate-prefix/src/cimg-populate-stamp/cimg-populate-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/ronaldjabouin/Documents/picominimain/PicoMini/_deps/cimg-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Creating directories for 'cimg-populate'"
	/opt/homebrew/Cellar/cmake/3.30.2/bin/cmake -Dcfgdir= -P /Users/ronaldjabouin/Documents/picominimain/PicoMini/_deps/cimg-subbuild/cimg-populate-prefix/tmp/cimg-populate-mkdirs.cmake
	/opt/homebrew/Cellar/cmake/3.30.2/bin/cmake -E touch /Users/ronaldjabouin/Documents/picominimain/PicoMini/_deps/cimg-subbuild/cimg-populate-prefix/src/cimg-populate-stamp/cimg-populate-mkdir

cimg-populate-prefix/src/cimg-populate-stamp/cimg-populate-patch: cimg-populate-prefix/src/cimg-populate-stamp/cimg-populate-patch-info.txt
cimg-populate-prefix/src/cimg-populate-stamp/cimg-populate-patch: cimg-populate-prefix/src/cimg-populate-stamp/cimg-populate-update
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/ronaldjabouin/Documents/picominimain/PicoMini/_deps/cimg-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "No patch step for 'cimg-populate'"
	/opt/homebrew/Cellar/cmake/3.30.2/bin/cmake -E echo_append
	/opt/homebrew/Cellar/cmake/3.30.2/bin/cmake -E touch /Users/ronaldjabouin/Documents/picominimain/PicoMini/_deps/cimg-subbuild/cimg-populate-prefix/src/cimg-populate-stamp/cimg-populate-patch

cimg-populate-prefix/src/cimg-populate-stamp/cimg-populate-test: cimg-populate-prefix/src/cimg-populate-stamp/cimg-populate-install
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/ronaldjabouin/Documents/picominimain/PicoMini/_deps/cimg-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "No test step for 'cimg-populate'"
	cd /Users/ronaldjabouin/Documents/picominimain/picomini/_deps/cimg-build && /opt/homebrew/Cellar/cmake/3.30.2/bin/cmake -E echo_append
	cd /Users/ronaldjabouin/Documents/picominimain/picomini/_deps/cimg-build && /opt/homebrew/Cellar/cmake/3.30.2/bin/cmake -E touch /Users/ronaldjabouin/Documents/picominimain/PicoMini/_deps/cimg-subbuild/cimg-populate-prefix/src/cimg-populate-stamp/cimg-populate-test

cimg-populate-prefix/src/cimg-populate-stamp/cimg-populate-update: cimg-populate-prefix/src/cimg-populate-stamp/cimg-populate-update-info.txt
cimg-populate-prefix/src/cimg-populate-stamp/cimg-populate-update: cimg-populate-prefix/src/cimg-populate-stamp/cimg-populate-download
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/ronaldjabouin/Documents/picominimain/PicoMini/_deps/cimg-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "No update step for 'cimg-populate'"
	/opt/homebrew/Cellar/cmake/3.30.2/bin/cmake -E echo_append
	/opt/homebrew/Cellar/cmake/3.30.2/bin/cmake -E touch /Users/ronaldjabouin/Documents/picominimain/PicoMini/_deps/cimg-subbuild/cimg-populate-prefix/src/cimg-populate-stamp/cimg-populate-update

cimg-populate: CMakeFiles/cimg-populate
cimg-populate: CMakeFiles/cimg-populate-complete
cimg-populate: cimg-populate-prefix/src/cimg-populate-stamp/cimg-populate-build
cimg-populate: cimg-populate-prefix/src/cimg-populate-stamp/cimg-populate-configure
cimg-populate: cimg-populate-prefix/src/cimg-populate-stamp/cimg-populate-download
cimg-populate: cimg-populate-prefix/src/cimg-populate-stamp/cimg-populate-install
cimg-populate: cimg-populate-prefix/src/cimg-populate-stamp/cimg-populate-mkdir
cimg-populate: cimg-populate-prefix/src/cimg-populate-stamp/cimg-populate-patch
cimg-populate: cimg-populate-prefix/src/cimg-populate-stamp/cimg-populate-test
cimg-populate: cimg-populate-prefix/src/cimg-populate-stamp/cimg-populate-update
cimg-populate: CMakeFiles/cimg-populate.dir/build.make
.PHONY : cimg-populate

# Rule to build all files generated by this target.
CMakeFiles/cimg-populate.dir/build: cimg-populate
.PHONY : CMakeFiles/cimg-populate.dir/build

CMakeFiles/cimg-populate.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cimg-populate.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cimg-populate.dir/clean

CMakeFiles/cimg-populate.dir/depend:
	cd /Users/ronaldjabouin/Documents/picominimain/PicoMini/_deps/cimg-subbuild && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ronaldjabouin/Documents/picominimain/PicoMini/_deps/cimg-subbuild /Users/ronaldjabouin/Documents/picominimain/PicoMini/_deps/cimg-subbuild /Users/ronaldjabouin/Documents/picominimain/PicoMini/_deps/cimg-subbuild /Users/ronaldjabouin/Documents/picominimain/PicoMini/_deps/cimg-subbuild /Users/ronaldjabouin/Documents/picominimain/PicoMini/_deps/cimg-subbuild/CMakeFiles/cimg-populate.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/cimg-populate.dir/depend

