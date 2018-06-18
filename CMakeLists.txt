cmake_minimum_required(VERSION 3.10)
project(sneak)

set(CMAKE_CXX_STANDARD 17)

add_executable(sneak main.cpp GameController.cpp GameController.h Sneak.cpp Sneak.h Fruit.cpp Fruit.h Cartesian.cpp Cartesian.h Direction.cpp Direction.h)