/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalakhi <ikalakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:55:04 by ikalakhi          #+#    #+#             */
/*   Updated: 2022/09/23 15:21:20 by ikalakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*tab;
	size_t	i;

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
