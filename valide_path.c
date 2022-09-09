#include "so_long.h"

void    check_path(char **map, t_dimo  *dimo, t_comp  *comp)
{
    playerspath(map, dimo);
    collectibles_path(map, dimo, comp);
}

void    playerspath(char **map, t_dimo  *dimo)
{
    char    **copy;

    dimo = player_location(map, dimo);
    dimo = exite_location(dimo, map);
    printf("\ney =>%d ex =>%d\n", dimo->ey, dimo->ex);
    copy = copy_map(map);
    while(map[dimo->y][dimo->x] != map[dimo->ey][dimo->ex] )
    {
        printf("\ny =>%d x =>%d\n", dimo->y, dimo->x);
        if(dimo->y > dimo->num_lines || dimo->x > dimo->line_lenth)
            break ;
        if(down(dimo, map, copy));
        else if(right(dimo, map, copy));
        else if(up(dimo, map, copy));
        else if(left(dimo, map, copy));
        else
        {
            revese_player_path(dimo, map, copy);
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

void    collectibles_path(char **map, t_dimo  *dimo, t_comp  *comp)
{
    char    **copy;

    copy = copy_map(map);
    dimo = player_location(map, dimo);
    while(comp->collectible > 0)
    {
        collectibles_location(copy, dimo);
        copy[dimo->cy][dimo->cx] = '*';
        printf("\ny =>%d x =>%d\n", dimo->y, dimo->x);
        printf("\ncy =>%d cx =>%d\n", dimo->cy, dimo->cx);
        while(map[dimo->y][dimo->x] != map[dimo->cy][dimo->cx] )
        {
            if(dimo->cy > dimo->num_lines || dimo->cx > dimo->line_lenth)
                break ;
            if(down_c(dimo, map, copy));
            else if(right_c(dimo, map, copy));
            else if(up_c(dimo, map, copy));
            else if(left_c(dimo, map, copy));
            else
            {
                revese_collectibles_path(dimo, map, copy);
                if(dimo->cy == 0 || dimo->cx == 0)
                    error("ERROR: invalid path\n");
            }
        }
        if(copy[dimo->cy][dimo->cx] == map[dimo->y][dimo->x])
            error("ERROR: invalid path\n");
        comp->collectible --;
    }
    int i = 0;
    printf("\n-----------colect-------------\n");
    while(copy[i])
    {
        printf("%s", copy[i]);
        i++;
    }
}