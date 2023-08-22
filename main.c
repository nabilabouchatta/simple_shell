#include "shell.h"

/**
 * main - the main function
 * @argc:  the number of command-line arguments
 * @av: An array of strings containing the command-line arguments
 *
 * Return: Always returns 0
 */
int main(int argc, char **argv)
{
    char **command_tokens = NULL;
    char *input_line = NULL;
    int stat = 0;
    (void)argc;

    while (1)
    {
        input_line = get_line();
        if (input_line == NULL)
        {
            if (isatty(STDIN_FILENO))
                write(STDOUT_FILENO, "\n", 1);
            return (stat);
        }

        command_tokens = tokenize_input(input_line);
        if (!command_tokens)
            continue;

        stat = execute_cmd(command_tokens, argv);
    }
}