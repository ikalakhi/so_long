/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalakhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:30:05 by ikalakhi          #+#    #+#             */
/*   Updated: 2022/09/25 16:56:11 by ikalakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

char	**read_map(char	*av, t_dimo *dimo)
{
	char	**map;
	char	*temp;
	char	*line;
	int		fd;
	int		i;

	map = malloc(sizeof (char *) * (dimo->num_lines + 1));
	fd = open(av, O_RDONLY);
	if (fd < 0)
		error("ERROR: no such file or directory\n");
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		temp = malloc(sizeof (char *) * (dimo->line_lenth + 1));
		map[i] = ft_strjoin(temp, line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	return (map);
}

t_comp	*map_errors(char *av, char **map, t_dimo *dimo, t_comp *comp)
{
	comp->collectible = 0;
	comp->player = 0;
	comp->exit = 0;
	check_extension(av);
	lines(map, dimo);
	rectangular_map(dimo);
	comp = map_components(map, comp);
	check_walls(map);
	return (comp);
}

t_comp	*map_components(char **map, t_comp *comp)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		components_chrch(map[i], comp);
		i++;
	}
	if (comp->collectible == 0)
		error("\033[1;31mERROR\033[0m:\
				there's no enough collectible\n");
	if (comp->exit < 1)
		error("\033[1;31mERROR\033[0m:\
				there's no EXIT, just like vim ;)\n");
	if (comp->player != 1)
	{
		if (comp->player == 0)
			error("\033[1;31mERROR\033[0m:\
					there's no player, how you wana play!!!\n");
		else
			error("\033[1;31mERROR\033[0m:\
					don't cheat you only need one player to win\n");
	}
	return (comp);
}
