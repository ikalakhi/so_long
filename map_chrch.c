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