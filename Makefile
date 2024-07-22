# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/19 11:28:04 by arissane          #+#    #+#              #
#    Updated: 2024/07/21 12:05:43 by arissane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFT = ./libft/libft.a

SRCS = \
        main.c validate.c nodes.c swap.c push.c \
	rotate.c rev_rotate.c sort.c ps_utils.c \
	mock_sort.c mock_init.c

OFILES = $(SRCS:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OFILES)
	@$(MAKE) -C ./libft
	@$(CC) $(CFLAGS) $(OFILES) $(LIBFT) -o $(NAME)

$(NAME_BONUS):
	@$(MAKE) -C ./bonus

bonus: $(NAME_BONUS)

clean:
	@$(MAKE) -C ./libft clean
	@$(MAKE) -C ./bonus lclean
	@rm -f $(OFILES)

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS) ./libft/libft.a

re: fclean all

.PHONY: all clean fclean re bonus
