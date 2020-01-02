/*
** EPITECH PROJECT, 2019
** get_next_line.h
** File description:
** useful function
*/

#ifndef READ_SIZE
#define READ_SIZE (5)
#endif // !READ_SIZE

#ifndef GET_NEXT_LINE
#define GET_NEXT_LINE
#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

char *my_strcat(char *str1, char *str2, int n);
char *buffer_to_give(int *index, char *container);
char *get_next_line(int fd);
void reset_static(char **container, int *index, int fd2, int *init);
#endif /* !GET_NEXT_LINE */
