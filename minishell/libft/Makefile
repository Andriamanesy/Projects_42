# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/04 19:02:28 by briandri          #+#    #+#              #
#    Updated: 2025/12/23 08:57:13 by briandri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
AR = ar
CFLAGS = -Wextra -Wall -Werror -I../include

SRC_DIR = srcs
OBJ_DIR = objs

SRC = srcs/ft_isalpha.c srcs/ft_isdigit.c srcs/ft_isalnum.c srcs/ft_isascii.c srcs/ft_isprint.c srcs/ft_strlen.c \
	srcs/ft_memset.c srcs/ft_bzero.c srcs/ft_memcpy.c srcs/ft_toupper.c srcs/ft_tolower.c srcs/ft_atoi.c srcs/ft_memmove.c \
	srcs/ft_strlcpy.c srcs/ft_strlcat.c srcs/ft_strchr.c srcs/ft_strrchr.c srcs/ft_strncmp.c srcs/ft_memchr.c \
	srcs/ft_memcmp.c srcs/ft_strnstr.c srcs/ft_strdup.c srcs/ft_calloc.c srcs/ft_substr.c srcs/ft_strjoin.c srcs/ft_strtrim.c \
	srcs/ft_split.c srcs/ft_strmapi.c srcs/ft_itoa.c srcs/ft_striteri.c srcs/ft_putchar_fd.c srcs/ft_putstr_fd.c srcs/ft_putendl_fd.c srcs/ft_putnbr_fd.c \
	srcs/ft_print_char.c srcs/ft_print_unsigned.c srcs/ft_print_decimal.c srcs/ft_formats.c srcs/ft_print_hex.c \
	srcs/ft_print_percent.c srcs/ft_print_addr.c srcs/ft_print_str.c srcs/ft_strcmp.c srcs/get_next_line.c srcs/get_next_line_utils.c

SRC_BONUS = srcs/ft_lstnew_bonus.c srcs/ft_lstadd_front_bonus.c srcs/ft_lstlast_bonus.c srcs/ft_lstsize_bonus.c srcs/ft_lstadd_back_bonus.c \
	srcs/ft_lstdelone_bonus.c srcs/ft_lstclear_bonus.c srcs/ft_lstiter_bonus.c

OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)/%.o)
OBJ_BONUS = $(SRC_BONUS:$(SRC_DIR)%.c=$(OBJ_DIR)/%.o)

COLOR_BoldCyan = \033[1;36m
COLOR_Reset = \033[0m
COLOR_Red = \033[31m

all: $(NAME)
	@echo "$(COLOR_BoldCyan)Building $(NAME)...$(COLOR_Reset)"

$(NAME): $(OBJ) $(OBJ_BONUS)
	@$(AR) -rcs $@ $^
	@echo "$(COLOR_BoldCyan)Library created: $(NAME)$(COLOR_Reset)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJ) $(OBJ_BONUS)
	@$(AR) -rcs $(NAME) $^

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
