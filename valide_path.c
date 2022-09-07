#include "so_long.h"

void    check_path(char **map, t_dimo  *dimo)
{
    char    **copy;
    // int a = -1;

    dimo = player_location(map, dimo);
    exite_location(dimo, map);
    copy = copy_map(map);
    while(map[dimo->y][dimo->x] != map[dimo->ey][dimo->ex] )
    {
        if(dimo->y > (dimo->num_lines - 1) || dimo->x > (dimo->line_lenth - 1))
            break ;
        if(down(dimo, map, copy));
        else if(right(dimo, map, copy));
        else if(up(dimo, map, copy));
        else if(left(dimo, map, copy));
        else
        {
            revese_path(dimo, map, copy);
            if(dimo->y == 0 || dimo->x == 0)
                error("ERROR: invalid path\n");
        }
    }
    if(copy[dimo->y][dimo->x] == map[dimo->ey][dimo->ex])
        error("ERROR: invalid path\n");
    int i = 0;
    while(copy[i])
    {
        printf("%s", copy[i]);
        i++;
    }
}

int    down(t_dimo *dimo, char **map, char **copy)
{
    int y;
    int x;

    y = dimo->y + 1;
    x = dimo->x;
    if (map[y][x] != '1' && copy[y][x] != '*')
    {
        copy[y][x] = '*';
        dimo->y = y;
        return (1);
    } 
    return (0);
}

int    up(t_dimo *dimo, char **map, char **copy)
{
    int y;
    int x;

    y = dimo->y - 1;
    x = dimo->x;
    if (map[y][x] != '1' && copy[y][x] != '*')
    {
        copy[y][x] = '*';
        dimo->y = y;
        return (1);
    }
    return (0);
}

int    left(t_dimo *dimo, char **map, char **copy)
{
    int y;
    int x;

    y = dimo->y;
    x = dimo->x - 1;
    if (map[y][x] != '1' && copy[y][x] != '*')
    {
        copy[y][x] = '*';
        dimo->x = x;
        return (1);
    }
    return (0);
}

int    right(t_dimo *dimo, char **map, char **copy)
{
    int y;
    int x;

    y = dimo->y;
    x = dimo->x + 1;
    if (map[y][x] != '1' && copy[y][x] != '*')
    {
        copy[y][x] = '*';
        dimo->x = x;
        return (1);
    }
    return (0);
}