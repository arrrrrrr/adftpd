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

set(GTEST_INCLUDE_DIRS "${CMAKE_CURRENT_BINARY_DIR}/googletest-src/googletest/include")

file(GLOB_RECURSE APP_SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "app/*.cpp" "app/*.h")
file(GLOB_RECURSE CONFIG_SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "config/*.cpp" "config/*.h")
file(GLOB_RECURSE NET_SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "net/*.cpp" "net/*.h")

if(Boost_FOUND)
    add_executable(adftpd main.cpp application.cpp application.h
                   config/common.h config/config_builder.cpp config/config_builder.h config/config_factory.cpp config/config_factory.h config/constants.cpp config/constants.h
                   config/config_exception.cpp config/config_exception.h config/master_reader.cpp config/master_reader.h
                   config/reader.cpp config/reader.h config/slave_reader.cpp config/slave_reader.h
                   app/cli_option_parser.cpp app/cli_option_parser.h app/common.h app/console_logger.cpp app/console_logger.h
                   app/constants.cpp app/constants.h app/file_exception.cpp app/file_exception.h app/file_logger.cpp app/file_logger.h app/logger.h utils/json.h utils/common.h)
    add_executable(adftpd_test tests/tests.cpp tests/cli_option_parser_test.h tests/logger_test.h
                   ${CONFIG_SOURCES} ${APP_SOURCES} ${NET_SOURCES} tests/config_reader_test.h)
    include_directories(${Boost_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR} ${GTEST_INCLUDE_DIRS})
    link_directories(${Boost_LIBRARY_DIRS})
    target_link_libraries(adftpd ${Boost_LIBRARIES})
    target_link_libraries(adftpd_test ${Boost_LIBRARIES} gtest_main)
endif()



