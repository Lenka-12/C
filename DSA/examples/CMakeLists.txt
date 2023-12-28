project(DSA)


add_executable(main main.c)


# Linking to static library
target_link_libraries(main 
    PRIVATE
    dsa)