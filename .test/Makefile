NAME	=	GNLtester
CC		=	cc
#CFLAGS	=	-Wall -Werror -Wextra -fsanitize=address -g3 -I $(INC)
CFLAGS	=	-Wall -Werror -Wextra -I $(INC)
INC		=	test.h
MAIN	=	test.c
SRCS	=	srcs/utils.c ../get_next_line.c ../get_next_line_utils.c

all:	$(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(MAIN) $(SRCS) -o $(NAME)

clean:
	find . -name "*.swp" -delete
	find . -name "*.DS_Store" -delete
	find . -name "*.gch" -delete

fclean:	clean
	rm -f $(NAME)
	rm -rf $(NAME).dSYM

re:	fclean all
	
.SILENT: all $(NAME) clean fclean re
.PHONY: all clean fclean re
