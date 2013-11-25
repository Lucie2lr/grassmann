cmake_minimum_required (VERSION 2.8)
project (Grassmann)

## Compilation du programme
add_library(grassmann_lib Grassmann.cpp)
add_library(scalar Scalar.cpp)
add_library(vecotr Vector.cpp)
add_library(bivector Bivector.cpp)
add_library(trivector Trivector.cpp)
add_library(quadvector Quadvector.cpp)

# programme point qui link avec la librairie
add_executable(grassmann main.cpp)
target_link_libraries(grassmann grassmann_lib scalar vector bivector trivector quadvector)

