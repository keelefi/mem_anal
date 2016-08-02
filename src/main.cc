#include <iostream>
#include <system_error>

#include <errno.h>
#include <unistd.h>

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
    if (argc < 2)
    {
        print_usage(argv[0]);
        return 1;
    }

    pid_t child_pid = fork();

    if (child_pid < 0)
    {
        throw std::system_error(errno, std::system_category());
    }
    else if (child_pid == 0)
    {
        std::cout << "hello from child" << std::endl;
    }
    else
    {
        std::cout << "hello from parent" << std::endl;
    }

    return 0;
}
