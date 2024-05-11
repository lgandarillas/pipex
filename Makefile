# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/03 15:20:42 by lgandari          #+#    #+#              #
#    Updated: 2024/05/03 21:23:33 by lgandari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = pipex

RED		=	\033[0;31m
GREEN	=	\033[0;32m
NC		=	\033[0m 

SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = inc/

SRC     = $(addprefix $(SRC_DIR), main.c execute_command.c here_doc.c)
OBJ     = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

LIBFT	= libft_v2//libft_v2.a
LIBFT_PATH	= libft_v2/

CC      = gcc
CFLAGS  = -Wall -Wextra -Werror
DFLAGS	= -fsanitize=address -g3
RM      = rm -f
INCS    = -I $(INC_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -L$(LIBFT_PATH) -lft_v2 -o $(NAME)
	@echo "$(GREEN)Compiling pipex...$(NC)"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

clean:
	@$(RM) -rf $(OBJ_DIR)
	@$(MAKE) clean -C $(LIBFT_PATH) > /dev/null
	@echo "$(RED)Cleaning pipex...$(NC)"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) -r $(OBJ_DIR)
	@$(MAKE) fclean -C $(LIBFT_PATH) > /dev/null

re: fclean all

debug: CFLAGS += $(DFLAGS)
debug: re

.PHONY: all clean fclean re