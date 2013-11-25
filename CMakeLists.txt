cmake_minimum_required(VERSION 2.8)
project (Grassmann)

set(CMAKE_CXX_FLAGS "-std=c++0x")

include_directories(eigen/Eigen)

include_directories(lib/include)
add_subdirectory(lib)

set(ALL_LIBRARIES GCA)

add_subdirectory(demo)
