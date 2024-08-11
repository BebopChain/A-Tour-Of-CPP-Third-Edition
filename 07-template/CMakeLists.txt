cmake_minimum_required(VERSION 3.10)

project(07-template LANGUAGES CXX)

add_executable(cmaketest cmaketest.cpp)

add_executable(concepts concepts.cpp)

add_executable(templateargumentoperations templateargumentoperations.cpp)

add_executable(variable_templates variable_templates.cpp)

add_executable(lambda_finally lambda_finally.cpp)

add_executable(template_aliases template_aliases.cpp)

add_executable(compile_time_if  compile_time_if.cpp)