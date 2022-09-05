#include "so_long.h"

int map_strchr(char *s, char c)
{
    int     i;

    i = 0;
    while (s[i])
    {
        if (s[i] == c)
            return (1);
        i++ ;
    }
    if (s[i] == c)
        return (1);
    return (0);
}

t_comp    components_chrch(char   *line, t_comp t_com)
{
    if (map_strchr(line, 'C') == 1)
        t_com.collectible = t_com.collectible + 1;
    if (map_strchr(line, 'E') == 1)
        t_com.exit =  t_com.exit + 1;
    if (map_strchr(line, 'P') == 1)
        t_com.player = t_com.player + 1;
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

t_dimo  player_location(char **map)
{
    t_dimo  dimo;
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
                dimo.x = x;
                dimo.y = y;
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