add_library(memory_block
    memory_block.cc
    )

add_library(event_printer_frontend
    event_printer_frontend.cc
    )

add_executable(memory-analyzer
    main.cc
    )

target_link_libraries(memory-analyzer
    gflags
    )

add_subdirectory(test)
