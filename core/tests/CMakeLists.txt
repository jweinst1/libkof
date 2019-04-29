# cmake file for tests for core

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(test_kof_items test_kof_items.c)
target_link_libraries(test_kof_items PUBLIC kof)
add_test(test_kof_items test_kof_items)
