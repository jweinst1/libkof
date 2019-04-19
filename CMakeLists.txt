cmake_minimum_required(VERSION 3.5)

project(libkof)

# Sets the prefix for installations
set(CMAKE_INSTALL_PREFIX /usr/local)

add_subdirectory(build)
message("Building with version: ${LIBKOF_NAMED_VERSION}")

option(KOF_WITH_TESTING "Builds libkof with testing." ON)

if(KOF_WITH_TESTING)
    enable_testing()
endif()
