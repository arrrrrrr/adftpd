cmake_minimum_required(VERSION 3.17)
project(adftpd)

set(CMAKE_CXX_STANDARD 17)
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
set(BOOST_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../libs/boost_1_73_0")
set(absl_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../vcpkg/installed/x64-windows/share/absl")
find_package(Boost 1.73.0)
find_package(absl REQUIRED)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(adftpd main.cpp config/reader.h config/master_reader.cpp config/master_reader.h config/slave_reader.cpp config/slave_reader.h)
    target_link_libraries(adftpd ${Boost_LIBRARIES})
endif()



