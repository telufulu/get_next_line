NAME		=	GNLtester
CC			=	cc
CFLAGSX		=	-Wall -Werror -Wextra -fsanitize=address -g3 -I $(INC)
CFLAGS		=	-Wall -Werror -Wextra -I $(INC)
INC			=	inc/
MAIN		=	srcs/test.c
SRCS		=	srcs/utils.c ../get_next_line.c ../get_next_line_utils.c

all:	$(NAME)

$(NAME):
	echo 'BUFFER_SIZE = 1'
	echo '**********************'
	$(CC) $(CFLAGS) $(MAIN) $(SRCS) -D BUFFER_SIZE=1 -o $(NAME)
	./$(NAME)
	echo 'BUFFER_SIZE = 2'
	echo '**********************'
	$(CC) $(CFLAGS) $(MAIN) $(SRCS) -D BUFFER_SIZE=2 -o $(NAME)
	./$(NAME)
	echo 'BUFFER_SIZE = 10000'
	echo '**********************'
	$(CC) $(CFLAGS) $(MAIN) $(SRCS) -D BUFFER_SIZE=10000 -o $(NAME)
	./$(NAME)

extra:
	echo 'BUFFER_SIZE = 1'
	echo '**********************'
	$(CC) $(CFLAGSX) $(MAIN) $(SRCS) -D BUFFER_SIZE=1 -o $(NAME)
	./$(NAME)
	echo 'BUFFER_SIZE = 2'
	echo '**********************'
	$(CC) $(CFLAGSX) $(MAIN) $(SRCS) -D BUFFER_SIZE=2 -o $(NAME)
	./$(NAME)
	echo 'BUFFER_SIZE = 10000'
	echo '**********************'
	$(CC) $(CFLAGSX) $(MAIN) $(SRCS) -D BUFFER_SIZE=10000 -o $(NAME)
	./$(NAME)
	
clean:
	find . -name "*.swp" -delete
	find . -name "*.DS_Store" -delete
	find . -name "*.gch" -delete

fclean:	clean
	rm -f $(NAME)
	rm -rf $(NAME).dSYM

re:	fclean all
	
.SILENT: all $(NAME) extra clean fclean re
.PHONY: all extra clean fclean re
