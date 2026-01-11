# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: briandri <briandri@student.42antananarivo. +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/17 13:43:05 by briandri          #+#    #+#              #
#    Updated: 2026/01/11 16:24:56 by briandri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = philo
CC          = cc
CFLAGS      = -Werror -Wall -Wextra -pthread 
#-fsanitize=thread -g3

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

OBJS        = $(addprefix $(OBJ_PATH), $(SRC:.c=.o))

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -I $(INC_PATH) -c $< -o $@

clean:
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean test valgrind
