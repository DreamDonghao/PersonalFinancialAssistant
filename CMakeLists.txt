cmake_minimum_required(VERSION 3.31)
project(personal_financial_assistant)

set(CMAKE_CXX_STANDARD 23)

include_directories(
        include
)

add_executable(personal_financial_assistant
        src/main.cpp
        src/time.cpp
        src/record.cpp
        src/recordList.cpp
        src/user.cpp
        include/user.hpp
)

