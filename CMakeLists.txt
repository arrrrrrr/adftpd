cmake_minimum_required(VERSION 3.17)
project(adftpd)

set(CMAKE_CXX_STANDARD 17)
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
set(BOOST_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../libs/boost_1_73_0")

find_package(Boost 1.73.0)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(adftpd main.cpp)
    target_link_libraries(adftpd ${Boost_LIBRARIES})
endif()



