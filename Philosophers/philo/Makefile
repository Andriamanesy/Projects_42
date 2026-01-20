# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/17 13:43:05 by briandri          #+#    #+#              #
#    Updated: 2026/01/18 03:05:59 by briandri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = philo
CC          = cc

CFLAGS      = -Werror -Wall -Wextra -pthread

SRC_PATH    = srcs/
OBJ_PATH    = objs/
INC_PATH    = includes/

SRC         = main.c \
              parsing.c \
              output.c \
              init.c \
              time.c \
              philosopher.c \
              simulation.c \
              actions.c \
              monitor.c \
              utils.c

OBJS        = $(SRC:%.c=$(OBJ_PATH)%.o)

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -I $(INC_PATH) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "Philo ready!"

clean:
	@rm -rf $(OBJ_PATH)
	@echo "Cleaning objects..."

fclean: clean
	@rm -f $(NAME)
	@echo "Cleaning binary..."

re: fclean all

.PHONY: all re clean fclean