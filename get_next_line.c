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
    char *result = NULL;

    for (; str1 && str1[i]; i += 1);
    result = malloc(sizeof(*result) * (i + n) + 1);
    for (int k = 0; str1 && k < i; k += 1)
        result[k] = str1[k];
    for (int k = 0; str2 && k < n; k += 1)
        result[k + i] = str2[k];
    return (result);
}

char *buffer_to_give(int *ind, char *cont)
{
    int nb_n = 0;
    int ok = 0;
    char *buffer = malloc(sizeof(*buffer) * 1);

    if (!cont)
        return NULL;
    for (; cont[*ind] && nb_n != 2 && ok != 2; *ind += 1) {
        if (cont[*ind] == '\n' && ok != 1) {
            buffer[0] = '\n';
            nb_n = 2;
        }
        else if (cont[*ind] == '\n' && ok == 1)
            ok = 2;
        else {
            buffer = my_strcat(buffer, &cont[*ind], 1);
            ok = 1;
        }
    }
    return (buffer);
}

void reset_static(char **conta, int *ind, int fd2, int *ini) {
    static int change_fd = 0;
    if (change_fd != fd2) {
        free(conta[0]);
        *ind = 0;
        *ini = 0;
    }
    change_fd = fd2;
}

char *get_next_line(int fd)
{
    static int init = 0;
    char *tmp = NULL;
    static char *container = NULL;
    static int index = 0;
    int k = -2;

    reset_static(&container, &index, fd, &init);
    if (fd == -1 || (init == 1 && !container[index]) || READ_SIZE <= 0)
        return (NULL);
    tmp = malloc(sizeof(*tmp) * READ_SIZE + 1);
    if (init == 0) {
        k = read(fd, tmp, READ_SIZE);
        for (; k != 0; k = read(fd, tmp, READ_SIZE))
            if (k != 0)
                container = my_strcat(container, tmp, k);
        init += 1;
    }
    tmp = buffer_to_give(&index, container);
    return (tmp);
}