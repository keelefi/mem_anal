include_directories(..)

add_executable(memory_block_tests
    memory_block.cc
    )

target_link_libraries(memory_block_tests
    ${GTEST_BOTH_LIBRARIES}
    memory_block
    pthread
    )

add_test(memory_block_tests memory_block_tests)
