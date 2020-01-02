/*
** EPITECH PROJECT, 2019
** test
** File description:
** criterion test
*/

#include "../get_next_line.h"


#include <criterion/criterion.h>

Test(get_next_line, should_handle_wrong_file) {
    int fd = open("wrong", O_RDONLY);
    cr_assert_null(get_next_line(fd));
    close(fd);
}

Test(get_next_line, should_handle_empty_file) {
    int fd = open("./tests/test_empty", O_RDONLY);
    char *buffer = get_next_line(fd);
    cr_assert_null(buffer);
    close(fd);
}

Test(get_next_line, should_return_first_line) {
    int fd = open("./tests/test1", O_RDONLY);
    char *buffer = get_next_line(fd);
    cr_assert_not_null(buffer);
    cr_assert_str_eq(buffer, "blablablabla");
    free(buffer);
    close (fd);
}

Test(get_next_line, should_handle_two_line) {
    int fd = open("./tests/test1", O_RDONLY);
    char *buffer = get_next_line(fd);
    cr_assert_not_null(buffer);
    cr_assert_str_eq(buffer, "blablablabla");
    free(buffer);

    buffer = get_next_line(fd);
    cr_assert_not_null(buffer);
    cr_assert_str_eq(buffer, "bleble");
    free(buffer);
    close(fd);
}

Test(get_next_line, should_reach_end_file) {
    int fd = open("./tests/test1", O_RDONLY);
    char *buffer = get_next_line(fd);
    cr_assert_not_null(buffer);
    cr_assert_str_eq(buffer, "blablablabla");
    free(buffer);

    buffer = get_next_line(fd);
    cr_assert_not_null(buffer);
    cr_assert_str_eq(buffer, "bleble");
    free(buffer);

    buffer = get_next_line(fd);
    cr_assert_null(buffer);
    close(fd);
}

Test(get_next_line, should_print_n_between_line) {
    int fd = open("./tests/test2", O_RDONLY);
    char *buffer = get_next_line(fd);
    cr_assert_not_null(buffer);
    cr_assert_str_eq(buffer, "Hello");
    free(buffer);

    buffer = get_next_line(fd);
    cr_assert_not_null(buffer);
    cr_assert_str_eq(buffer, "\n");

    buffer = get_next_line(fd);
    cr_assert_not_null(buffer);
    cr_assert_str_eq(buffer, "How");
    free(buffer);
    close(fd);
}

Test(my_strcat, should_handle_first_null) {
    char *buffer = NULL;
    buffer = my_strcat(buffer, "Hello", 5);

    cr_assert_str_eq(buffer, "Hello");
}