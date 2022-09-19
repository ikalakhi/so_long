#include "so_long.h"

t_comp    *components_chrch(char   *line, t_comp *comp)
{
    int i ;

    i = 0;
    while (line[i])
    {
        if (line[i] == 'C')
            comp->collectible = comp->collectible + 1;
        else if (line[i] == 'E')
            comp->exit =  comp->exit + 1;
        else if (line[i] == 'P')
            comp->player = comp->player + 1;
        i++;
    }
    return(comp);
}

char    **copy_map(char **map)
{
    int     i;
    char    **copy;

    i = -1;
    while(map[++i])
        ;

    copy = malloc(sizeof(char *) * i+1);
    i = 0;
    while(map[i])
    {
        copy[i] = ft_strdup(map[i]);
        i++;
    }
    copy[i] = NULL;
    return(copy);
}

void   player_location(char **map, t_dimo  *dimo)
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
            if (map[y][x] == 'P')
            {
                dimo->x = x;
                dimo->y = y;
            }
            x++;
        }
        y++;       
    }
}

void    exite_location(t_dimo *dimo, char **map)
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
            if (map[y][x] == 'E')
            {
                dimo->ex = x;
                dimo->ey= y;
            }
            x++;
        }
        y++;       
    }
}

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