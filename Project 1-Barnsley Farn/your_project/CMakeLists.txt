# Always specify which version you need:
# - at least VERSION 3
# - EIKON has VERSION 3.10.2 available
cmake_minimum_required (VERSION 3.10)

#set (CMAKE_CXX_STANDARD 11)

# This defines ${PROJECT_NAME}, use it to change the name of your executable easily
project(HA)

# Prevent compilation in-source directory
if( ${CMAKE_BINARY_DIR} STREQUAL ${PROJECT_SOURCE_DIR} )
  Message( FATAL_ERROR "Source and build directories are the same!")
endif()

# Good practice, collect all *.cpp files into a variable
set(SRC_FILES main.cpp)

# Add additional include directories (those of the library):
include_directories("inc")

# Add additional link directories (those of the library):
# -> Linker is informed about path for creating the executable
# -> For Shared Library: Hardcoded path '../lib/libdemo.so' in the executable
# -> 'lib' is a default path, so this line is somewhat optional
link_directories("lib")



# This creates a Makefile to produce the executables
add_executable(${PROJECT_NAME} ${SRC_FILES})

target_compile_options(${PROJECT_NAME} PRIVATE -O2 -L/usr/X11R6/lib -lm -lpthread -lX11)


# Finally, we have to link the executable against our library, 'lib' and '.so' must be ommited
target_link_libraries(${PROJECT_NAME} demo)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(${PROJECT_NAME} Threads::Threads)
target_link_libraries(${PROJECT_NAME} X11)
