#include "shell.h"

/**
 * tokenize_input -  tokenize an input line into individual
 * tokens based on a specified set of delimiters
 * @input_line : the line to be tolenized
 *
 * Return: return the command array
 */
char **tokenize_input(char *input_line)
{
    char *token = NULL;
    char *tmp = NULL;
    char delimiter[] = "\t\n";
    int count = 0, i = 0;
    char **command_tokens = NULL;

    if (!input_line)
        return (NULL);
    tmp = _strdup(input_line);

    token = strtok(tmp, delimiter);
    if (token == NULL)
    {
        free(input_line), input_line = NULL;
        free(tmp), tmp = NULL;
        return (NULL);
    }
    while (token)
    {
        count++;
        token = strtok(NULL, delimiter);
    }

    free(tmp);
    tmp = NULL;
    command_tokens = malloc(sizeof(char *) * (count + 1));
    if (!command_tokens)
    {
        free(input_line);
        input_line = NULL;
        return (NULL);
    }

    token = strtok(input_line, delimiter);
    while (token)
    {
        command_tokens[i] = token;
        token = strtok(NULL, delimiter);
        i++;
    }
    free(input_line);
    input_line = NULL;
    command_tokens[i] = NULL;
    return (command_tokens);
}