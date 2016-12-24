add_library(memory_block
    memory_block.cc
    )

add_library(event_printer_frontend
    event_printer_frontend.cc
    )

add_executable(mem_anal
    main.cc
    )

add_subdirectory(test)
