# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\White\source\C_course\week1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\White\source\C_course\week1\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\task03.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\task03.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\task03.dir\flags.make

CMakeFiles\task03.dir\task3.cpp.obj: CMakeFiles\task03.dir\flags.make
CMakeFiles\task03.dir\task3.cpp.obj: ..\task3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\White\source\C_course\week1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/task03.dir/task3.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\task03.dir\task3.cpp.obj /FdCMakeFiles\task03.dir\ /FS -c C:\Users\White\source\C_course\week1\task3.cpp
<<

CMakeFiles\task03.dir\task3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task03.dir/task3.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe > CMakeFiles\task03.dir\task3.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\White\source\C_course\week1\task3.cpp
<<

CMakeFiles\task03.dir\task3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task03.dir/task3.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\task03.dir\task3.cpp.s /c C:\Users\White\source\C_course\week1\task3.cpp
<<

# Object files for target task03
task03_OBJECTS = \
"CMakeFiles\task03.dir\task3.cpp.obj"

# External object files for target task03
task03_EXTERNAL_OBJECTS =

task03.exe: CMakeFiles\task03.dir\task3.cpp.obj
task03.exe: CMakeFiles\task03.dir\build.make
task03.exe: CMakeFiles\task03.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\White\source\C_course\week1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable task03.exe"
	"C:\Program Files\JetBrains\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\task03.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\task03.dir\objects1.rsp @<<
 /out:task03.exe /implib:task03.lib /pdb:C:\Users\White\source\C_course\week1\cmake-build-debug\task03.pdb /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\task03.dir\build: task03.exe

.PHONY : CMakeFiles\task03.dir\build

CMakeFiles\task03.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\task03.dir\cmake_clean.cmake
.PHONY : CMakeFiles\task03.dir\clean

CMakeFiles\task03.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\White\source\C_course\week1 C:\Users\White\source\C_course\week1 C:\Users\White\source\C_course\week1\cmake-build-debug C:\Users\White\source\C_course\week1\cmake-build-debug C:\Users\White\source\C_course\week1\cmake-build-debug\CMakeFiles\task03.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\task03.dir\depend

