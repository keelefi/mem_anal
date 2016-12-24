#include "event_printer_frontend.hh"

#include <ios>
#include <iostream>

event_printer_frontend::event_printer_frontend() :
        m_outstream(std::cout.rdbuf())
{
}

event_printer_frontend::event_printer_frontend(std::ostream& outstream) :
        m_outstream(outstream.rdbuf())
{
}

void event_printer_frontend::system_memory_allocation(
        const std::size_t& address,
        const std::size_t& length)
{
    print_event("Memory allocated", address, length);
}

void event_printer_frontend::system_memory_release(
        const std::size_t& address,
        const std::size_t& length)
{
    print_event("Memory released", address, length);
}

void event_printer_frontend::print_event(
        const std::string& event,
        const std::size_t& address,
        const std::size_t& length)
{
    m_outstream
            << event
            << " at "
            << std::hex << address
            << " ("
            << std::hex << length
            << ")";
}

