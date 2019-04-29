# Cmake file for the core dir

include_directories(${PROJECT_SOURCE_DIR}/include)

set(KOF_CORE_SOURCES
   kof_items.c
)

add_library(kof STATIC "${KOF_CORE_SOURCES}")
add_library(kofs SHARED "${KOF_CORE_SOURCES}")

add_subdirectory(tests)
