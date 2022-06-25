project(X11_debug)
add_executable(${PROJECT_NAME} main.cpp)

target_compile_options(${PROJECT_NAME} PUBLIC -I/opt/X11/include)
#set(CMAKE_CXX_FLAGS "-I /opt/X11/include")
target_link_libraries(${PROJECT_NAME} PUBLIC "-L/opt/X11/lib -lX11")

#set(CMAKE_CXX_LINKER_FLAGSS  )