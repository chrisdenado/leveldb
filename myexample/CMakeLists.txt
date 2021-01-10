cmake_minimum_required(VERSION 3.9)

# C standard can be overridden when this is used as a sub-project.
if(NOT CMAKE_C_STANDARD)
    # This project can use C11, but will gracefully decay down to C89.
    set(CMAKE_C_STANDARD 11)
    set(CMAKE_C_STANDARD_REQUIRED OFF)
    set(CMAKE_C_EXTENSIONS OFF)
endif(NOT CMAKE_C_STANDARD)

# C++ standard can be overridden when this is used as a sub-project.
if(NOT CMAKE_CXX_STANDARD)
    # This project requires C++11.
    set(CMAKE_CXX_STANDARD 11)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)
endif(NOT CMAKE_CXX_STANDARD)

SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
set(THREADS_PREFER_PTHREAD_FLAG)

include_directories(../include)

add_executable(simple_use1 simple_use1.cpp)
target_link_libraries(simple_use1 leveldb pthread)
#target_link_libraries(simple_use1 ${PROJECT_SOURCE_DIR}/build/libleveldb.a pthread)

