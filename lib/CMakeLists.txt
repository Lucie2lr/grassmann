INCLUDE_DIRECTORIES(include)
file(GLOB_RECURSE SRC_FILES *.cpp *.hpp)

add_library(GCA ${SRC_FILES})
target_link_libraries(GCA)
