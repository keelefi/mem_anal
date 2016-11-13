#include "memory_block.hh"

memory_block::memory_block(
        const std::size_t& address,
        const std::size_t& size) :
            m_address(address),
            m_size(size),
            m_allocation_time(std::chrono::steady_clock::now())
{
}

memory_block::memory_block(
        const std::size_t& address,
        const std::size_t& size,
        const std::chrono::steady_clock::time_point& allocation_time) :
            m_address(address),
            m_size(size),
            m_allocation_time(allocation_time)
{
}

std::size_t memory_block::get_address() const
{
    return m_address;
}

std::size_t memory_block::get_size() const
{
    return m_size;
}

std::pair<std::size_t, std::size_t> memory_block::get_range() const
{
    return std::make_pair(m_address, m_address + m_size);
}

const std::chrono::steady_clock::time_point&
memory_block::get_allocation_time() const
{
    return m_allocation_time;
}

std::chrono::steady_clock::duration memory_block::get_time_since_allocation() const
{
    return get_time_since_allocation(std::chrono::steady_clock::now());
}

std::chrono::steady_clock::duration memory_block::get_time_since_allocation(
        const std::chrono::steady_clock::time_point& now) const
{
    return now - m_allocation_time;
}

