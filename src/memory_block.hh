#pragma once

#include <chrono>
#include <utility>

class memory_block
{
public:
    memory_block(
            const std::size_t& address,
            const std::size_t& size);
    memory_block(
            const std::size_t& address,
            const std::size_t& size,
            const std::chrono::steady_clock::time_point& m_allocation_time);

    std::size_t get_address() const;
    std::size_t get_size() const;
    std::pair<std::size_t, std::size_t> get_range() const;
    const std::chrono::steady_clock::time_point& get_allocation_time() const;
    std::chrono::steady_clock::duration get_time_since_allocation() const;
    std::chrono::steady_clock::duration get_time_since_allocation(
            const std::chrono::steady_clock::time_point& now) const;

private:
    std::size_t m_address;
    std::size_t m_size;
    std::chrono::steady_clock::time_point m_allocation_time;
};

