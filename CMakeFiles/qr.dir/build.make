# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_SOURCE_DIR = /home/pi/Desktop/省综技2.0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/Desktop/省综技2.0

# Include any dependencies generated for this target.
include CMakeFiles/qr.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/qr.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/qr.dir/flags.make

CMakeFiles/qr.dir/Discriminate.cpp.o: CMakeFiles/qr.dir/flags.make
CMakeFiles/qr.dir/Discriminate.cpp.o: Discriminate.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Desktop/省综技2.0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/qr.dir/Discriminate.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/qr.dir/Discriminate.cpp.o -c /home/pi/Desktop/省综技2.0/Discriminate.cpp

CMakeFiles/qr.dir/Discriminate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/qr.dir/Discriminate.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/Desktop/省综技2.0/Discriminate.cpp > CMakeFiles/qr.dir/Discriminate.cpp.i

CMakeFiles/qr.dir/Discriminate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/qr.dir/Discriminate.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/Desktop/省综技2.0/Discriminate.cpp -o CMakeFiles/qr.dir/Discriminate.cpp.s

CMakeFiles/qr.dir/main.cpp.o: CMakeFiles/qr.dir/flags.make
CMakeFiles/qr.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Desktop/省综技2.0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/qr.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/qr.dir/main.cpp.o -c /home/pi/Desktop/省综技2.0/main.cpp

CMakeFiles/qr.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/qr.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/Desktop/省综技2.0/main.cpp > CMakeFiles/qr.dir/main.cpp.i

CMakeFiles/qr.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/qr.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/Desktop/省综技2.0/main.cpp -o CMakeFiles/qr.dir/main.cpp.s

# Object files for target qr
qr_OBJECTS = \
"CMakeFiles/qr.dir/Discriminate.cpp.o" \
"CMakeFiles/qr.dir/main.cpp.o"

# External object files for target qr
qr_EXTERNAL_OBJECTS =

qr: CMakeFiles/qr.dir/Discriminate.cpp.o
qr: CMakeFiles/qr.dir/main.cpp.o
qr: CMakeFiles/qr.dir/build.make
qr: /usr/local/lib/libopencv_dnn.so.4.2.0
qr: /usr/local/lib/libopencv_gapi.so.4.2.0
qr: /usr/local/lib/libopencv_highgui.so.4.2.0
qr: /usr/local/lib/libopencv_ml.so.4.2.0
qr: /usr/local/lib/libopencv_objdetect.so.4.2.0
qr: /usr/local/lib/libopencv_photo.so.4.2.0
qr: /usr/local/lib/libopencv_stitching.so.4.2.0
qr: /usr/local/lib/libopencv_video.so.4.2.0
qr: /usr/local/lib/libopencv_videoio.so.4.2.0
qr: /usr/lib/libwiringPi.so
qr: /usr/local/lib/libopencv_imgcodecs.so.4.2.0
qr: /usr/local/lib/libopencv_calib3d.so.4.2.0
qr: /usr/local/lib/libopencv_features2d.so.4.2.0
qr: /usr/local/lib/libopencv_flann.so.4.2.0
qr: /usr/local/lib/libopencv_imgproc.so.4.2.0
qr: /usr/local/lib/libopencv_core.so.4.2.0
qr: CMakeFiles/qr.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/Desktop/省综技2.0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable qr"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/qr.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/qr.dir/build: qr

.PHONY : CMakeFiles/qr.dir/build

CMakeFiles/qr.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/qr.dir/cmake_clean.cmake
.PHONY : CMakeFiles/qr.dir/clean

CMakeFiles/qr.dir/depend:
	cd /home/pi/Desktop/省综技2.0 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/Desktop/省综技2.0 /home/pi/Desktop/省综技2.0 /home/pi/Desktop/省综技2.0 /home/pi/Desktop/省综技2.0 /home/pi/Desktop/省综技2.0/CMakeFiles/qr.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/qr.dir/depend

