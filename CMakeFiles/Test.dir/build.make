# CMAKE generated file: DO NOT EDIT!
# Generated by "MSYS Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = "/D/Program Files/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "/D/Program Files/CMake/bin/cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /C/Gelis/Programs/Waves

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /C/Gelis/Programs/Waves

# Include any dependencies generated for this target.
include CMakeFiles/Test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Test.dir/flags.make

CMakeFiles/Test.dir/src/main.cpp.obj: CMakeFiles/Test.dir/flags.make
CMakeFiles/Test.dir/src/main.cpp.obj: CMakeFiles/Test.dir/includes_CXX.rsp
CMakeFiles/Test.dir/src/main.cpp.obj: src/main.cpp
CMakeFiles/Test.dir/src/main.cpp.obj: CMakeFiles/Test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/C/Gelis/Programs/Waves/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Test.dir/src/main.cpp.obj"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Test.dir/src/main.cpp.obj -MF CMakeFiles/Test.dir/src/main.cpp.obj.d -o CMakeFiles/Test.dir/src/main.cpp.obj -c /C/Gelis/Programs/Waves/src/main.cpp

CMakeFiles/Test.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Test.dir/src/main.cpp.i"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /C/Gelis/Programs/Waves/src/main.cpp > CMakeFiles/Test.dir/src/main.cpp.i

CMakeFiles/Test.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Test.dir/src/main.cpp.s"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /C/Gelis/Programs/Waves/src/main.cpp -o CMakeFiles/Test.dir/src/main.cpp.s

CMakeFiles/Test.dir/src/Shader.cpp.obj: CMakeFiles/Test.dir/flags.make
CMakeFiles/Test.dir/src/Shader.cpp.obj: CMakeFiles/Test.dir/includes_CXX.rsp
CMakeFiles/Test.dir/src/Shader.cpp.obj: src/Shader.cpp
CMakeFiles/Test.dir/src/Shader.cpp.obj: CMakeFiles/Test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/C/Gelis/Programs/Waves/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Test.dir/src/Shader.cpp.obj"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Test.dir/src/Shader.cpp.obj -MF CMakeFiles/Test.dir/src/Shader.cpp.obj.d -o CMakeFiles/Test.dir/src/Shader.cpp.obj -c /C/Gelis/Programs/Waves/src/Shader.cpp

CMakeFiles/Test.dir/src/Shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Test.dir/src/Shader.cpp.i"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /C/Gelis/Programs/Waves/src/Shader.cpp > CMakeFiles/Test.dir/src/Shader.cpp.i

CMakeFiles/Test.dir/src/Shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Test.dir/src/Shader.cpp.s"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /C/Gelis/Programs/Waves/src/Shader.cpp -o CMakeFiles/Test.dir/src/Shader.cpp.s

CMakeFiles/Test.dir/src/Camera.cpp.obj: CMakeFiles/Test.dir/flags.make
CMakeFiles/Test.dir/src/Camera.cpp.obj: CMakeFiles/Test.dir/includes_CXX.rsp
CMakeFiles/Test.dir/src/Camera.cpp.obj: src/Camera.cpp
CMakeFiles/Test.dir/src/Camera.cpp.obj: CMakeFiles/Test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/C/Gelis/Programs/Waves/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Test.dir/src/Camera.cpp.obj"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Test.dir/src/Camera.cpp.obj -MF CMakeFiles/Test.dir/src/Camera.cpp.obj.d -o CMakeFiles/Test.dir/src/Camera.cpp.obj -c /C/Gelis/Programs/Waves/src/Camera.cpp

CMakeFiles/Test.dir/src/Camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Test.dir/src/Camera.cpp.i"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /C/Gelis/Programs/Waves/src/Camera.cpp > CMakeFiles/Test.dir/src/Camera.cpp.i

CMakeFiles/Test.dir/src/Camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Test.dir/src/Camera.cpp.s"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /C/Gelis/Programs/Waves/src/Camera.cpp -o CMakeFiles/Test.dir/src/Camera.cpp.s

