#include <iostream>

void print_usage(const char *argv0)
{
    std::cout
            << "usage: "
            << std::string(argv0)
            << " <command>"
            << std::endl;
}

int main(int argc, char **argv)
{
    print_usage(argv[0]);

    return 0;
}
