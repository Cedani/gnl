/*
** EPITECH PROJECT, 2019
** get_next_line
** File description:
** get as many line as we call the functions untill buffer is null
*/

#include "get_next_line.h"

char *my_strcat(char *str1, char *str2, int n)
{
    int i = 0;
    int j = 0;
    char *result;

    for (; str1 && str1[i]; i += 1);
    result = malloc(sizeof(*result) * (i + n) + 1);
    for (int k = 0; str1 && k < i; k += 1)
        result[k] = str1[k];
    for (int k = 0; str2 && k < n; k += 1)
        result[k + i] = str2[k];
    return (result);
}

char *buffer_to_give(int *index, char *container)
{
    int nb_n = 0;
    int ok = 0;
    char *buffer = malloc(sizeof(*buffer) * 1);

    if (!container)
        return NULL;
    for (; container[*index] && nb_n != 2 && ok != 2; *index += 1) {
        if (container[*index] == '\n' && ok != 1) {
            buffer[0] = '\n';
            nb_n = 2;
        }
        else if (container[*index] == '\n' && ok == 1)
            ok = 2;
        else {
            buffer = my_strcat(buffer, &container[*index], 1);
            ok = 1;
        }
    }
    return (buffer);
}

void reset_static(char **container, int *index, int fd2, int *init) {
    static int change_fd = 0;
    if (change_fd != fd2) {
        free(container[0]);
        *index = 0;
        *init = 0;
    }
    change_fd = fd2;
}

char *get_next_line(int fd)
{
    static int init = 0;
    char *tmp = malloc(sizeof(*tmp) * READ_SIZE + 1);
    static char *container;
    static int index = 0;
    int k = read(fd, tmp, READ_SIZE);

    reset_static(&container, &index, fd, &init);
    if (fd == -1 || (init == 1 && !container[index]))
        return (NULL);
    if (init == 0) {
        for (; k != 0; k += 0) {
            if (k != 0)
                container = my_strcat(container, tmp, k);
            k = read(fd, tmp, READ_SIZE);
        }
        init += 1;
    }
    tmp = buffer_to_give(&index, container);
    return (tmp);
}