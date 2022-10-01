#include "so_long.h"

t_dimo  *collectibles_location(char **map, t_dimo  *dimo)
{
    int     x;
    int     y;

    x = 0;
    y = 0;
    while(map[y])
    {
        x = 0;
        while(map[y][x])
        {
            if (map[y][x] == 'C')
            {
                dimo->cx = x;
                dimo->cy = y;
                return(dimo);
            }
            x++;
        }
        y++;       
    }
    return(dimo);
}

int	can_be_path_c(char **map, t_dimo *dimo, int cx, int cy)
{
	if (cy <= 0 || cx <= 0)
		return (-1);
	if (cx >= dimo->line_lenth || cy >= dimo->num_lines)
		return (-1);
	if (map[cy][cx] == '1')
		return (-1);
	if (dimo->tab[cy][cx] == 1)
		return (-1);
	return (1);
}

void	back_track_path_c(t_dimo *dimo, int cx, int cy, char **map)
{
	if (cx == dimo->x && cy == dimo->y)
	{
		dimo->wrong_path = 1;
		return ;
	}
	dimo->tab[cy][cx] = 1;
	if (!dimo->wrong_path && can_be_path_c(map, dimo, cx + 1, cy) != -1)
		back_track_path_c(dimo, cx + 1, cy, map);
	if (!dimo->wrong_path && can_be_path_c(map, dimo, cx, cy -1) != -1)
		back_track_path_c(dimo, cx, cy -1, map);
	if (!dimo->wrong_path && can_be_path_c(map, dimo, cx - 1, cy) != -1)
		back_track_path_c(dimo, cx - 1, cy, map);
	if (!dimo->wrong_path && can_be_path_c(map, dimo, cx, cy + 1) != -1)
		back_track_path_c(dimo, cx, cy + 1, map);
}

void    collectibles_path(t_dimo *dimo,t_comp *comp, char **map)
{
    int cx;
    int cy;

    cx = 0;
    cy = 0;
    dimo->wrong_path = 0;
    while (comp->collectible > 0)
    {
        dimo = collectibles_location(map, dimo);
        cx = dimo->cx;
        cy = dimo->cy;
        back_track_path_c(dimo, cx, cy, map);
        comp->collectible--;
    }
}