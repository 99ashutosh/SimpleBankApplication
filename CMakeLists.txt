project(bank_application C CXX)

# Set the minimum version of cmake required to build this project
cmake_minimum_required(VERSION 3.10)

# Use the package PkgConfig to detect GTK+ headers/library files
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK REQUIRED gtk+-3.0)


add_executable(bank_application src/main.c src/dashboard.c src/greet_main.c src/bank_management.c)
target_link_libraries(bank_application PRIVATE ${GTKMM_LIBRARIES})


# Add other flags to the compiler
target_compile_definitions(bank_application PRIVATE ${GTKMM_CFLAGS_OTHER})


# Setup CMake to use GTK+, tell the compiler where to look for headers
# and to the linker where to look for libraries
target_include_directories(bank_application PRIVATE ${GTKMM_INCLUDE_DIRS})
target_link_directories(bank_application PRIVATE ${GTKMM_LIBRARY_DIRS})