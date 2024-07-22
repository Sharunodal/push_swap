# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 15:11:22 by arissane          #+#    #+#              #
#    Updated: 2024/07/21 11:43:24 by arissane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFT = ./../libft/libft.a

SRCS = \
	     main_bonus.c check_output_bonus.c \
	     validate_bonus.c nodes_bonus.c \
	     ps_utils_bonus.c actions_bonus.c

OFILES = $(SRCS:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OFILES)
	@$(MAKE) -C ./../libft
	@$(CC) $(CFLAGS) $(OFILES) $(LIBFT) -o $(NAME)
	@mv $(NAME) ./../

clean:
	@$(MAKE) -C ./../libft clean
	@rm -f $(OFILES)

lclean:
	@rm -f $(OFILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

