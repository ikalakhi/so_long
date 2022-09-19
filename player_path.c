#include "so_long.h"

void    revese_player_path(t_dimo *dimo, char **copy)
{
    int x;
    int y;

    x = dimo->x;
    y = dimo->y;
    if(down(dimo, copy) == 0)
        dimo->y --;
    else if(right(dimo, copy) == 0)
        dimo->x --;
    else if(up(dimo, copy) == 0)
        dimo->y ++;
    else if(left(dimo, copy) == 0)
        dimo->x ++;
}

int down(t_dimo *dimo, char **copy)
{
    int y;
    int x;

    y = dimo->y + 1;
    x = dimo->x;
    if (copy[y][x] != '1' && copy[y][x] != '*' && copy[dimo->y][dimo->x] != '1')
    {
        copy[y][x] = '*';
        dimo->y = y;
        return (1);
    } 
    return (0);
}

int up(t_dimo *dimo, char **copy)
{
    int y;
    int x;

    y = dimo->y - 1;
    x = dimo->x;
    if (copy[y][x] != '1' && copy[y][x] != '*' && copy[dimo->y][dimo->x] != '1')
    {
        copy[y][x] = '*';
        dimo->y = y;
        return (1);
    }
    return (0);
}

int left(t_dimo *dimo, char **copy)
{
    int y;
    int x;

    y = dimo->y;
    x = dimo->x - 1;
    if (copy[y][x] != '1' && copy[y][x] != '*' && copy[dimo->y][dimo->x] != '1')
    {
        copy[y][x] = '*';
        dimo->x = x;
        return (1);
    }
    return (0);
}

int right(t_dimo *dimo, char **copy)
{
    int y;
    int x;

    y = dimo->y;
    x = dimo->x + 1;
    if (copy[y][x] != '1' && copy[y][x] != '*' && copy[dimo->y][dimo->x] != '1')
    {
        copy[y][x] = '*';
        dimo->x = x;
        return (1);
    }
    return (0);
}