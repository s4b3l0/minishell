# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sankosi <sankosi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/06 09:55:53 by sankosi           #+#    #+#              #
#    Updated: 2018/10/28 14:40:42 by sankosi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	= minishell

SRC		=	src/core/main.c \
			src/core/garbage_handler.c \
			src/core/duparray.c \
			src/core/update_shlvl.c \
			src/core/prompt_handler.c \
			src/core/read_handler.c \
			src/core/argument_handler.c \
			src/builtin/env_builtin.c \
			src/builtin/echo_builtin.c \
			src/builtin/setenv_builtin.c \
			src/builtin/unsetenv_builtin.c \
			src/builtin/cd_builtin.c \
			src/core/is_bin.c \
			src/core/tokenize.c \
			src/core/exec.c

OBJ		= $(SRC:.c=.o)

CmakeFLAGS	= -Wall -Wextra -Werror

$(NAME): $(OBJ)
	@make -C libft/
	@norminette $(SRC)
	@gcc $(CmakeFLAGS) $(OBJ) -o $(NAME) -L libft/ -lft

all: $(NAME)

clean:
	@make -C libft/ clean
	@rm -rf $(OBJ)

run:
	./$(NAME)
fclean: clean
	@make -C libft/ fclean
	@rm -rf $(NAME) $(OBJ)
re: fclean $(NAME)
