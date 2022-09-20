#include "so_long.h"


void	collectibles_cont(t_comp *mlx)
{
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->b_image,\
		mlx->dimo->x * 64,mlx->dimo->y * 64);
	mlx->conter_c++;
}

void	move_player(t_comp *mlx)
{
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->p_image,\
		mlx->dimo->x * 64,mlx->dimo->y * 64);
}

void    move(t_comp *mlx, char c, int key)
{
	int	cont;

	cont = 0;
	printf("y == %d, x == %d\n", mlx->dimo->y, mlx->dimo->x);
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->b_image,\
		 (mlx->dimo->x * 64), (mlx->dimo->y * 64));
    if (c == 'y' && mlx->map[mlx->dimo->y  + (1 * key)][mlx->dimo->x] != '1' &&\
		 mlx->map[mlx->dimo->y + (1 * key)][mlx->dimo->x] != 'E')
	{
		printf("y == %d, x == %d\n", mlx->dimo->y, mlx->dimo->x);
		printf("you moved %d times\n", ++cont);
		mlx->dimo->y = mlx->dimo->y + (1 * key);
	}
	else if (c == 'x' && mlx->map[mlx->dimo->y][mlx->dimo->x  + (1 * key)] != '1' &&\
		 mlx->map[mlx->dimo->y][mlx->dimo->x  + (1 * key)] != 'E')
	{
		printf("y == %d, x == %d\n", mlx->dimo->y, mlx->dimo->x);
		printf("you moved %d times\n", ++cont);
		mlx->dimo->x = mlx->dimo->x + (1 * key);
	}
	else if (c == 'y' && mlx->conter_c != mlx->collectible &&\
		 mlx->map[mlx->dimo->y + (1 * key)][mlx->dimo->x] == 'E')
	{
		printf("Please eat all burgers befor leaving\n");
	}
	else if (c == 'y' && mlx->conter_c != mlx->collectible &&\
		 mlx->map[mlx->dimo->y][mlx->dimo->x  + (1 * key)] == 'E')
	{
		printf("Please eat all burgers befor leaving\n");
	}
	if (mlx->map[mlx->dimo->y][mlx->dimo->x] == 'C')
		collectibles_cont(mlx);
	move_player(mlx);
}

int key_hook(int key_code, t_comp *mlx)
{
	printf("heeeer=%d\n", key_code);
    // mlx->dimo->x = 0;
	if (key_code == ESC)
		escape(mlx);
	else if (key_code == W)
		move(mlx, 'y', -1);
	else if (key_code == A)
		move(mlx, 'x', -1);
	else if (key_code == S)
		move(mlx, 'y', 1);
	else if (key_code == D)
		move(mlx, 'x', 1);
	if (mlx->map[mlx->dimo->y][ mlx->dimo->x] == 'E')
		printf("Congratulations you won\n");
	return (0);
}