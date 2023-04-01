cmake_minimum_required(VERSION 3.22)

project(Rational VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -Werror)

add_executable( rational 
    main.cpp
    Rational.cpp )