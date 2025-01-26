##
## EPITECH PROJECT, 2024
## C PROJECT
## File description:
## SECURED
##

SRC		= src/hashtable.c \
	src/ht_dump.c \
	src/ht_search.c \
	src/ht_delete.c \
	src/ht_insert.c

SRC_P = src/miniprintf/miniprintf.c 		\
		src/miniprintf/my_put_nbr.c 		\
		src/miniprintf/my_putchar.c 		\
		src/miniprintf/my_putstr.c
SRC_L =	src/tools/my_strlen.c  				\
		src/tools/my_strcmp.c 				\
		src/tools/my_strdup.c

NAME	=	libhashtable.a

CFLAGS	=	-Wall -Wextra -Werror -I./include

OBJ		=	$(SRC:.c=.o)

OBJ_P = $(SRC_P:.c=.o)

OBJ_L = $(SRC_L:.c=.o)

all:	$(NAME)	$(EXEC)

$(NAME):	$(OBJ) $(OBJ_P) $(OBJ_L)
	ar rc $(NAME) $(OBJ) $(OBJ_P) $(OBJ_L)

clean:
	rm -rf $(OBJ) $(OBJ_P) $(OBJ_L)
	rm -rf $(EXEC)

fclean:	clean
	rm -rf $(NAME) $(EXEC)

re:	fclean all
