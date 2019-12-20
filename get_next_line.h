/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** useful functions
*/
#ifndef READ_SIZE
#define READ_SIZE  2
#endif
#ifndef MY
#define MY
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char *get_next_line(int fd);
char *my_strncat(char *str, char *src, int n);
int check_n(char *src, char **dest, int fd, int *n);
char *get_without_n(char *tmp, int ind);
#endif /* !MY */
