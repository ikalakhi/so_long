#include "so_long.h"

void    revese_path(t_dimo *dimo, char **map, char **copy)
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