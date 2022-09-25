/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valide_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalakhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:48:51 by ikalakhi          #+#    #+#             */
/*   Updated: 2022/09/25 16:50:33 by ikalakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	can_be_path(t_dimo *dimo, int x, int y, char **map)
{
	if (y <= 0 || x <= 0)
		return (-1);
	if (x >= dimo->line_lenth || y >= dimo->num_lines)
		return (-1);
	if (map[y][x] == '1')
		return (-1);
	if (dimo->tab[y][x] == 1)
		return (-1);
	return (1);
}

void	track_path(t_dimo *dimo, int x, int y, char **map)
{
	if (x == dimo->ex && y == dimo->ey)
	{
		dimo->inv_path = 1;
		return ;
	}
	dimo->tab[y][x] = 1;
	if (!dimo->inv_path && can_be_path(dimo, x + 1, y, map) != -1)
		track_path(dimo, x + 1, y, map);
	if (!dimo->inv_path && can_be_path(dimo, x, y -1, map) != -1)
		track_path(dimo, x, y -1, map);
	if (!dimo->inv_path && can_be_path(dimo, x - 1, y, map) != -1)
		track_path(dimo, x - 1, y, map);
	if (!dimo->inv_path && can_be_path(dimo, x, y + 1, map) != -1)
		track_path(dimo, x, y + 1, map);
}

void	check_path(char **map, t_dimo *dimo)
{
	int	i;

	i = 0;
	dimo->inv_path = 0;
	dimo->tab = (int **)malloc(sizeof(int *) * dimo->num_lines);
	while (i < dimo->num_lines)
		dimo->tab[i++] = (int *)malloc(sizeof(int) * dimo->line_lenth);
	player_location(map, dimo);
	exite_location(dimo, map);
	track_path(dimo, dimo->x, dimo->y, map);
	if (dimo->inv_path)
		return ;
	error("\033[1;31merror:\033[0m\ninvalid path!\n");
}
