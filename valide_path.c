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

int	can_be_path(t_dimo *dimo, int x, int y)
{
	if (y <= 0 || x <= 0)
		return (-1);
	if (x > dimo->line_lenth || y > dimo->num_lines)
		return (-1);
	if (dimo->tab[y][x] == '1')
		return (-1);
	if (dimo->tab[y][x] == 'C')
	{
		dimo->tab[y][x] = '0';
		dimo->c--;
	}
	return (1);
}

void	back_track_path(t_dimo *dimo, t_comp *comp, int x, int y, char **map)
{
	if (x == dimo->ex && y == dimo->ey && dimo->c == 0)
	{
		dimo->inv_path = 1;
		return ;
	}
	dimo->tab[y][x] = '1';
	if (!dimo->inv_path && can_be_path(dimo, x + 1, y) != -1)
		back_track_path(dimo, comp, x + 1, y, map);
	if (!dimo->inv_path && can_be_path(dimo, x, y - 1) != -1)
		back_track_path(dimo, comp, x, y -1, map);
	if (!dimo->inv_path && can_be_path(dimo, x - 1, y) != -1)
		back_track_path(dimo, comp, x - 1, y, map);
	if (!dimo->inv_path && can_be_path(dimo, x, y + 1) != -1)
		back_track_path(dimo, comp, x, y + 1, map);
}

void	check_path(char **map, t_dimo *dimo, t_comp *comp)
{
	int	i;

	i = 0;
	dimo->inv_path = 0;
	dimo->c = comp->collectible;
	dimo->tab = copy_map(map);
	player_location(map, dimo);
	exite_location(dimo, map);
	back_track_path(dimo, comp, dimo->x, dimo->y, map);
	if (dimo->inv_path == 1 || dimo->c == 0)
		return ;
	else
		error("\033[1;31merror:\033[0m\ninvalid path!\n");
}
