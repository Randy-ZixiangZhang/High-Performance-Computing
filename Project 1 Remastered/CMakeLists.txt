
# - EIKON has VERSION 3.10.2 available
cmake_minimum_required (VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)


project(LEAF)

# Prevent compilation in-source directory
if( ${CMAKE_BINARY_DIR} STREQUAL ${PROJECT_SOURCE_DIR} )
  Message( FATAL_ERROR "Source and build directories are the same!")
endif()

# Good practice, collect all *.cpp files into a variable
set(SRC_FILES main.cpp)

set(CMAKE_CXX_LINKER_FLAGSS -L/opt/X11/lib -lX11)


#INCLUDE_DIRECTORIES(/opt/X11)

# This creates a Makefile to produce the executables
add_executable(${PROJECT_NAME} ${SRC_FILES})


target_link_libraries(${PROJECT_NAME} pthread)

# Just change the default value if you want to disable the interactive window based on X11 library
option(YOU_NEED_X "Activates usage of X11 library"  OFF)

# # Just change the default value if CImg should not use libpng but the default ImageMagick
# # (I had problems with ImageMagick, hence the alternative based on libpng)
# option(YOU_NEED_PNG "Activates usage of png library" OFF)

# if(${YOU_NEED_PNG})
#     message(STATUS "Looking for libpng ...")

#     # Define a prepro variable to control the c++ code
#     add_definitions(-DYOU_NEED_PNG)

#     # Flags for Cool Image to enable native support for PNG image files, using the PNG library.
#     set(CIMG_PNG_CCFLAGS  -Dcimg_use_png)

#     # More details in third lecture
#     find_package(PNG REQUIRED)

#     #
#     include_directories(${PNG_INCLUDE_DIR})
#     target_link_libraries (${PROJECT_NAME} ${PNG_LIBRARY})
#     target_compile_definitions(${PROJECT_NAME} PRIVATE cimg_use_png=1)
# endif()

if(${YOU_NEED_X})
    message(STATUS "Looking for libx11 ...")

    add_definitions(-DYOU_NEED_X)
    find_package(X11 REQUIRED)
    include_directories(${X11_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} X11)
    message(STATUS "Done looking for libx11 ...")
endif()