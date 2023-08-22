#include "shell.h"

int execute_cmd(char **command_tokens, char **argv)
{
    pid_t pid;
    int stat;

    pid = fork();
    if (pid == 0)
    {
        if (execve(command_tokens[0], command_tokens, environ) == -1)
        {
            perror(argv[0]);
            free_array(command_tokens);
            exit(127);
        }
    }
    else
    {
        waitpid(pid, &stat, 0);
        free_array(command_tokens);
    }
    return (WEXITSTATUS(stat));
}