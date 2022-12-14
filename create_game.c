/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalakhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:59:23 by ikalakhi          #+#    #+#             */
/*   Updated: 2022/09/23 17:10:47 by ikalakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	escape(t_comp *mlx)
{
	mlx_destroy_window(mlx->init, mlx->win);
	ft_printf("\n SAAFI te9adaw like?\n");
	exit(EXIT_SUCCESS);
}

void	collectibles_cont(t_comp *mlx)
{
	mlx->conter_c++;
	mlx->map[mlx->dimo->y][mlx->dimo->x] = '0';
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->b_image,
		mlx->dimo->x * 64, mlx->dimo->y * 64);
}

void	move_player(t_comp *mlx)
{
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->p_image,
		mlx->dimo->x * 64, mlx->dimo->y * 64);
}

void	navigate(t_comp *mlx, char c, int key)
{
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->b_image,
		(mlx->dimo->x * 64), (mlx->dimo->y * 64));
	if (c == 'y' && mlx->map[mlx->dimo->y + (1 * key)][mlx->dimo->x] != '1' &&
			(mlx->map[mlx->dimo->y + (1 * key)][mlx->dimo->x] != 'E' ||
		mlx->collectible == mlx->conter_c))
	{
		ft_printf("You moved %d times\n", ++mlx->dimo->c);
		mlx->dimo->y = mlx->dimo->y + (1 * key);
	}
	else if (c == 'x' && mlx->map[mlx->dimo->y][mlx->dimo->x + (1 * key)] != '1'
			&& (mlx->map[mlx->dimo->y][mlx->dimo->x + (1 * key)] != 'E'
		|| mlx->collectible == mlx->conter_c))
	{
		ft_printf("You moved %d times\n", ++mlx->dimo->c);
		mlx->dimo->x = mlx->dimo->x + (1 * key);
	}
	else if (c == 'y' && mlx->conter_c != mlx->collectible
		&& mlx->map[mlx->dimo->y + (1 * key)][mlx->dimo->x] == 'E')
		ft_printf("Please eat all the burgers before leaving\n");
	else if (c == 'y' && mlx->conter_c != mlx->collectible
		&& mlx->map[mlx->dimo->y][mlx->dimo->x + (1 * key)] == 'E')
		ft_printf("Please eat all the burgers before leaving\n");
	if (mlx->map[mlx->dimo->y][mlx->dimo->x] == 'C')
		collectibles_cont(mlx);
	move_player(mlx);
}

int	key_hook(int key_code, t_comp *mlx)
{
	if (key_code == 53)
		escape(mlx);
	else if (key_code == 13)
		navigate(mlx, 'y', -1);
	else if (key_code == 0)
		navigate(mlx, 'x', -1);
	else if (key_code == 1)
		navigate(mlx, 'y', 1);
	else if (key_code == 2)
		navigate(mlx, 'x', 1);
	if (mlx->map[mlx->dimo->y][mlx->dimo->x] == 'E')
	{
		mlx_destroy_window(mlx->init, mlx->win);
		ft_printf("\033[0;64mCongratulations you won\n");
		exit(EXIT_SUCCESS);
	}
	return (0);
}
