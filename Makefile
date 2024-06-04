# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/03 15:20:42 by lgandari          #+#    #+#              #
#    Updated: 2024/06/04 10:02:11 by lgandari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAME_BONUS = pipex_bonus

RED	= \033[0;31m
GREEN	= \033[0;32m
NC	= \033[0m 

CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address
CC = cc
RM = rm -f

LIBFT	= libft_v2//libft_v2.a
LIBFT_PATH	= libft_v2/

SRC_DIR = src/
BONUS_DIR = src_bonus/

SRCS	= $(addprefix $(SRC_DIR), main.c execute_command.c)
SRCS_BONUS = $(addprefix $(BONUS_DIR), main.c execute_command.c here_doc.c)

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all : $(NAME)

bonus : $(NAME_BONUS)

$(NAME) : $(OBJS)
	@make all -sC $(LIBFT_PATH)
	@$(CC) $(CFLAGS) $(OBJS) -I ../../inc/pipex.h $(LIBFT) -o $(NAME)
	@echo "$(GREEN)Compiling pipex...$(NC)"

$(NAME_BONUS) : $(OBJS_BONUS)
	@make all -sC $(LIBFT_PATH)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) -I ../../inc/pipex.h $(LIBFT) -o $(NAME_BONUS)
	@echo "$(GREEN)Compiling pipex bonus...$(NC)"

clean:
	@$(RM) $(OBJS)
	@$(RM) $(OBJS_BONUS)
	@make clean -sC $(LIBFT_PATH)
	@echo "$(RED)All Objs Deleted.$(NC)"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)
	@$(RM) $(LIBFT)
	@echo "$(RED)Everything Deleted.$(NC)"

re: fclean all

.PHONY: all clean fclean re
.SILENT:
