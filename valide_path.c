#include "so_long.h"

int	visitable(t_dimo *dimo, int x, int y, char **map)
{
	if (y <= 0 || x <= 0)
		return (-1);
	if (x >= dimo->line_lenth || y >= dimo->num_lines)
		return (-1);
	if (map[y][x] == '1')
		return (-1);
	if (dimo->tab[y][x] == 1)
		return (-1);
	return (1);
}

void	visit(t_dimo *dimo, int x, int y, char **map)
{
	if (x == dimo->ex && y == dimo->ey)
	{
		dimo->inv_path = 1;
		return ;
	}
	dimo->tab[y][x] = 1;
	if (!dimo->inv_path && visitable(dimo, x + 1, y, map) != -1)
		visit(dimo, x + 1, y, map);
	if (!dimo->inv_path && visitable(dimo, x, y -1, map) != -1)
		visit(dimo, x, y -1, map);
	if (!dimo->inv_path && visitable(dimo, x - 1, y, map) != -1)
		visit(dimo, x - 1, y, map);
	if (!dimo->inv_path && visitable(dimo, x, y + 1, map) != -1)
		visit(dimo, x, y + 1, map);
	dimo->tab[y][x] = 0;
}

void	check_path(char **map, t_dimo *dimo)
{
	int i;

	i = 0;
	dimo->inv_path = 0;
	dimo->tab = (int **)malloc(sizeof(int *) * dimo->num_lines);
	while (i < dimo->num_lines)
		dimo->tab[i++] = (int *)malloc(sizeof(int) * dimo->line_lenth);
    player_location(map, dimo);
    exite_location(dimo, map);
	visit(dimo,dimo->x, dimo->y, map);
	if ( dimo->inv_path == -1)
		error("\033[1;31merror:\033[0m\ninvalid path!\n");
}