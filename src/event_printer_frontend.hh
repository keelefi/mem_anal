#pragma once

#include "frontend.hh"

#include <ostream>
#include <string>

class event_printer_frontend: public frontend
{
public:
    event_printer_frontend();
    event_printer_frontend(std::ostream& outstream);
    virtual ~event_printer_frontend() = default;

    virtual void system_memory_allocation(
            const std::size_t& address,
            const std::size_t& length) override;
    virtual void system_memory_release(
            const std::size_t& address,
            const std::size_t& length) override;

private:
    void print_event(
            const std::string& event,
            const std::size_t& address,
            const std::size_t& length);

    std::ostream m_outstream;
};

