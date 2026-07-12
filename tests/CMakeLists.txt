add_executable(test_movie test_movie.cpp)
target_link_libraries(test_movie movielib)
add_test(NAME MovieTest COMMAND test_movie)
