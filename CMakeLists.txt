cmake_minimum_required(VERSION 3.17)
project(philosophers C)

set(CMAKE_C_STANDARD 11)

include_directories(philo_one)

add_executable(philosophers
        philo_one/main.c
        practice/main.c
        philo_one/philo_one.h)
