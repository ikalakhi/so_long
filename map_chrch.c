/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_chrch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalakhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:56:19 by ikalakhi          #+#    #+#             */
/*   Updated: 2022/09/25 17:06:37 by ikalakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

t_comp	*components_chrch(char *line, t_comp *comp)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'C')
			comp->collectible = comp->collectible + 1;
		else if (line[i] == 'E')
			comp->exit = comp->exit + 1;
		else if (line[i] == 'P')
			comp->player = comp->player + 1;
		i++;
	}
	return (comp);
}

char	**copy_map(char **map)
{
	int		i;
	char	**copy;

	i = -1;
	while (map[++i])
		;
	copy = malloc(sizeof(char *) * i + 1);
	i = 0;
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

t_dimo	*player_location(char **map, t_dimo *dimo)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				dimo->x = x;
				dimo->y = y;
			}
			x++;
		}
		y++;
	}
	return (dimo);
}

void	exite_location(t_dimo *dimo, char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'E')
			{
				dimo->ex = x;
				dimo->ey = y;
			}
			x++;
		}
		y++;
	}
}

void	undifined(char **map)
{
	int	i;
	int	j;

	i = 0;
	while(map[i])
	{
		j = ft_strlen(map[i]) - 2;
		while (j > 0)
		{
			if (map[i][j] != '0' && map[i][j] != '1'
				&& map[i][j] != 'E' && map[i][j] != 'C' && map[i][j] != 'P')
				error("\033[1;31mERROR\033[0m: **invalid map!\n");
			j--;
		}
		i++;
	}
}