# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chunpark <chunpark@student.42gyeongsan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/17 19:09:54 by chunpark          #+#    #+#              #
#    Updated: 2024/05/17 20:27:22 by chunpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
DIR = ./man
SRC = push_swap.c index_node.c sort_arr.c sort_stack.c sort_stack_3_5.c
SRCS = $(addprefix $(DIR)/, $(SRC))
OBJS = $(SRCS:.c=.o)

BNS_NAME = checker
BNS_DIR = ./bonus
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

LIBFT = ./utils/utils/libft/libft.a
GNL = ./utils/utils/get_next_line/get_next_line.a

PUSH_SWAP_OBJS = $(OBJS) $(UTILS_OBJS) $(FUNC_OBJS)
CHECKER_OBJS = $(BNS_OBJS) $(UTILS_OBJS) $(FUNC_OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: spinner $(NAME)

$(NAME): $(PUSH_SWAP_OBJS)
	@make re -C ./utils/utils/libft > /dev/null
	@$(CC) $(CFLAGS) $(PUSH_SWAP_OBJS) $(LIBFT) -o $(NAME)
bonus: $(BNS_NAME)

$(BNS_NAME): $(CHECKER_OBJS)
	@make re -C ./utils/utils/libft > /dev/null
	@make re -C ./utils/utils/get_next_line > /dev/null
	@$(CC) $(CFLAGS) $(CHECKER_OBJS) $(LIBFT) $(GNL) -o $(BNS_NAME)

clean:
	@make clean -C ./utils/utils/libft > /dev/null
	@make clean -C ./utils/utils/get_next_line > /dev/null
	@rm -f $(PUSH_SWAP_OBJS) $(CHECKER_OBJS)

fclean: clean
	@make fclean -C ./utils/utils/libft > /dev/null
	@make fclean -C ./utils/utils/get_next_line > /dev/null
	@rm -f $(NAME) $(BNS_NAME)

re: fclean all

re_bonus: fclean bonus

spinner :
	@bash a.sh
