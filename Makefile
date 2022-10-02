# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikalakhi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/12 20:59:17 by ikalakhi          #+#    #+#              #
#    Updated: 2022/09/25 16:55:47 by ikalakhi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

PRINTF = ft_printf/libftprintf.a

SRC = so_long.c map.c libft/split.c map_chrch.c window_rendering.c\
		libft/get_next_line.c libft/get_next_line_utils.c\
		libft/substr.c libft/strdup.c errors_handling.c\
		valide_path.c map_dimension.c create_game.c 

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
