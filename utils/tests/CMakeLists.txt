# Cmake file for the utils tests

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(test_kofmem test_kofmem.c)
# Turns on debugger mode.
target_compile_definitions(test_kofmem PRIVATE -DKOF_MEMORY_DEBUG_MODE)
add_test(test_kofmem test_kofmem)

add_executable(test_kofio test_kofio.c)
target_link_libraries(test_kofio kofutils)
add_test(test_kofio test_kofio)
