#include "so_long.h"

void    revese_player_path(t_dimo *dimo, char **map, char **copy)
{
    if(down(dimo, map, copy) == 0)
        dimo->y --;
    else if(right(dimo, map, copy) == 0)
        dimo->x --;
    else if(up(dimo, map, copy) == 0)
        dimo->y ++;
    else if(left(dimo, map, copy) == 0)
        dimo->x ++;
}

int    down(t_dimo *dimo, char **map, char **copy)
{
    int y;
    int x;

    y = dimo->y + 1;
    x = dimo->x;
    if (map[y][x] != '1' && copy[y][x] != '*' && map[dimo->y][dimo->x] != '1')
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
    if (map[y][x] != '1' && copy[y][x] != '*' && map[dimo->y][dimo->x] != '1')
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
    if (map[y][x] != '1' && copy[y][x] != '*' && map[dimo->y][dimo->x] != '1')
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
    if (map[y][x] != '1' && copy[y][x] != '*' && map[dimo->y][dimo->x] != '1')
    {
        copy[y][x] = '*';
        dimo->x = x;
        return (1);
    }
    return (0);
}