##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## matchstick
##

SRC	=	main.c	\
		src/my_putchar.c	\
		src/my_putstr.c	\
		src/my_getnbr.c	\
		src/tools_matchstick.c	\
		src/my_put_nbr.c	\
		src/check_matchstick.c	\
		src/game_move.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	matchstick

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(SRC)

clean:
		rm  -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
