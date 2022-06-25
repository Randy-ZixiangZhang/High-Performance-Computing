# C++ Toy Project
## Purpose of this ReadMe file
Recording the learning process: problem encountered.

## Environment Setup
- MAC, visual studio code. has embedded CMake supporter, it also asks user to select "kit". Now on M1, default is Clang ARM64.
### Issues
CImg library is dependent on X11, the default enviroment has link problem.
MAC OS accesses opt folder. "cd /opt"
built a separate project to compile X11 "hello world" project. "g++ main.cpp -I /opt/X11/include -L /opt/X11/lib" helped to solve "'X11/Xlib.h' file not found" issue
"g++ main.cpp -I /opt/X11/include -L /opt/X11/lib -lX11" successfully built!

-I adds a directory to the list of places searched by the compiler for a file named on a #include line, and -L adds a directory to the list of places searched by the linker for a library named with the -l option

## CMake specific

### Fundamentals of CMake:
 - Variables
#### Subdirectories
    "Binary dir" means build directory.
    Third-Party Library could be put in a separate dir, own written h could be with main.cpp if complexity manageble
 - Functions and Macros
 - Properties
 - Generator Expressions
 - Modules
 - Policies
 - Flow Control (for me never used)

### Builds in Depth

- Build Type
- Compiler and Linker Essentials
- Target Types
- Custom Tasks
- Working with Files
#### Specifying Version Details
    set(${PROJECT_NAME}_VERSION_MAJOR 1)
    set(${PROJECT_NAME}_VERSION_MINOR 0)
- Libraries
- Toolchain And Cross Compiling
- Apple Features


### Tutorial Problems
- config, the use of h.in and h is still a mystery. Why header file is located in build dir?

