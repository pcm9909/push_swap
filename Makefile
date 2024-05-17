CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
DIR = ./push_swap
SRC = index_node.c sort_arr.c sort_stack.c sort_stack_3_5.c push_swap.c
SRCS = $(addprefix $(DIR)/, $(SRC))
OBJS = $(SRCS:.c=.o)

BNS_NAME = checker
BNS_DIR = ./checker
BNS_SRC = process_input.c checker.c
BNS_SRCS = $(addprefix $(BNS_DIR)/, $(BNS_SRC))
BNS_OBJS = $(BNS_SRCS:.c=.o)

UTILS_DIR = ./utils
UTILS_SRC = exit_msg.c handle_node.c handle_stack.c split_args.c validate_args.c
UTILS_SRCS = $(addprefix $(UTILS_DIR)/, $(UTILS_SRC))
UTILS_OBJS = $(UTILS_SRCS:.c=.o)

FUNC_DIR = ./utils/func
FUNC_SRC = push.c reverse_rotate.c rotate.c swap.c
FUNC_SRCS = $(addprefix $(FUNC_DIR)/, $(FUNC_SRC))
FUNC_OBJS = $(FUNC_SRCS:.c=.o)


%.o: %.c
			@$(CC) $(CFLAGS) -c $< -o $@


all : $(NAME)

$(NAME): $(OBJS)
	@make re -C ./utils/utils/libft
	@$(CC) $(CFLAGS) $(OBJS) $(UTILS_OBJS) $(FUNC_OBJS) ./utils/utils/libft/libft.a

bonus : $(BNS_NAME)

$(BNS_NAME):
	@make re -C ./utils/utils/libft
	@make re -C ./utils/utils/get_next_line
	@$(CC) $(CFLAGS) $(BNS_OBJS) $(UTILS_OBJS) $(FUNC_OBJS) ./utils/utils/libft/libft.a ./utils/utils/get_next_line/get_next_line.a

clean:
	@make clean -C ./utils/utils/libft
	@make clean -C ./utils/utils/get_next_line
	@rm -f $(OBJS) $(BNS_OBJS) $(UTILS_OBJS)

fclean: clean
	@make clean -C ./utils/utils/libft
	@make clean -C ./utils/utils/get_next_line
	@rm -f $(NAME) $(BNS_NAME)

re: fclean all

re_bonus: fclean bonus


