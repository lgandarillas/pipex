# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/03 15:20:42 by lgandari          #+#    #+#              #
#    Updated: 2024/05/12 18:22:37 by lgandari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAME_BONUS = pipex_bonus

RED	= \033[0;31m
GREEN	= \033[0;32m
NC	= \033[0m 

CFLAGS = -Wall -Werror -Wextra -g3 #-fsanitize=address
CC = cc
RM = rm -f

LIBFT	= libft_v2//libft_v2.a
LIBFT_PATH	= libft_v2/ # NOT USED

SRC_DIR = src/
BONUS_DIR = src_bonus/
OBJ_DIR = obj/ # NOT USED
INC_DIR = inc/ # NOT USED

SRCS	= $(addprefix $(SRC_DIR), main.c execute_command.c)
SRCS_BONUS = $(addprefix $(BONUS_DIR), main.c execute_command.c here_doc.c)

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all : $(NAME)

bonus : $(NAME_BONUS)

$(NAME) : $(OBJS)
	@make all -sC ./libft_v2/
	@echo "$(GREEN)Compiling Libft.$(NC)"
	@$(CC) $(CFLAGS) $(OBJS) -I ../../inc/pipex.h $(LIBFT) -o $(NAME)
	@echo "$(GREEN)Pipex Compiled.$(NC)"

$(NAME_BONUS) : $(OBJS_BONUS)
	@make all -sC ./libft_v2
	@echo "$(GREEN)Compiling Libft.$(NC)"
	@$(CC) $(CFLAGS) $(OBJS_BONUS) -I ../../inc/pipex.h $(LIBFT) -o $(NAME_BONUS)
	@echo "$(GREEN)Pipex Bonus Compiled.$(NC)"

clean:
	@$(RM) $(OBJS)
	@$(RM) $(OBJS_BONUS)
	@make clean -sC libft_v2
	@echo "$(RED)All Objs Deleted.$(NC)"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)
	@$(RM) $(LIBFT)
	@echo "$(RED)Everything Deleted.$(NC)"

re: fclean all

.PHONY: all clean fclean re

### OLD ########################################################################

#OBJ     = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
#BONUS_OBJ = $(BONUS_SRC:$(BONUS_DIR)%.c=$(OBJ_DIR)%.o)
#
#CC      = gcc
#CFLAGS  = -Wall -Wextra -Werror
#DFLAGS	= -fsanitize=address -g3
#RM      = rm -f
#INCS    = -I $(INC_DIR)
#
#$(OBJ_DIR)%.o: $(SRC_DIR)%.c
#	@mkdir -p $(OBJ_DIR)
#	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@
#
#$(OBJ_DIR)%.o: $(BONUS_DIR)%.c
#	@mkdir -p $(OBJ_DIR)
#	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@
#
#$(NAME): $(OBJ)
#	@$(MAKE) -C $(LIBFT_PATH)
#	@$(CC) $(OBJ) -L$(LIBFT_PATH) -lft_v2 -o $(NAME)
#	@echo "$(GREEN)Compiling pipex...$(NC)"
#
#$(BONUS_NAME): $(BONUS_OBJ)
#	@$(MAKE) -C $(LIBFT_PATH)
#	@$(CC) $(BONUS_OBJ) -L $(LIBFT_PATH) -lft_v2 -o $(BONUS_NAME)
#	@echo "$(GREEN)Compiling pipex bonus...$(NC)"
#
#all: $(LIBFT) $(NAME)
#
#bonus: $(BONUS_OBJ) $(LIBFT)
#	@$(CC) $(BONUS_OBJ) -L$(LIBFT_PATH) -lft_v2 -o $(BONUS_NAME)
#	@echo "$(GREEN)Compiling pipex bonus...$(NC)"
#
#clean:
#	@$(RM) -rf $(OBJ_DIR)
#	@$(MAKE) clean -C $(LIBFT_PATH) > /dev/null
#	@echo "$(RED)Cleaning pipex...$(NC)"
#
#fclean: clean
#	@$(RM) $(NAME)
#	@$(RM) -r $(OBJ_DIR)
#	@$(MAKE) fclean -C $(LIBFT_PATH) > /dev/null
#
#re: fclean all
#
#debug: CFLAGS += $(DFLAGS)
#debug: re
#
#.PHONY: all clean fclean re
