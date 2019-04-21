# Cmake file for the utils library

include_directories(${PROJECT_SOURCE_DIR}/include)

set(KOF_UTILS_SOURCES
   kof-io.c
)

add_library(kofutils STATIC "${KOF_UTILS_SOURCES}")

add_subdirectory(tests)
