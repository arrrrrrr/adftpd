cmake_minimum_required(VERSION 3.17)
project(adftpd)

set(CMAKE_CXX_STANDARD 17)

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
        ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL)

# Setup boost and abseil parameters
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
set(BOOST_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../libs/boost_1_73_0")
set(BOOST_LIBRARY_DIRS "${BOOST_ROOT}/stage/lib")
set(absl_DIR  "${CMAKE_CURRENT_SOURCE_DIR}/../vcpkg/installed/x64-windows/share/absl")
find_package(Boost REQUIRED COMPONENTS program_options)
find_package(absl REQUIRED)

if(Boost_FOUND)
    add_executable(adftpd main.cpp config/reader.h config/master_reader.cpp config/master_reader.h config/slave_reader.cpp config/slave_reader.h config/default_config.cpp config/default_config.h config/constants.cpp config/constants.h tests/config_reader_test.cpp config/config_factory.cpp config/config_factory.h app/constants.cpp app/constants.h app/cli_option_parser.cpp app/cli_option_parser.h app/logger.h app/console_logger.cpp app/console_logger.h application.cpp application.h app/common.h config/common.h app/file_logger.cpp app/file_logger.h app/file_exception.cpp app/file_exception.h)
    include_directories(${Boost_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR})
    link_directories(${Boost_LIBRARY_DIRS})
    target_link_libraries(adftpd ${Boost_LIBRARIES} gtest_main)
endif()



