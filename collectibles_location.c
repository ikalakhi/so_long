#include "so_long.h"

void    revese_collectibles_path(t_dimo *dimo, char **map, char **copy)
{
    if(down_c(dimo, map, copy) == 0)
        dimo->cy --;
    else if(right_c(dimo, map, copy) == 0)
        dimo->cx --;
    else if(up_c(dimo, map, copy) == 0)
        dimo->cy ++;
    else if(left_c(dimo, map, copy) == 0)
        dimo->cx ++;
}

int    down_c(t_dimo *dimo, char **map, char **copy)
{
    int y;
    int x;

    y = dimo->cy + 1;
    x = dimo->cx;
    if (map[cy][cx] != '1' && copy[cy][cx] != '*' && map[dimo->cy][dimo->cx] != '1')
    {
        copy[cy][cx] = '*';
        dimo->cy = cy;
        return (1);
    } 
    return (0);
}

int    up_c(t_dimo *dimo, char **map, char **copy)
{
    int y;
    int x;

    y = dimo->cy - 1;
    x = dimo->cx;
    if (map[cy][cx] != '1' && copy[cy][cx] != '*' && map[dimo->cy][dimo->cx] != '1')
    {
        copy[cy][cx] = '*';
        dimo->cy = cy;
        return (1);
    }
    return (0);
}

int    left_c(t_dimo *dimo, char **map, char **copy)
{
    int y;
    int x;

    y = dimo->cy;
    x = dimo->cx - 1;
    if (map[cy][cx] != '1' && copy[cy][cx] != '*' && map[dimo->cy][dimo->cx] != '1')
    {
        copy[cy][cx] = '*';
        dimo->cx = cx;
        return (1);
    }
    return (0);
}

int    right_c(t_dimo *dimo, char **map, char **copy)
{
    int y;
    int x;

    y = dimo->cy;
    x = dimo->cx + 1;
    if (map[cy][cx] != '1' && copy[cy][cx] != '*' && map[dimo->cy][dimo->cx] != '1')
    {
        copy[cy][cx] = '*';
        dimo->cx = cx;
        return (1);
    }
    return (0);
}