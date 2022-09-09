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

int main (int ac, char **av)
{
    char    **map;
    t_dimo  dimo;
    t_comp  *mlx;

    if (ac != 2)
        error("Error\nUsage: './so_long mappath/mapname.ber'\n");
    map = NULL;
    mlx =  malloc(sizeof(t_comp) * 1);
    dimo = map_dimension(av[1]);
    map = read_map(av[1], dimo);
    mlx = map_errors(av[1], map, dimo, mlx);
    check_path(map, &dimo, mlx);
    int i = 0;
    printf("\n------------------map---------------\n");
    while(map[i])
    {
        printf("%s", map[i]);
        i++;
    }
    // mlx->init = mlx_init();
    // mlx->win = mlx_new_window(mlx->init,  1920, 1080, "so_long");
   // creat_map(mlx, dimo);
    // mlx_loop(mlx->init);
    return (0);
}