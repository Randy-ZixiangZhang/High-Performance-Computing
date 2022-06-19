# Always specify which version you need:
# - at least VERSION 3
# - EIKON has VERSION 3.10.2 available
cmake_minimum_required (VERSION 3.10)

# Two things to do from "outside":
# Set CMAKE_BUILD_TYPE to Release, because the install configuration wants a Release build (for speed)
# Set CMAKE_INSTALL_PREFIX to the folder 'your_project'

# This defines ${PROJECT_NAME}, use it to change the name of your executable easily
# Here we use it to define the name for the library
project(demo)

# Prevent compilation in-source directory
if( ${CMAKE_BINARY_DIR} STREQUAL ${PROJECT_SOURCE_DIR} )
  Message( FATAL_ERROR "Source and build directories are the same!")
endif()

# The path required for installing the library, cmake moves the libdemo.so file in this folder
set(DEST_LIB lib/)

# The path required for installing the public headers, cmake moves the demo_lib.h file in this folder
# Default would be 'include', but this does not match previous examples
set(DEST_INC inc/)

# All *.cpp files that must be compiled
set(SRC_FILES demo_lib.cpp)

# All *.h files, which build the public interface
set(INC_FILES demo_lib.h)

set(HEADER_LIB CImg.h)

# This puts the code together into the library, no add_executable here!
add_library(${PROJECT_NAME} SHARED ${SRC_FILES})

add_library(Cool_Image INTERFACE)
target_include_directories(Cool_Image INTERFACE ${HEADER_LIB})

target_link_libraries(${PROJECT_NAME}
	PUBLIC Cool_Image)
target_compile_options(Cool_Image INTERFACE -O2 -L/usr/X11R6/lib -lm -lpthread -lX11)


# Tell cmake what belongs to public header files and must be copied
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER ${INC_FILES} PUBLIC_HEADER ${HEADER_LIB})

# Create the actual install target for the libary, DEST_LIB is relative to the install prefix
install(TARGETS ${PROJECT_NAME} 
  LIBRARY 
    DESTINATION ${DEST_LIB} CONFIGURATIONS Release
  PUBLIC_HEADER 
    DESTINATION ${DEST_INC})

# Or just copy the whole folder structure, sometimes this might be easier, in particular when you 
# have nested folders in your include directory (e.g. for Eigen ...)
# E.g. to copy your full inlucde directories as is:
# install(DIRECTORY ${INC_DIR} DESTINATION ${DEST_INC} MESSAGE_NEVER FILES_MATCHING PATTERN "*" )
