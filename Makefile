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

SRC = so_long.c so_long_utils.c map.c player_path.c external_functions/split.c\
		external_functions/get_next_line.c external_functions/get_next_line_utils.c\
		external_functions/substr.c external_functions/strdup.c errors_handling.c\
		map_chrch.c valide_path.c collectibles_path.c map_dimension.c\
		window_rendering.c

OBJS = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror 
#-fsanitize=address
MLX_FALGS = -lmlx -framework OpenGL -framework AppKit

all : $(NAME)
$(NAME): $(OBJS)
	cc $(CFLAGS) $(MLX_FALGS) $(SRC)  -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all