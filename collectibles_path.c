#include "so_long.h"

void    revese_collectibles_path(t_dimo *dimo, char **copy)
{
    if(down_c(dimo, copy) == 0)
        dimo->cy --;
    else if(right_c(dimo, copy) == 0)
        dimo->cx --;
    else if(up_c(dimo, copy) == 0 )
        dimo->cy ++;
    else if(left_c(dimo, copy) == 0)
        dimo->cx ++;
}

int    down_c(t_dimo *dimo, char **copy)
{
    int cy;
    int cx;

    cy = dimo->cy + 1;
    cx = dimo->cx;
    if (copy[cy][cx] != '1' && copy[cy][cx] != '*' && copy[dimo->cy][dimo->cx] != '1')
    {
        copy[cy][cx] = '*';
        dimo->cy = cy;
        return (1);
    } 
    return (0);
}

int    up_c(t_dimo *dimo, char **copy)
{
    int cy;
    int cx;

    cy = dimo->cy - 1;
    cx = dimo->cx;
    if (copy[cy][cx] != '1' && copy[cy][cx] != '*' && copy[dimo->cy][dimo->cx] != '1')
    {
        copy[cy][cx] = '*';
        dimo->cy = cy;
        return (1);
    }
    return (0);
}

int    left_c(t_dimo *dimo, char **copy)
{
    int cy;
    int cx;

    cy = dimo->cy;
    cx = dimo->cx - 1;
    if (copy[cy][cx] != '1' && copy[cy][cx] != '*' && copy[dimo->cy][dimo->cx] != '1')
    {
        copy[cy][cx] = '*';
        dimo->cx = cx;
        return (1);
    }
    return (0);
}

int    right_c(t_dimo *dimo, char **copy)
{
    int cy;
    int cx;

    cy = dimo->cy;
    cx = dimo->cx + 1;
    if (copy[cy][cx] != '1' && copy[cy][cx] != '*' && copy[dimo->cy][dimo->cx] != '1')
    {
        copy[cy][cx] = '*';
        dimo->cx = cx;
        return (1);
    }
    return (0);
}