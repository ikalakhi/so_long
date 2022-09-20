/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalakhi <ikalakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:55:09 by ikalakhi          #+#    #+#             */
/*   Updated: 2022/08/24 11:56:56 by ikalakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int escape(t_comp *mlx)
{
	mlx_destroy_window(mlx->init, mlx->win);
	write(1, "You gave up :(\n Is the game to hard for you?\n", 44);
	exit(EXIT_SUCCESS);
}

void    creat_game(t_comp *mlx, t_dimo *dimo, char **map)
{
    dimo = player_location(map, dimo);
    printf("y == %d, x == %d\n", mlx->dimo->y, mlx->dimo->x);
    mlx->map = copy_map(map);
    mlx_hook(mlx->win, 17, 0, escape, mlx);
    mlx_key_hook(mlx->win, key_hook, mlx);
}

int main (int ac, char **av)
{
    char    **map;
    t_dimo  *dimo;
    t_comp  *mlx;

    if (ac != 2)
        error("Error\nUsage: './so_long mappath/mapname.ber'\n");
    map = NULL;
    dimo = malloc(sizeof(t_dimo) * 1);
    mlx =  malloc(sizeof(t_comp) * 1);
    dimo = map_dimension(av[1], dimo);
    map = read_map(av[1], dimo);
    mlx = map_errors(av[1], map, dimo, mlx);
    check_path(map, dimo);
    creat_map(map, mlx, dimo);
    creat_game(mlx, dimo, map);
    mlx_loop(mlx->init);
    return (0);
}