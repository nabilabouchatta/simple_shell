#include "shell.h"

/**
 * _strtok - Tokenizes a string based on given delimiters.
 * @str: The string to be tokenized.
 * @delim: The delimiters used for tokenization.
 * Return: A pointer to the next token found in the string,
 *         or NULL if no more tokens are found.
 */
char *_strtok(char *str, const char *delim)
{
    static char *next;
    char *start;
    const char *delimiter;

    if (str != NULL)
        next = str;

    if (*next == '\0')
        return (NULL);

    start = next;

    while (*next)
    {
        delimiter = delim;
        while (*delimiter)
        {
            if (*next == *delimiter)
            {
                *next = '\0';
                next++;
                return start;
            }
            delimiter++;
        }
        next++;
    }

    return start;
}

/**
 * _strdup - Duplicates a given string.
 * @str: The string to be duplicated.
 *
 * Returns: A pointer to the duplicated string.
 */
char *_strdup(const char *str)
{
    char *rtn;
    int i, length = 0;
    if (str == NULL)
        return (NULL);
    while (*str != '\0')
    {
        length++;
        str++;
    }
    str = str - length;
    rtn = malloc(sizeof(char) * (length + 1));
    if (str == NULL)
        return (NULL);
    for (i = 0; i <= length; i++)
        rtn[i] = str[i];
    return (rtn);
}

/**
 * _strcmp - Compares two strings lexicographically.
 * @str1: The first string to compare.
 * @str2: The second string to compare.
 *
 * Returns:
 * - A negative value if str1 comes before str2 in lexicographic order.
 * - A positive value if str1 comes after str2 in lexicographic order.
 * - Zero if str1 and str2 are lexicographically equal.
 */

int _strcmp(char *str1, char *str2)
{
    while (*str1 && *str2)
    {
        if (*str1 != *str2)
            return (*str1 - *str2);
        str1++;
        str2++;
    }
    if (*str1 == *str2)
        return (0);
    else
        return (*str1 < *str2 ? -1 : 1);
}

/**
 * _strlen - Computes the length of a null-terminated string.
 * @str: The input string.
 *
 * Return: The number of characters in the string (excluding the null terminator).
 */
int _strlen(char *str)
{
    int length = 0;
    while (str[length])
        length++;

    return (length);
}
/**
 * _strcpy - copies a string from source to destination
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcpy(char *dest, char *src)
{
    int i = 0;

    if (dest == src || src == 0)
        return (dest);

    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = 0;
    return (dest);
}

/**
 * _strncat - Concatenates two strings, using a specified maximum number of bytes.
 * @dest: The first string to which the second string will be concatenated.
 * @src: The second string to be concatenated to the first.
 * @n: The maximum number of bytes to be used for concatenation.
 *
 * Return: A pointer to the concatenated string.
 */
char *_strncat(char *dest, char *src, int n)
{
    int a, b;
    char *str = dest;

    a = 0;
    b = 0;

    while (dest[a] != '\0')
        a++;
    while (src[b] != '\0' && b < n)
    {
        dest[a] = src[b];
        a++;
        b++;
    }
    if (b < n)
        dest[a] = '\0';
    return (str);
}