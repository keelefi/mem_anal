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

add_executable(event_printer_frontend_tests
    event_printer_frontend.cc
    )

target_link_libraries(event_printer_frontend_tests
    ${GTEST_BOTH_LIBRARIES}
    event_printer_frontend
    pthread
    )

add_test(event_printer_frontend_tests event_printer_frontend_tests)
