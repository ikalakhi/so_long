# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikalakhi <ikalakhi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/24 11:54:44 by ikalakhi          #+#    #+#              #
#    Updated: 2022/08/24 11:54:45 by ikalakhi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = so_long.c so_long_utils.c map.c  map_lenth.c external_functions/split.c\
		external_functions/get_next_line.c external_functions/get_next_line_utils.c\
		external_functions/substr.c external_functions/strdup.c errors_handling.c\
		map_chrch.c
		

OBJS = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror 
#-fsanitize=address
all : $(NAME)
$(NAME): $(OBJS)
	cc $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all