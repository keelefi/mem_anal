#pragma once

#include <cstddef>

class frontend
{
public:
    virtual ~frontend() = default;

    virtual void system_memory_allocation(
            const std::size_t& address,
            const std::size_t& length) = 0;
    virtual void system_memory_release(
            const std::size_t& address,
            const std::size_t& length) = 0;
};

