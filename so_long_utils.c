/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalakhi <ikalakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:55:04 by ikalakhi          #+#    #+#             */
/*   Updated: 2022/08/24 11:56:14 by ikalakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void    error(char *s)
{
    int     i;

    i = 0;
    while (s[i] != '\0')
    {
        write (1, &s[i], 1);
        i++;
    }
    exit(EXIT_FAILURE);
}

void    *ft_calloc(size_t count, size_t size)
{
    char    *tab;
    size_t  i;

    i = 0;
    tab = malloc(count * size);
    if (tab == (NULL))
        return (NULL);
    while (size > 0)
    {
        tab[i] = '\0';
        size--;
        i++;
    }
    return (tab);
}