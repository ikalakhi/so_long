#include "so_long.h"

void    check_path(char **map)
{
    t_dimo  dimo;
    char    **copy;
    int a = -1;

    dimo = player_location(map);
    exite_location(&dimo, map);
    copy = copy_map(map);
    while(++a <100)
    {
        if(/*dimo.y < dimo.ey || */down(&dimo, map, copy));
        else if(/*dimo.x < dimo.ex && */right(&dimo, map, copy));
        else if(/*dimo.y > dimo.ey && */up(&dimo, map, copy));
        else if(/*dimo.x > dimo.ex && */left(&dimo, map, copy))
            ;
        // else
        //     revese_path();
    }
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