cmake_minimum_required(VERSION 2.8.11)
project(PointVector CXX)

# Use C++11 standard
set(CMAKE_CXX_STANDARD 11)

# Set install directory
set(APP_INSTALL_DIR ${PROJECT_BINARY_DIR}/install CACHE PATH "Application install directory")
set(CMAKE_INSTALL_PREFIX ${APP_INSTALL_DIR})

# Set RPATH
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}")

include_directories(include/)

# Point test application
add_executable(point src/app_point.cpp)

# Vector test application
add_executable(vector src/app_vector.cpp)

# Add install target for test applications
install(TARGETS point vector DESTINATION ${APP_INSTALL_DIR})

# Add a custom target for calling inside IDEs
add_custom_target(install_project
        COMMAND +env $(CMAKE_COMMAND) --build . --target install
        COMMENT "Installing ${PROJECT_NAME}...")

# Generate an uninstall target
# @see: https://cmake.org/Wiki/CMake_FAQ#Can_I_do_.22make_uninstall.22_with_CMake.3F
configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
        IMMEDIATE @ONLY)
add_custom_target(uninstall COMMAND +env ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)

# Tests
enable_testing()
add_executable(test_point tests/catch.hpp tests/test_point.cpp)
add_test(NAME TestPoint COMMAND $<TARGET_FILE:test_point>)
add_executable(test_vector tests/catch.hpp tests/test_vector.cpp)
add_test(NAME TestVector COMMAND $<TARGET_FILE:test_vector>)
