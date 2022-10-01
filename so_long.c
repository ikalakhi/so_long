/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalakhi <ikalakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:55:09 by ikalakhi          #+#    #+#             */
/*   Updated: 2022/09/23 14:46:05 by ikalakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	creat_game(t_comp *mlx, t_dimo *dimo, char **map)
{
	mlx->dimo = dimo;
	mlx->map = copy_map(map);
	mlx->conter_c = 0;
	mlx_hook(mlx->win, 17, 0, escape, mlx);
	mlx_key_hook(mlx->win, key_hook, mlx);
}

int	main(int ac, char **av)
{
	char	**map;
	t_dimo	*dimo;
	t_comp	*mlx;

	if (ac != 2)
		error("\033[1;31mError\n\033[0mUsage: './so_long mappath/mapname.ber'\n");
	map = NULL;
	dimo = malloc (sizeof(t_dimo) * 1);
	mlx = malloc (sizeof(t_comp) * 1);
	dimo = map_dimension(av[1], dimo);
	map = read_map(av[1], dimo);
	mlx = map_errors(av[1], map, dimo, mlx);
	check_path(map, dimo, mlx);
	creat_map(map, mlx, dimo);
	creat_game(mlx, dimo, map);
	mlx_loop(mlx->init);
	return (0);
}
