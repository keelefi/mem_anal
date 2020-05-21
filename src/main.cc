#include <iostream>
#include <system_error>
#include <vector>

#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <assert.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>

void print_usage(const char *argv0)
{
    std::cout
            << "usage: "
            << std::string(argv0)
            << " <command>"
            << std::endl;
}

void tracer_func(pid_t child_pid)
{
    int status;
    if (waitpid(child_pid, &status, 0) == -1)
    {
        throw std::system_error(errno, std::system_category());
    }
    assert(WIFSTOPPED(status));

    std::cout << "child " << child_pid << " exited." << std::endl;
}

void tracee_func(int argc, char **argv)
{
    // we need to remove argv[0] and end the array with a NULL element
    std::vector<char *> child_argv;
    for (int i = 1; i < argc; ++i)
    {
        child_argv.push_back(argv[i]);
    }

    if (ptrace(PTRACE_TRACEME) == -1)
    {
        throw std::system_error(errno, std::system_category());
    }

    if (kill(getpid(), SIGSTOP) == -1)
    {
        throw std::system_error(errno, std::system_category());
    }

    // execvp() returns only if an error occured
    execvp(child_argv[0], child_argv.data());
    throw std::system_error(errno, std::system_category());
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
        tracee_func(argc, argv);
    }
    else
    {
        tracer_func(child_pid);
    }

    return 0;
}
