/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalakhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:22:14 by ikalakhi          #+#    #+#             */
/*   Updated: 2022/09/23 14:29:33 by ikalakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	error(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write (1, &s[i], 1);
		i++;
	}
	exit(EXIT_FAILURE);
}

void	check_extension(char *av)
{
	int		i;
	int		j;
	char	*extension;

	j = 0;
	i = ft_strlen(av) - 4;
	extension = ".ber";
	while (av[i] == extension[j] && extension)
	{
		if (av[i] == '\0')
			return ;
		i++;
		j++;
	}
	if (av[i] != '\0')
		error("\033[1;31mERROR: \033[0mwrong file 'file extension should be .ber'\n");
}

void	check_walls(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(map[i]) - 2;
	while (j > 0)
	{
		if (map[i][j] != '1')
			error("\033[1;31mERROR:\033[0m you have a hole in your wall! (fixe it please)\n");
		j--;
	}
	j = ft_strlen(map[i]) - 2;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][j] != '1')
			error("\033[1;31mERROR:\033[0m you have a hole in your wall! (fixe it please)\n");
		i++;
	}
	i = i - 1;
	while (j > 0)
	{
		if (map[i][j] != '1')
			error("\033[1;31mERROR:\033[0m you have a hole in your wall! (fixe it please)\n");
		j--;
	}
}

void	lines(char **map, t_dimo *dimo)
{
	int	i;
	int	j;

	i = dimo->num_lines;
	j = ft_strlen(map[0]);
	while (i > 0)
	{
		if (j > dimo->line_lenth)
			error("\033[1;31mERROR: \033[0mdimensios are not valid\n");
		j = ft_strlen(map[i]);
		i--;
	}
}

void	rectangular_map(t_dimo *dimo)
{
	if (dimo->line_lenth < dimo->num_lines)
		error("\033[1;31mERROR: \033[0myour map must be rectangular\n");
}
