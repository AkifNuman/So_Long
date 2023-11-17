NAME	=	so_long
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
LFLAGS	=	-Lminilibx -lmlx -framework OpenGL -framework AppKit
SOURCES	=	$(shell find *.c)

all		:	$(NAME)

$(NAME)	:	mdir
	$(CC) $(CFLAGS) $(LFLAGS) $(SOURCES) -o $(NAME)

mdir	:
	make -C minilibx

clean	:
	make -C minilibx	clean

fclean	:
	make -C minilibx	clean

	rm   -f $(NAME)

re		:	fclean	all

.PHONY	:	all $(NAME) mdir clean fclean re