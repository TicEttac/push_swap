
NAME = push_swap

SRCS =		main.c			\
		a_orders.c			\
		b_orders.c			\
		both_orders.c		\
		parsing.c			\
		parsing_check.c		\
		parsing_tools.c		\
		small_sort.c		\
		sort_utils.c		\

OBJS = $(addprefix srcs/, $(SRCS))

LIB =	lib/libft.a	\

CFLAGS = -g3 -fsanitize=address -Wall -Werror -Wextra -I inc -o

CC = gcc

all:	$(NAME)

$(NAME): $(OBJS)
	@make -C ./libft all
	@mkdir -p lib
	@cp libft/libft.h inc/libft.h
	@mv libft/libft.a lib/
	@${CC} ${CFLAGS} ${NAME} ${OBJS} ${LIB}
	@echo "compiling $@"

clean:
	@rm -rf lib/
	@rm -rf inc/libft.h
	@make -C libft clean

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all

git: fclean
	@git add .
	@git commit -m "$@"
	@git push
	@git status

.SILENT: all clean fclean re
.PHONY: all clean fclean re
