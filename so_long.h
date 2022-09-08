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
    int ex ;
    int ey;
    int cx ;
    int cy;
    int x;
    int y;
} t_dimo;

// struct that holds the map's components.
typedef struct t_components
{
    int     collectible;
    int     player;
    int     exit;
    void    *init;
    void    *win;
} t_comp;

void    error(char *s);
void    check_walls(char **map);
void    check_extension(char *av);
void    map_components(char **map);
void    rectangular_map(t_dimo dimo);
void    lines(char  **map, t_dimo dimo);
void    creat_map(t_comp *mlx, t_dimo dimo);
void    check_path(char **map, t_dimo  *dimo);
void    *ft_calloc(size_t count, size_t size);
void    playerspath(char **map, t_dimo  *dimo);
void    exite_location(t_dimo *dimo, char **map);
void    map_errors(char *av, char **map, t_dimo dimo);
void    revese_player_path(t_dimo *dimo, char **map, char **copy);
void    collectibles_path(char **map, t_dimo  *dimo, t_comp comp);
void    revese_collectibles_path(t_dimo *dimo, char **map, char **copy);

char    **copy_map(char **map);
char    **help_split(char ***map);
char    *join(char *s1, char *s2);
char    **read_map(char  *av, t_dimo dimo);

int     line_lenth(char *av);
int     number_of_lines(char *av);
int     map_strchr(char *s, char c);
int     up(t_dimo *dimo, char **map, char **copy);
int     down(t_dimo *dimo, char **map, char **copy);
int     left(t_dimo *dimo, char **map, char **copy);
int     right(t_dimo *dimo, char **map, char **copy);
int     up_c(t_dimo *dimo, char **map, char **copy);
int     down_c(t_dimo *dimo, char **map, char **copy);
int     left_c(t_dimo *dimo, char **map, char **copy);
int     right_c(t_dimo *dimo, char **map, char **copy);

t_dimo  map_dimension(char  *av);
t_comp  components_chrch(char *line, t_comp t_com);
t_dimo  *player_location(char **map, t_dimo  *dimo);

# endif