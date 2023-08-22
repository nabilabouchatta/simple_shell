#include "shell.h"

/**
 * get_line -  reading a line of input from the user
 *
 * Return: return -1 in case of error or end of file
 *         return line_input in case of success
 */
char *get_line(void)
{
    char *line_input = NULL;
    size_t length = 0;
    ssize_t nread;

    if (isatty(STDIN_FILENO))
        write(STDOUT_FILENO, "$ ", 2);
    nread = getline(&line_input, &length, stdin);
    if (nread == -1)
    {
        free(line_input);
        return (NULL);
    }

    return (line_input);
}