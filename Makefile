# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikalakhi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/12 20:59:17 by ikalakhi          #+#    #+#              #
#    Updated: 2021/12/22 14:51:29 by ikalakhi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

PRINTF = ft_printf/libftprintf.a

SRC = so_long.c so_long_utils.c map.c external_functions/split.c\
		external_functions/get_next_line.c external_functions/get_next_line_utils.c\
		external_functions/substr.c external_functions/strdup.c errors_handling.c\
		map_chrch.c valide_path.c map_dimension.c create_game.c\
		window_rendering.c 

OBJS = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror 
#-fsanitize=address
MLX_FALGS = -lmlx -framework OpenGL -framework AppKit

all : $(NAME)
$(NAME): $(OBJS)
	cd ft_printf && make && cd ..
	cc $(CFLAGS) $(MLX_FALGS) $(PRINTF) $(SRC)  -o $(NAME)

clean:
	cd ft_printf && make clean && cd ..
	rm -f $(OBJS)

fclean: clean
	cd ft_printf && make fclean && cd ..
	rm -f $(NAME)

re: fclean all