CMakeFiles/Test.dir/src/Brush.cpp.obj: CMakeFiles/Test.dir/flags.make
CMakeFiles/Test.dir/src/Brush.cpp.obj: CMakeFiles/Test.dir/includes_CXX.rsp
CMakeFiles/Test.dir/src/Brush.cpp.obj: src/Brush.cpp
CMakeFiles/Test.dir/src/Brush.cpp.obj: CMakeFiles/Test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/C/Gelis/Programs/Waves/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Test.dir/src/Brush.cpp.obj"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Test.dir/src/Brush.cpp.obj -MF CMakeFiles/Test.dir/src/Brush.cpp.obj.d -o CMakeFiles/Test.dir/src/Brush.cpp.obj -c /C/Gelis/Programs/Waves/src/Brush.cpp

CMakeFiles/Test.dir/src/Brush.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Test.dir/src/Brush.cpp.i"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /C/Gelis/Programs/Waves/src/Brush.cpp > CMakeFiles/Test.dir/src/Brush.cpp.i

CMakeFiles/Test.dir/src/Brush.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Test.dir/src/Brush.cpp.s"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /C/Gelis/Programs/Waves/src/Brush.cpp -o CMakeFiles/Test.dir/src/Brush.cpp.s

CMakeFiles/Test.dir/include/imgui/imgui_draw.cpp.obj: CMakeFiles/Test.dir/flags.make
CMakeFiles/Test.dir/include/imgui/imgui_draw.cpp.obj: CMakeFiles/Test.dir/includes_CXX.rsp
CMakeFiles/Test.dir/include/imgui/imgui_draw.cpp.obj: include/imgui/imgui_draw.cpp
CMakeFiles/Test.dir/include/imgui/imgui_draw.cpp.obj: CMakeFiles/Test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/C/Gelis/Programs/Waves/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Test.dir/include/imgui/imgui_draw.cpp.obj"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Test.dir/include/imgui/imgui_draw.cpp.obj -MF CMakeFiles/Test.dir/include/imgui/imgui_draw.cpp.obj.d -o CMakeFiles/Test.dir/include/imgui/imgui_draw.cpp.obj -c /C/Gelis/Programs/Waves/include/imgui/imgui_draw.cpp

CMakeFiles/Test.dir/include/imgui/imgui_draw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Test.dir/include/imgui/imgui_draw.cpp.i"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /C/Gelis/Programs/Waves/include/imgui/imgui_draw.cpp > CMakeFiles/Test.dir/include/imgui/imgui_draw.cpp.i

CMakeFiles/Test.dir/include/imgui/imgui_draw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Test.dir/include/imgui/imgui_draw.cpp.s"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /C/Gelis/Programs/Waves/include/imgui/imgui_draw.cpp -o CMakeFiles/Test.dir/include/imgui/imgui_draw.cpp.s

CMakeFiles/Test.dir/include/imgui/imgui_impl_glfw.cpp.obj: CMakeFiles/Test.dir/flags.make
CMakeFiles/Test.dir/include/imgui/imgui_impl_glfw.cpp.obj: CMakeFiles/Test.dir/includes_CXX.rsp
CMakeFiles/Test.dir/include/imgui/imgui_impl_glfw.cpp.obj: include/imgui/imgui_impl_glfw.cpp
CMakeFiles/Test.dir/include/imgui/imgui_impl_glfw.cpp.obj: CMakeFiles/Test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/C/Gelis/Programs/Waves/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Test.dir/include/imgui/imgui_impl_glfw.cpp.obj"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Test.dir/include/imgui/imgui_impl_glfw.cpp.obj -MF CMakeFiles/Test.dir/include/imgui/imgui_impl_glfw.cpp.obj.d -o CMakeFiles/Test.dir/include/imgui/imgui_impl_glfw.cpp.obj -c /C/Gelis/Programs/Waves/include/imgui/imgui_impl_glfw.cpp

