NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address

LIBFT = libft/libft.a
SRC = stackutils.c init_stack_a.c  init_stack_b.c init_stack.c \
	parsing.c push_swap.c push.c reverse_rotate.c rotate.c sort_stacks.c sort_three.c \
	swap.c ft_errors.c

# MAIN_OBJ = $(MAIN:.c=.o)
SRC_OBJS = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT):
	make -C libft
	
$(NAME): $(LIBFT) $(SRC_OBJS)
	$(CC) $(CFLAGS) $(SRC_OBJS) $(LIBFT) -o $(NAME)

clean:
	rm -f $(SRC_OBJS) $(BONUS_OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
	