##
## EPITECH PROJECT, 2018
## simulator_bpce
## File description:
## CMakeLists
##

project(BPCE_all_banks_simulator)

cmake_minimum_required(VERSION 2.6)

file(
        GLOB_RECURSE
        src_files
        src/*.cpp
        src/includes/*.hpp
)

include_directories(${general_includes_dir})

add_executable(
        simulator
        ${src_files}
)