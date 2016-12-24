#include "memory_block.hh"

#include "gtest/gtest.h"

const auto CLOCK_BASE = std::chrono::steady_clock::now();

const auto BUILD_STEADY_CLOCK(const std::chrono::steady_clock::duration& offset)
{
    return CLOCK_BASE + offset;
}

const std::size_t ADDRESS_START1 = 0x00;
const std::size_t ADDRESS_START2 = 0x01;
const std::size_t ADDRESS_START3 = 0x80;

const std::size_t BLOCK_SIZE1 = 0x01;
const std::size_t BLOCK_SIZE2 = 0x08;
const std::size_t BLOCK_SIZE3 = 0x10;

const auto OFFSET1(std::chrono::seconds(0));
const auto OFFSET2(std::chrono::seconds(1));
const auto OFFSET3(std::chrono::minutes(1));

const auto TIME1(BUILD_STEADY_CLOCK(OFFSET1));
const auto TIME2(BUILD_STEADY_CLOCK(OFFSET2));
const auto TIME3(BUILD_STEADY_CLOCK(OFFSET3));

class memory_block_tests: public testing::Test
{
public:
    memory_block block1;
    memory_block block2;
    memory_block block3;

    memory_block_tests() :
            block1(ADDRESS_START1, BLOCK_SIZE1, TIME1),
            block2(ADDRESS_START2, BLOCK_SIZE2, TIME2),
            block3(ADDRESS_START3, BLOCK_SIZE3, TIME3)
    {
    }

    void assert_block_range(
            const std::pair<std::size_t, std::size_t>& actual,
            const std::size_t& expected_start,
            const std::size_t& expected_end)
    {
        EXPECT_EQ(expected_start, actual.first);
        EXPECT_EQ(expected_end, actual.second);
    }
};

TEST_F(memory_block_tests, test_get_range)
{
    assert_block_range(
            block1.get_range(),
            ADDRESS_START1,
            ADDRESS_START1 + BLOCK_SIZE1);

    assert_block_range(
            block2.get_range(),
            ADDRESS_START2,
            ADDRESS_START2 + BLOCK_SIZE2);

    assert_block_range(
            block3.get_range(),
            ADDRESS_START3,
            ADDRESS_START3 + BLOCK_SIZE3);
}

TEST_F(memory_block_tests, test_time_since_allocation)
{
    auto delta(std::chrono::seconds(1));

    EXPECT_EQ(
            block1.get_time_since_allocation(BUILD_STEADY_CLOCK(OFFSET1 + delta)),
            delta);
    EXPECT_EQ(
            block2.get_time_since_allocation(BUILD_STEADY_CLOCK(OFFSET2 + delta)),
            delta);
    EXPECT_EQ(
            block3.get_time_since_allocation(BUILD_STEADY_CLOCK(OFFSET3 + delta)),
            delta);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

