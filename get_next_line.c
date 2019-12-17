/*
** EPITECH PROJECT, 2019
** get_next_line
** File description:
** get_next_line
*/

#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char *tmp = NULL;
    static int i = 0;
    char *buffer = get_without_n(tmp, i);
    int k = 0;

    for (i = 0; tmp && tmp[i]; i += 1);
    tmp = malloc(sizeof(*tmp) * READ_SIZE + 1);
    k = read(fd, tmp, READ_SIZE);
    tmp[READ_SIZE] = '\0';
    i = k;
    if (k == -1 || k == 0)
        return (NULL);
    for (; check_n(tmp, &buffer, fd, &i) == 0 && k == READ_SIZE; k += 0) {
        k = read(fd, tmp, READ_SIZE);
        tmp[READ_SIZE] = '\0';
        i = k;
    }
    return (buffer);
}

char *my_strncat(char *str, char *src, int n)
{
    char *dest = NULL;
    int k = 0;
    int i = 0;
    if (str == NULL)
        dest = malloc(sizeof(*dest) * n + 1);
    else {
        for (; str[k] != '\0'; k += 1);
        dest = malloc(sizeof(*dest) * (k) + 1);
        dest = str;
    }
    for (; i < n; i += 1)
        dest[i + k] = src[i];
    dest[i + k] = '\0';
    return (dest);
}

int check_n(char *src, char **dest, int fd, int *n)
{
    int i = 0;

    for (; src[i] && src[i] != '\n' && i < *n; i += 1) {
    }
    dest[0] = my_strncat(dest[0], src, i);
    if (i < READ_SIZE) {
        *n = i;
        return (1);
    } else {
        return (0);
    }
}

char *get_without_n(char *tmp, int ind)
{
    int i = 0;
    int k = 0;

    if (tmp == NULL)
        return (NULL);
    char *dest = malloc(sizeof(*dest) * (1 + READ_SIZE - ind));
    for (i = ind; i < READ_SIZE; i += 1) {
        if (tmp[i] != '\n') {
            dest[k] = tmp[i];
            k += 1;
        }
    }
    dest[k] = '\0';
    return (dest);
}