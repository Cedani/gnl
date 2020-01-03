##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC		=		get_next_line.c	\

UNIT 	=		./tests/test.c 	\

OBJ 	= $(SRC:.c=.o)


CC 		= gcc

NAME	=		unit_tests

tests_run:
	$(CC) -o $(NAME) $(SRC) $(UNIT) --coverage -lcriterion
	./unit_tests

clean:
		rm -rf *.gcda
		rm -rf *.gcno
		rm -rf ./lib/my/*.o
		rm -rf *.o

fclean: clean
		rm -f $(NAME)

re: 	fclean tests_run
