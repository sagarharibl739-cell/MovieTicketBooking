cmake_minimum_required(VERSION 3.16)

project(MovieTicketBooking)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

# Library
add_library(movielib
    src/Movie.cpp
)

# Executable
add_executable(movie_booking
    src/main.cpp
)

target_link_libraries(movie_booking movielib)

# Enable testing
enable_testing()

# Tests
add_subdirectory(tests)
