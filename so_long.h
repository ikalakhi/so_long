/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalakhi <ikalakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:55:17 by ikalakhi          #+#    #+#             */
/*   Updated: 2022/09/23 15:19:37 by ikalakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct t_dimension
{
	int	line_lenth;
	int	wrong_path;
	int	num_lines;
	int	inv_path;
	char	**tab;
	char	**tab2;
	int	visited;
	int	ex;
	int	ey;
	int	cx;
	int	cy;
	int	c;
	int	x;
	int	y;
	int	exit;
}	t_dimo;

typedef struct t_components
{
	int		collectible;
	int		conter_c;
	int		player;
	int		zero;
	int		exit;
	void	*win;
	void	*init;
	char	**map;
	void	*b_image;
	void	*p_image;
	void	*c_image;
	void	*e_image;
	void	*w_image;
	t_dimo	*dimo;
}	t_comp;

void	error(char *s);
void	free_map(int **tab);
void	undifined(char **map);
void	check_walls(char **map);
void	images_path(t_comp *mlx);
void	check_extension(char *av);
void	rectangular_map(t_dimo *dimo);
void	lines(char **map, t_dimo *dimo);
void	fill_window(char **map, t_comp *path);
void	push_backgroud(char **map, t_comp *mlx);
void	exite_location(t_dimo *dimo, char **map);
void	creat_map(char **map, t_comp *mlx, t_dimo *dimo);
void	creat_game(t_comp *mlx, t_dimo *dimo, char **map);
void	check_path(char **map, t_dimo *dimo, t_comp *comp);
void	revese_collectibles_path(t_dimo *dimo, char **copy);
void	back_track_path(t_dimo *dimo, t_comp *comp, int x, int y, char **map);

char	**copy_map(char **map);
char	**help_split(char ***map);
char	*join(char *s1, char *s2);
char	**read_map(char *av, t_dimo *dimo);

int		escape(t_comp *mlx);
int		line_lenth(char *av);
int		number_of_lines(char *av);
int		map_strchr(char *s, char c);
int		key_hook(int key_code, t_comp *mlx);
int		can_be_path(t_dimo *dimo, int x, int y);

t_dimo	*map_dimension(char *av, t_dimo *dimo);
t_comp	*map_components(char **map, t_comp *comp);
t_dimo	*player_location(char **map, t_dimo *dimo);
t_comp	*components_chrch(char *line, t_comp *comp);
t_comp	*map_errors(char *av, char **map, t_dimo *dimo, t_comp *comp);

#endif
