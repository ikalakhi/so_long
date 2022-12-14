/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalakhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:47:33 by ikalakhi          #+#    #+#             */
/*   Updated: 2022/08/24 11:47:34 by ikalakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*help_join(char *save, char *s1, char *s2)
{
	size_t	i;
	size_t	p;

	if (!save)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	if (s1 && s1[0] != '\0')
	{
		while (s1[i] != '\0')
		{
			save[i] = s1[i];
			i++;
		}
	}
	p = 0;
	while (s2 && s2[p] != '\0')
		save[i++] = s2[p++];
	save[i++] = '\0';
	return (save);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*save;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	save = malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	save = help_join(save, s1, s2);
	free(s1);
	return (save);
}

int	ft_strchr(char *s, int c)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}
