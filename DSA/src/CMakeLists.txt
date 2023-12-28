project(DSA)
# Get all source files in a current directory
file(GLOB_RECURSE SRC_FILES *.c)

# define a library
add_library(dsa ${SRC_FILES})

target_include_directories(dsa
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../include)
    