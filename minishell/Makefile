# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/18 15:12:07 by briandri          #+#    #+#              #
#    Updated: 2025/12/29 11:40:20 by briandri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = minishell
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -Iinclude -Ilibft/includes -g

SRC_DIR     = src
OBJ_DIR     = objs
LIBFT_DIR   = libft

SRC = \
	$(SRC_DIR)/main.c\
	\
	$(SRC_DIR)/core/init.c \
	\
	$(SRC_DIR)/lexer/lexer.c \
	$(SRC_DIR)/lexer/token_utils.c \
	$(SRC_DIR)/lexer/lexer_utils.c \
	$(SRC_DIR)/lexer/quotes.c \
	\
	$(SRC_DIR)/parser/parser.c \
	$(SRC_DIR)/parser/parser_utils.c \
	$(SRC_DIR)/parser/parser_cmd.c \
	$(SRC_DIR)/parser/parser_cmd_utils.c \
	$(SRC_DIR)/parser/parse_redirs.c \
	\
	$(SRC_DIR)/expander/expander.c \
	$(SRC_DIR)/expander/expand_utils.c \
	$(SRC_DIR)/expander/here_doc.c \
	\
	$(SRC_DIR)/executor/exec.c \
	$(SRC_DIR)/executor/exec_utils.c \
	$(SRC_DIR)/executor/other_exec_utils.c \
	\
	$(SRC_DIR)/builtins/builtin_cd.c \
	$(SRC_DIR)/builtins/builtin.c \
	$(SRC_DIR)/builtins/builtin_pwd.c \
	$(SRC_DIR)/builtins/builtin_echo.c \
	$(SRC_DIR)/builtins/builtin_env.c \
	$(SRC_DIR)/builtins/builtin_export.c \
	$(SRC_DIR)/builtins/builtin_exit.c \
	\
	$(SRC_DIR)/env/env_init.c \
	$(SRC_DIR)/env/env_set.c \
	$(SRC_DIR)/env/env_convert.c \
	$(SRC_DIR)/env/env_get.c \
	$(SRC_DIR)/env/env_unset.c \
	\
	$(SRC_DIR)/utils/memory_utils.c \
	$(SRC_DIR)/utils/debug_utils.c\
	$(SRC_DIR)/utils/error_utils.c\
	$(SRC_DIR)/utils/list_utils.c\
	$(SRC_DIR)/utils/str_utils.c\
	\
	$(SRC_DIR)/signals/signals.c\
	$(SRC_DIR)/signals/signals_utils.c\
	

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT = $(LIBFT_DIR)/libft.a

COLOR_BoldCyan = \033[1;36m
COLOR_Reset    = \033[0m
COLOR_Red      = \033[31m

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -lreadline -o $@
	@echo "$(COLOR_BoldCyan)Executable created: $(NAME)$(COLOR_Reset)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "$(COLOR_Red)Object files cleaned.$(COLOR_Reset)"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
	@echo "$(COLOR_Red)Executable $(NAME) cleaned.$(COLOR_Reset)"

re: fclean all

.PHONY: all clean fclean re

