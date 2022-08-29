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
    char    **map = NULL;
    t_dimo  dimo;

    if (ac != 2)
        error("Error\nUsage: './so_long mappath/mapname.ber'\n");
    dimo = map_dimension(av[1]);
    map = read_map(av[1], dimo);
    map_errors(av[1], map, dimo);
    int i = 0;
    while (map[i])
    {
        printf("%s\n", map[i]);
        i++;
    }
    return (0);
}