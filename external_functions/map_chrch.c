#include "libft.h"

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
    // if (s[i] == c)
    //     return (1);
    return (0);
}

void    components_chrch(char   *line)
{
    if (map_strchr(line, 'C') == 0)
        error("EROOR: there's no collectible");
    if (map_strchr(line, 'E') == 0)
        error("EROOR: there's no EXIT");
    if (map_strchr(line, 'P') == 0)
        error("EROOR: there's no player");
    else
        error("EROOR: map is not valid");
}