CMakeFiles/Test.dir/include/imgui/imgui_impl_glfw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Test.dir/include/imgui/imgui_impl_glfw.cpp.i"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /C/Gelis/Programs/Waves/include/imgui/imgui_impl_glfw.cpp > CMakeFiles/Test.dir/include/imgui/imgui_impl_glfw.cpp.i

CMakeFiles/Test.dir/include/imgui/imgui_impl_glfw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Test.dir/include/imgui/imgui_impl_glfw.cpp.s"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /C/Gelis/Programs/Waves/include/imgui/imgui_impl_glfw.cpp -o CMakeFiles/Test.dir/include/imgui/imgui_impl_glfw.cpp.s

CMakeFiles/Test.dir/include/imgui/imgui_impl_opengl3.cpp.obj: CMakeFiles/Test.dir/flags.make
CMakeFiles/Test.dir/include/imgui/imgui_impl_opengl3.cpp.obj: CMakeFiles/Test.dir/includes_CXX.rsp
CMakeFiles/Test.dir/include/imgui/imgui_impl_opengl3.cpp.obj: include/imgui/imgui_impl_opengl3.cpp
CMakeFiles/Test.dir/include/imgui/imgui_impl_opengl3.cpp.obj: CMakeFiles/Test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/C/Gelis/Programs/Waves/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Test.dir/include/imgui/imgui_impl_opengl3.cpp.obj"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Test.dir/include/imgui/imgui_impl_opengl3.cpp.obj -MF CMakeFiles/Test.dir/include/imgui/imgui_impl_opengl3.cpp.obj.d -o CMakeFiles/Test.dir/include/imgui/imgui_impl_opengl3.cpp.obj -c /C/Gelis/Programs/Waves/include/imgui/imgui_impl_opengl3.cpp

CMakeFiles/Test.dir/include/imgui/imgui_impl_opengl3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Test.dir/include/imgui/imgui_impl_opengl3.cpp.i"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /C/Gelis/Programs/Waves/include/imgui/imgui_impl_opengl3.cpp > CMakeFiles/Test.dir/include/imgui/imgui_impl_opengl3.cpp.i

CMakeFiles/Test.dir/include/imgui/imgui_impl_opengl3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Test.dir/include/imgui/imgui_impl_opengl3.cpp.s"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /C/Gelis/Programs/Waves/include/imgui/imgui_impl_opengl3.cpp -o CMakeFiles/Test.dir/include/imgui/imgui_impl_opengl3.cpp.s

CMakeFiles/Test.dir/include/imgui/imgui.cpp.obj: CMakeFiles/Test.dir/flags.make
CMakeFiles/Test.dir/include/imgui/imgui.cpp.obj: CMakeFiles/Test.dir/includes_CXX.rsp
CMakeFiles/Test.dir/include/imgui/imgui.cpp.obj: include/imgui/imgui.cpp
CMakeFiles/Test.dir/include/imgui/imgui.cpp.obj: CMakeFiles/Test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/C/Gelis/Programs/Waves/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Test.dir/include/imgui/imgui.cpp.obj"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Test.dir/include/imgui/imgui.cpp.obj -MF CMakeFiles/Test.dir/include/imgui/imgui.cpp.obj.d -o CMakeFiles/Test.dir/include/imgui/imgui.cpp.obj -c /C/Gelis/Programs/Waves/include/imgui/imgui.cpp

CMakeFiles/Test.dir/include/imgui/imgui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Test.dir/include/imgui/imgui.cpp.i"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /C/Gelis/Programs/Waves/include/imgui/imgui.cpp > CMakeFiles/Test.dir/include/imgui/imgui.cpp.i

CMakeFiles/Test.dir/include/imgui/imgui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Test.dir/include/imgui/imgui.cpp.s"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /C/Gelis/Programs/Waves/include/imgui/imgui.cpp -o CMakeFiles/Test.dir/include/imgui/imgui.cpp.s

