cmake_minimum_required(VERSION 3.17)
project(adftpd)

set(CMAKE_CXX_STANDARD 17)
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
set(BOOST_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../libs/boost_1_73_0")
set(BOOST_LIBRARY_DIRS "${BOOST_ROOT}/stage/lib")
set(absl_DIR  "${CMAKE_CURRENT_SOURCE_DIR}/../vcpkg/installed/x64-windows/share/absl")
find_package(Boost REQUIRED COMPONENTS program_options)
find_package(absl REQUIRED)

add_executable(adftpd main.cpp config/reader.h config/master_reader.cpp config/master_reader.h config/slave_reader.cpp config/slave_reader.h config/default_config.cpp config/default_config.h)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    link_directories(${Boost_LIBRARY_DIRS})
    target_link_libraries(adftpd ${Boost_LIBRARIES})
endif()



