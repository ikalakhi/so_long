/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalakhi <ikalakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:55:17 by ikalakhi          #+#    #+#             */
/*   Updated: 2022/08/24 11:56:48 by ikalakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H

# include "external_functions/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>

//struct that hold the map dimension.
typedef struct t_dimension
{
    int line_lenth;
    int num_lines;
    int x;
    int y;
    int ex;
    int ey;
} t_dimo;

//struct that holds the map's components
typedef struct t_components
{
    int     collectible;
    int     player;
    void    *init;
    int     exit;
    void    *win;
} t_comp;

void    error(char *s);
void    check_path(char **map);
void    check_walls(char **map);
void    check_extension(char *av);
void    map_components(char **map);
void    rectangular_map(t_dimo dimo);
void    lines(char  **map, t_dimo dimo);
void    creat_map(t_comp *mlx, t_dimo dimo);
void    *ft_calloc(size_t count, size_t size);
void    exite_location(t_dimo *dimo, char **map);
void    map_errors(char *av, char **map, t_dimo dimo);

char    **copy_map(char **map);
char    *join(char *s1, char *s2);
char    **help_split(char ***map);
char    **read_map(char  *av, t_dimo dimo);

int     line_lenth(char *av);
int     number_of_lines(char *av);
int     map_strchr(char *s, char c);
int    up(t_dimo *dimo, char **map, char **copy);
int    left(t_dimo *dimo, char **map, char **copy);
int    right(t_dimo *dimo, char **map, char **copy);
int    down(t_dimo *dimo, char **map, char **copy);

t_dimo  map_dimension(char  *av);
t_dimo  player_location(char **map);
t_comp  components_chrch(char *line, t_comp t_com);

# endif