CMakeFiles/Test.dir/include/imgui/imgui_demo.cpp.obj: CMakeFiles/Test.dir/flags.make
CMakeFiles/Test.dir/include/imgui/imgui_demo.cpp.obj: CMakeFiles/Test.dir/includes_CXX.rsp
CMakeFiles/Test.dir/include/imgui/imgui_demo.cpp.obj: include/imgui/imgui_demo.cpp
CMakeFiles/Test.dir/include/imgui/imgui_demo.cpp.obj: CMakeFiles/Test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/C/Gelis/Programs/Waves/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Test.dir/include/imgui/imgui_demo.cpp.obj"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Test.dir/include/imgui/imgui_demo.cpp.obj -MF CMakeFiles/Test.dir/include/imgui/imgui_demo.cpp.obj.d -o CMakeFiles/Test.dir/include/imgui/imgui_demo.cpp.obj -c /C/Gelis/Programs/Waves/include/imgui/imgui_demo.cpp

CMakeFiles/Test.dir/include/imgui/imgui_demo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Test.dir/include/imgui/imgui_demo.cpp.i"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /C/Gelis/Programs/Waves/include/imgui/imgui_demo.cpp > CMakeFiles/Test.dir/include/imgui/imgui_demo.cpp.i

CMakeFiles/Test.dir/include/imgui/imgui_demo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Test.dir/include/imgui/imgui_demo.cpp.s"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /C/Gelis/Programs/Waves/include/imgui/imgui_demo.cpp -o CMakeFiles/Test.dir/include/imgui/imgui_demo.cpp.s

CMakeFiles/Test.dir/include/imgui/imgui_tables.cpp.obj: CMakeFiles/Test.dir/flags.make
CMakeFiles/Test.dir/include/imgui/imgui_tables.cpp.obj: CMakeFiles/Test.dir/includes_CXX.rsp
CMakeFiles/Test.dir/include/imgui/imgui_tables.cpp.obj: include/imgui/imgui_tables.cpp
CMakeFiles/Test.dir/include/imgui/imgui_tables.cpp.obj: CMakeFiles/Test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/C/Gelis/Programs/Waves/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Test.dir/include/imgui/imgui_tables.cpp.obj"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Test.dir/include/imgui/imgui_tables.cpp.obj -MF CMakeFiles/Test.dir/include/imgui/imgui_tables.cpp.obj.d -o CMakeFiles/Test.dir/include/imgui/imgui_tables.cpp.obj -c /C/Gelis/Programs/Waves/include/imgui/imgui_tables.cpp

CMakeFiles/Test.dir/include/imgui/imgui_tables.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Test.dir/include/imgui/imgui_tables.cpp.i"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /C/Gelis/Programs/Waves/include/imgui/imgui_tables.cpp > CMakeFiles/Test.dir/include/imgui/imgui_tables.cpp.i

CMakeFiles/Test.dir/include/imgui/imgui_tables.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Test.dir/include/imgui/imgui_tables.cpp.s"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /C/Gelis/Programs/Waves/include/imgui/imgui_tables.cpp -o CMakeFiles/Test.dir/include/imgui/imgui_tables.cpp.s

CMakeFiles/Test.dir/include/imgui/imgui_widgets.cpp.obj: CMakeFiles/Test.dir/flags.make
CMakeFiles/Test.dir/include/imgui/imgui_widgets.cpp.obj: CMakeFiles/Test.dir/includes_CXX.rsp
CMakeFiles/Test.dir/include/imgui/imgui_widgets.cpp.obj: include/imgui/imgui_widgets.cpp
CMakeFiles/Test.dir/include/imgui/imgui_widgets.cpp.obj: CMakeFiles/Test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/C/Gelis/Programs/Waves/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/Test.dir/include/imgui/imgui_widgets.cpp.obj"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Test.dir/include/imgui/imgui_widgets.cpp.obj -MF CMakeFiles/Test.dir/include/imgui/imgui_widgets.cpp.obj.d -o CMakeFiles/Test.dir/include/imgui/imgui_widgets.cpp.obj -c /C/Gelis/Programs/Waves/include/imgui/imgui_widgets.cpp

CMakeFiles/Test.dir/include/imgui/imgui_widgets.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Test.dir/include/imgui/imgui_widgets.cpp.i"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /C/Gelis/Programs/Waves/include/imgui/imgui_widgets.cpp > CMakeFiles/Test.dir/include/imgui/imgui_widgets.cpp.i

