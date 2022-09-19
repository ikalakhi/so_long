#include "so_long.h"

int key_hook(int key_code, t_comp *mlx)
{
    mlx->dimo->x = 0;
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
		wining(mlx);
	return (0);
}

void    move(t_comp **mlx, char c, int key)
{
    
}