/*
** EPITECH PROJECT, 2019
** get_next_line
** File description:
** get as many line as we call the functions until buffer is null
*/

#include "get_next_line.h"

char *my_strcat(char *str1, char *str2, int n)
{
    int i = 0;
    int j = 0;
    char *result;

    if (str1)
        for (; str1[i]; i += 1);
    result = malloc(sizeof(*result) * (i + n) + 1);
    if (str1) {
        for (; j < i; j += 1)
            result[j] = str1[j];
    }
    for (int m = 0; m < n; m += 1) {
        result[j] = str2[m];
        j += 1;
    }
    result[j] = '\0';
    return (result);
}

char *buffer_to_give(int *ind, char *cont)
{
    int ok = 0;
    char *buffer = malloc(sizeof(*buffer));

    for (; cont[*ind] && ok != 2; *ind += 1) {
        if (cont[*ind] == '\n' && ok != 1) {
            ok = 2;
        }
        if (cont[*ind] == '\n' && ok == 1)
            ok = 2;
        if (cont[*ind] != '\n') {
            buffer = my_strcat(buffer, &cont[*ind], 1);
            ok = 1;
        }
    }
    return (buffer);
}

char *get_next_line(int fd)
{
    static int init = 0;
    char *tmp = NULL;
    static char *container = NULL;
    static int index = 0;
    int k = -2;

    if (fd == -1 || (init == 1 && !container[index]) || READ_SIZE <= 0)
        return (NULL);
    tmp = malloc(sizeof(*tmp) * READ_SIZE + 1);
    if (init == 0) {
        k = read(fd, tmp, READ_SIZE);
        for (; k != 0; k = read(fd, tmp, READ_SIZE))
            container = my_strcat(container, tmp, k);
        init += 1;
    }
    if (!container)
        return NULL;
    tmp = buffer_to_give(&index, container);
    return (tmp);
}