CMakeFiles/Test.dir/include/imgui/imgui_widgets.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Test.dir/include/imgui/imgui_widgets.cpp.s"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /C/Gelis/Programs/Waves/include/imgui/imgui_widgets.cpp -o CMakeFiles/Test.dir/include/imgui/imgui_widgets.cpp.s

# Object files for target Test
Test_OBJECTS = \
"CMakeFiles/Test.dir/src/main.cpp.obj" \
"CMakeFiles/Test.dir/src/Shader.cpp.obj" \
"CMakeFiles/Test.dir/src/Camera.cpp.obj" \
"CMakeFiles/Test.dir/src/Brush.cpp.obj" \
"CMakeFiles/Test.dir/include/imgui/imgui_draw.cpp.obj" \
"CMakeFiles/Test.dir/include/imgui/imgui_impl_glfw.cpp.obj" \
"CMakeFiles/Test.dir/include/imgui/imgui_impl_opengl3.cpp.obj" \
"CMakeFiles/Test.dir/include/imgui/imgui.cpp.obj" \
"CMakeFiles/Test.dir/include/imgui/imgui_demo.cpp.obj" \
"CMakeFiles/Test.dir/include/imgui/imgui_tables.cpp.obj" \
"CMakeFiles/Test.dir/include/imgui/imgui_widgets.cpp.obj"

# External object files for target Test
Test_EXTERNAL_OBJECTS =

bin/Test.exe: CMakeFiles/Test.dir/src/main.cpp.obj
bin/Test.exe: CMakeFiles/Test.dir/src/Shader.cpp.obj
bin/Test.exe: CMakeFiles/Test.dir/src/Camera.cpp.obj
bin/Test.exe: CMakeFiles/Test.dir/src/Brush.cpp.obj
bin/Test.exe: CMakeFiles/Test.dir/include/imgui/imgui_draw.cpp.obj
bin/Test.exe: CMakeFiles/Test.dir/include/imgui/imgui_impl_glfw.cpp.obj
bin/Test.exe: CMakeFiles/Test.dir/include/imgui/imgui_impl_opengl3.cpp.obj
bin/Test.exe: CMakeFiles/Test.dir/include/imgui/imgui.cpp.obj
bin/Test.exe: CMakeFiles/Test.dir/include/imgui/imgui_demo.cpp.obj
bin/Test.exe: CMakeFiles/Test.dir/include/imgui/imgui_tables.cpp.obj
bin/Test.exe: CMakeFiles/Test.dir/include/imgui/imgui_widgets.cpp.obj
bin/Test.exe: CMakeFiles/Test.dir/build.make
bin/Test.exe: CMakeFiles/Test.dir/linkLibs.rsp
bin/Test.exe: CMakeFiles/Test.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/C/Gelis/Programs/Waves/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX executable bin/Test.exe"
	"/D/Program Files/CMake/bin/cmake.exe" -E rm -f CMakeFiles/Test.dir/objects.a
	/C/msys64/mingw64/bin/ar.exe qc CMakeFiles/Test.dir/objects.a @CMakeFiles/Test.dir/objects1.rsp
	/C/msys64/mingw64/bin/g++.exe  -Wno-dev -Wl,--whole-archive CMakeFiles/Test.dir/objects.a -Wl,--no-whole-archive -o bin/Test.exe -Wl,--out-implib,libTest.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/Test.dir/linkLibs.rsp

# Rule to build all files generated by this target.
CMakeFiles/Test.dir/build: bin/Test.exe
.PHONY : CMakeFiles/Test.dir/build

CMakeFiles/Test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Test.dir/clean

CMakeFiles/Test.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MSYS Makefiles" /C/Gelis/Programs/Waves /C/Gelis/Programs/Waves /C/Gelis/Programs/Waves /C/Gelis/Programs/Waves /C/Gelis/Programs/Waves/CMakeFiles/Test.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Test.dir/depend
