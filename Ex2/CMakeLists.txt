cmake_minimum_required(VERSION 3.10)
project(vbdExamples)

include_directories(/usr/local/include/)
add_executable(vbdExamples Main.cpp)

set(CMAKE_BUILD_RPATH "/usr/local/lib")
set(CMAKE_INSTALL_RPATH "/usr/local/lib")
find_library(OPENVDB_LIBRARY openvdbdir HINTS /usr/local/lib)

target_link_libraries(vbdExamples openvdb tbb)
install(TARGETS vbdExamples DESTINATION bin)