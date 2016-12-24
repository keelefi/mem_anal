#include "event_printer_frontend.hh"

#include "gtest/gtest.h"

#include <sstream>

class event_printer_frontend_tests: public testing::Test
{
public:
    std::ostringstream output;
    event_printer_frontend event_printer;

    event_printer_frontend_tests() :
            output(),
            event_printer(output)
    {
    }
};

TEST_F(event_printer_frontend_tests, test_memory_allocation_output_message1)
{
    event_printer.system_memory_allocation(0x00, 0x00);

    ASSERT_STREQ("Memory allocated at 0 (0)", output.str().c_str());
}

TEST_F(event_printer_frontend_tests, test_memory_allocation_output_message2)
{
    event_printer.system_memory_allocation(0x00, 0x10);

    ASSERT_STREQ("Memory allocated at 0 (10)", output.str().c_str());
}

TEST_F(event_printer_frontend_tests, test_memory_allocation_output_message3)
{
    event_printer.system_memory_allocation(0x10, 0x00);

    ASSERT_STREQ("Memory allocated at 10 (0)", output.str().c_str());
}

TEST_F(event_printer_frontend_tests, test_memory_allocation_output_message4)
{
    event_printer.system_memory_allocation(0x10, 0x10);

    ASSERT_STREQ("Memory allocated at 10 (10)", output.str().c_str());
}

TEST_F(event_printer_frontend_tests, test_memory_allocation_output_message5)
{
    event_printer.system_memory_allocation(0xabc, 0xff00);

    ASSERT_STREQ("Memory allocated at abc (ff00)", output.str().c_str());
}

TEST_F(event_printer_frontend_tests, test_memory_release_output_message)
{
    event_printer.system_memory_release(0xbfd, 0x1010);

    ASSERT_STREQ("Memory released at bfd (1010)", output.str().c_str());
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
