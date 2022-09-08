#include "so_long.h"

t_comp    components_chrch(char   *line, t_comp t_com)
{
    int i ;

    i = 0;
    while (line[i])
    {
        if (line[i] == 'C')
            t_com.collectible = t_com.collectible + 1;
        else if (line[i] == 'E')
            t_com.exit =  t_com.exit + 1;
        else if (line[i] == 'P')
            t_com.player = t_com.player + 1;
        i++;
    }
    return(t_com);
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

t_dimo  *player_location(char **map, t_dimo  *dimo)
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
    return(dimo);
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
            if (map[y][x] == 'P')
            {
                dimo->cx = x;
                dimo->cy = y;
            }
            x++;
        }
        y++;       
    }
    return(dimo);
}